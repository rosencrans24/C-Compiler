/*  
      Emitter.c
      This program takes the ast tree and translates it into NASM code
      Joshua Rosencrans
      May 4, 2018

*/
#include "emitter.h"

extern int mydebug;
int LTEMP =0;           // global label counter 

void Emit(FILE * f, ASTnode * p){                     // driver program that prints the setup for NASM
      emit(f,"%include \"io64.inc\"\n","","");        // part of required setup
      emit_global(f,p);                               // prints out all the global variables that exist 
      emit(f,"section .data\n","","");                // prints the header for the data section
      emit_string(f,p);                               // prints out the strings in the code with the label
      emit(f,"section .text","","");                  // prints out the .text section
      emit(f,"","global main\n","");                  // prints the global section called main
      EmitAST(f,p);                                   // starts the emitsAST program which is where the code is generated 
}

void emit(FILE * f,char * label,char * command,char * comment){   // function that writes the NASM code to a file
      char s[100];                                                      
      fprintf(f, "%s \t %s \t %s \n",label,command,comment);
}

void emit_global(FILE * f, ASTnode * p){                          // emits the NASM code for global variables
      if(p == NULL)                                               // check to see if there are any global variables
         return;
      char s[100];
      if(p->type == VARDEC){                                      // go to vardec in ast becasue thats where the declarations will be 
         sprintf(s,"common %s %d", p->name,p->value*WORDSIZE);    // load the variable and size into a string
         emit(f,"",s,"; define a global variable");               // emit the string to be at the top of the NASM code
      }                                                           // will only find global variables because it stays at level 0 only checking next
      emit_global(f,p->next);                                     // check to see if there are any more variable declarations at the global level
}
void emit_string(FILE * f, ASTnode * p){                          // function to emit when a string is found
      if(p==NULL)                                                 // make sure there is a string 
         return;
      char s[100];
      if(p->type == OUT)                                          // check to see if the type is a write statemnt
            if(p->name != NULL){                                  // continue as long as a string to print exist 
                  p->value = LTEMP;                               // puts the value in the global temp for the label number
                  char * temporary = CreateLab();                 // creates the label with the value 
                  sprintf(s,"db%s, 0",p->name);                   
                  emit(f,temporary,s,"; global string");          // prints out the label at the top as a global string
            }
            emit_string(f,p->next);                               // big hammer approach check everywhere to see if 
            emit_string(f,p->right);                              // strings exist
            emit_string(f,p->left); 
            emit_string(f,p->s1);
            emit_string(f,p->s2);    
}
void emit_function(FILE * f, ASTnode * p){                        // function header for emitting functions
      char s[100];                                                // char array created to build strings
      sprintf(s,"%s:",p->name);                                   // get the name of the function
      emit(f,s,"","; Start of a function");                       // print out that this is where a function begins
      if(strcmp(p->name,"main")==0){                              // special case when the function is main
            emit(f,"","mov rbp,rsp",";special RSP to RBP for MAIN only");     // when in main the stack pointer and base pointer  
      }                                                                       // need to start at the same location 
      emit(f,"","mov r8,rsp",";FUNC header RSP is at most RBP");              // use r8 as a temp register to store stack pointer
      sprintf(s,"add r8,%d",(p->value)* WORDSIZE * -1);                       // find the offset and store in r8
      emit(f,"",s,"; adjust the stack pointer");                              // adjust the stack pointer
      emit(f,"","mov [r8],rbp",";store old BP");                              //store the old the base pointer before offset                            
      emit(f,"","mov [r8+8],rsp","; store old SP");                           // store old stack pointer before offset
      emit(f,"","mov rsp,r8",";func header new SP");                          // move the stack pointer to the beginning of your function
      fprintf(f,"\n");
      EmitAST(f,p->right);                                                    // start traversing throught the emiter
      fprintf(f,"\n");
      emit(f,"","mov rbp,[rsp]",";Restore old BP");                           // restore the old base pointer 
      emit(f,"","mov rsp,[rsp + 8]",";Restore old SP");                       // restore the old stack pointer
      if(strcmp(p->name,"main")==0)                                           // special case for main must restore the old stack and base pointer
            emit(f,"","mov rsp,rbp",";Special RSP and RBP restore for main");
      emit(f,"","ret","");                                                    // end the assembly code
}
void emit_ident(FILE * f, ASTnode * p){
      char s[100];
      if(p->symbol->IsAFunc == 2){              // check to see if the identifier is an array reference 
            switch(p->right->type){             // if it is find out what type it is
                  case NUMBER:                  // if its a number just shove that value into rbx
                        sprintf(s,"mov rbx, %d", p->right->value);      
                        emit(f,"",s,"; RBX is a number");
                        break;
                  case EXPR:                        // if it is an expression shove the value of the expression into rbx
                        emit_expression(f,p->right);
                        sprintf(s,"mov rbx, [rbx + %d]",p->right->symbol->offset * WORDSIZE);
                        emit(f,"",s,";stores expresion value in rbx");
                        break;
                  case IDENT:                       //if it is an identfier shove the value int rbx
                        emit_ident(f,p->right);
                        emit(f,"","mov rbx, [rax]",";store ident value in rbx");
                        break;
            } 
            sprintf(s,"shl rbx, %d",LOGICALSIZE); /* shift over 3 place in order to not mess with rax*/
            emit(f,"",s,";multiply RBX by 3");    
      }
      if(p->symbol->level == 0){                  // if identifer level equals zero then it is a global variable
            sprintf(s,"mov rax, %s",p->name);
            emit(f,"",s,";load rax with location");
      }
      else{                                       // other wise it is is a local variable
            sprintf(s,"mov rax, %d",(p->symbol->offset) *WORDSIZE);
            emit(f,"",s,";Load RAX with location");
            sprintf(s,"add rax,rsp");
            emit(f,"",s,"; add RAX and RSP");
      }
      if(p->symbol->IsAFunc == 2){
            emit(f,"","add rax,rbx",";adds RBX to RAX"); /* adds rbx to rax to ensure the right offset*/
      }
}
void emit_expression(FILE * f,ASTnode *p) {     // function header for expression evaluate the left side then the right side and combine at end
      char s[100];

      switch (p->left->type){                   // first evaluate the left hand side of the exrpression
            case NUMBER:                        // if LHS is a number just shove that value into rax
                  sprintf(s,"mov rax, %d",p->left->value);
                  emit(f,"",s,"; LHS expression is  a number");
                  break;
            case IDENT:                        // if the LHS is an identfer calls emit ident then stores the value from rax in memory location rax
                  emit_ident(f,p->left);
                  emit(f,"","mov rax, [rax]", ";LHS expression is an identifier");
                  break;
            case CALL:
                  break;
            case EXPR:                        // if LHS is an expression goes as deep as it need to in the tree to find either an ident or a num
                  emit_expression(f,p->left);
                  sprintf(s,"mov rax, [rsp + %d]",(p->left->symbol->offset) * WORDSIZE);  // stores the value of the expression in rax
                  emit(f,"",s,"; LHS is expression");
                  break;      
      }
      sprintf(s,"mov [rsp + %d], rax",(p->symbol->offset) * WORDSIZE);  // gets the value of LHS and stores that in memory
      emit(f,"",s,";store LHS of expression in memory");

      switch(p->right->type){                                           // now needs to take care of the right hand side
            case NUMBER:                                                // if RHS is a number shove that value in RBX
                  sprintf(s,"mov rbx, %d", p->right->value);
                  emit(f,"",s,"; RHS expression is  a number");
                  break;
            case IDENT:                                                 // if RHS is a ident evalute the ident then put value into RBX
                  emit_ident(f,p->right);
                  emit(f,"","mov rbx, [rax]", ";RHS expression is an identifier");
                  break;
            case CALL:
                  break;
            case EXPR:                                                  // if RHS is a expression evaluate the expression until you get to 
                  emit_expression(f,p->right);                          // a number or ident node then store value in rbx
                  sprintf(s,"mov rbx, [rsp + %d]",(p->right->symbol->offset) * WORDSIZE);
                  emit(f,"",s,"; RHS is expression");
                  break;
      }
      sprintf(s,"mov rax, [rsp + %d]",(p->symbol->offset)* WORDSIZE);   // makes sure you have both left and right hand side before cheking 
      emit(f,"",s,";fetch LHS of expression from memory");              // which operater is between them

      switch(p->operator){                                              // now that you have LHS in rax and RHS in rbx you can check which 
            case PLUS:                                                  // operator is being used
                  emit(f,"","add rax,rbx",";EXPR ADD");                 // if operator is add then adds rax and rbx
                  break;
            case MINUS:
                  emit(f,"","sub rax,rbx",";EXPR SUB");                 // if operator is subtract then subtracts rax and rbx
                  break;
            case TIMES:
                  emit(f,"","imul rax, rbx",";EXPR MULT");              // if operator is times then multiplies rax and rbx
                  break;
            case DIV:                                                   // if operator is div then divides rax and rbx
                  emit(f,"","xor rdx,rdx",";EXPR DIV");                 // ors rdx to ensure that the value is 0
                  emit(f,"","idiv rbx",";EXPR DIV");
                  break; 
            case MOD:
                  emit(f,"","xor rdx,rdx",";EXPR DIV");                 
                  emit(f,"","idiv rbx",";EXPR DIV");
                  emit(f,"","rax,rdx",";Stores the remainder of division in rax");
                  break;      
            case EQUAL:                                                 // if operator is equal compares the values 
                  emit(f,"","cmp rax, rbx",";EXPR Equal");              // then sets al to equals
                  emit(f,"","sete al",";EXPR Equal");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;
            case NOTEQ:                                                 // if operator is not equal compares the values 
                  emit(f,"","cmp rax, rbx",";EXPR Not Equal");          // then sets al to not equals
                  emit(f,"","setne al",";EXPR Not Equal");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;
                  
            case LESSTHAN:                                              // if operator is less than compares the values
                  emit(f,"","cmp rax, rbx",";EXPR Less Than");          // then sets al to less than
                  emit(f,"","setl al",";EXPR Less Than ");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;
            case LESSTHANEQ:                                            // if operator is less than equal then compare the values
                  emit(f,"","cmp rax, rbx",";EXPR Less than equal");    // then sets al to less than or equal
                  emit(f,"","setle al",";EXPR less than equal");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;
            case GREATERTHAN:                                           // if operator is greater than compare the values
                  emit(f,"","cmp rax, rbx",";EXPR Greater than");       // then sets al to greater than 
                  emit(f,"","setg al",";EXPR Greater than");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;;
            case GREATERTHANEQ:                                               // if operator is greater than or equal then compare the values
                  emit(f,"","cmp rax, rbx",";EXPR Greater than or Equal");    //and set al to greater than or equal
                  emit(f,"","setge al",";EXPR Less than or Equal");
                  emit(f,"","mov rbx,1",";set rbx to one to filter rax");
                  emit(f,"","and rax,rbx",";filter RAX");
                  break;    
      }
      sprintf(s,"mov [rsp+%d],rax",(p->symbol->offset )* WORDSIZE);     // store the value of rax into the memory location plus offset
      emit(f,"",s,";store RHS of expression in memory");
}
void emit_expressionStmt(FILE * f, ASTnode *p){                         // function header for expresion statement which is only used
 char s[100];                                                           // if node is an assignment statement since only RHS will be an expresion
 if(mydebug)
      printf("HERE\n");
 switch (p->type){                                                      // checks the type of the RHS
            case NUMBER:                                                // if number shoves the value into rax
                  if(mydebug)
                        printf("HERE\n");
                  sprintf(s,"mov rax, %d",p->value);
                  emit(f,"",s,"; RHS expression is  a number");
                  break;
            case IDENT:                                                 // if its an idnet calls emit ident to get value then puts that 
                  if(mydebug)
                        printf("HERE\n");                                     // into rax
                  emit_ident(f,p);
                  if(mydebug)
                        printf("HERE\n");
                  emit(f,"","mov rax, [rax]", ";RHS expression is an identifier");
                  break;
            case CALL:
                  break;
            case EXPR:                                                  // if it is a expresion calls emit expression and puts value in rax
                 if(mydebug)
                        printf("HERE\n");
                  emit_expression(f,p);
                  sprintf(s,"mov rax, [rsp + %d]",(p->symbol->offset) * WORDSIZE);
                  emit(f,"",s,"; RHS is an expression");
                  break;
      }
      sprintf(s,"mov [rsp + %d], rax",(p->symbol->offset) * WORDSIZE);  // stores rax into the memory location plus the offset
      emit(f,"",s,";store RHS of expression in memory");
}

char * CreateLab(){                                                     // function that creates the labels with value of global temp
      char hold[100];
      char *s;
      sprintf(hold,"_L%d",LTEMP++);
      s=strdup(hold);
      return (s);
}


void EmitAST(FILE * f,ASTnode *p)         // funtion that handles the printing for all the node types
{
   int i;
   char s[100];                           // char array to create strings to print
   char *t;                               // create char pointers to be used in if and while for tarets
   char *t2;
   if (p == NULL ) return;                // if there s no program quit
   else{ 
       switch (p->type) {                 // else see which node type you are on and continue 
         
         case VARDEC :  
            break;
         
         case FUNDEC :                    // calls emit funtction if the type is a function mine only does the main function
            emit_function(f,p); 
            break;
        
         case PARAMS  : 
            break;
         
         case PARAM :  
            break;
         
         case BLOCK :                     // if the type is a compound statement goes back thorugh with the left side of the statement
            EmitAST(f,p->left);
            break;
        
         case READSTMT :                  // first goes to the right hand side then once in a read, reads the value 
            EmitAST(f,p->right);
            emit(f,"","GET_DEC 8,[rax]",";Read an integer");
            break;
         
         case ASSIGNSTMT  :                     // if type is an assignment statement
            emit_expressionStmt(f,p->right);    // first calls expression statement to evalueate the RHS for the assignment    
            emit_ident(f,p->left);              // emits the LHS identifier
            sprintf(s,"mov rbx, [rsp + %d]",(p->right->symbol->offset)*WORDSIZE);   // loads the RHS calculated into RBX
            emit(f,"",s,";Load RHS into RBX");                    
            emit(f,"","mov [rax],rbx",";Store RHS");        // stores the RHS into rax
            break;
         case OUT  :                                  // case for the write statement 
            if(p->name == NULL){                      // checks to see if a string
                  switch(p->right->type){                   
                        case NUMBER:                  // if type is a number just shoves the value into rsi to be printed
                              sprintf(s,"mov rsi,%d",p->right->value);
                              emit(f,"",s,";Load RSI");
                              break;
                        case IDENT:                   // if write is a ident it goes throught the right of the tree to take care of the ident 
                              EmitAST(f,p->right);
                              emit(f,"","mov rsi,[rax]",";Load RSI");
                              break;
                        case EXPR:                    // if write is a expression goes to right of tree to evaluate the expression
                              EmitAST(f,p->right);
                              sprintf(s,"mov rsi,[rsp + %d]",(p->right->symbol->offset)* WORDSIZE);
                              emit(f,"",s,";write and expression");
                              break;
                  }           
            }
            else{                                           // if name is not null then a string exist
                  sprintf(s,"PRINT_STRING _L%d",p->value);  // use print string on the value
                  emit(f,"",s,";Print a string");
                  emit(f,"","NEWLINE", ";print a newline ");
                  break;
            }
            emit(f,"","PRINT_DEC 8,rsi",";Print");          // always going to print out what value was found from the first if
            emit(f,"","NEWLINE",";Newline");
            break;
         case IFSTMT :                                // case that handles the if statements 
            switch(p->left->type){                    // must see what is being passed as the arguement in the if statement 
                  case NUMBER:                        // if type is a number put the value in rax
                        sprintf(s,"mov rax, %d",p->left->value);
                        emit(f,"",s,";Type is a number");
                        break;
                  case EXPR:                          // if type is a expression evaluate the expression and store that value in rax
                        emit_expression(f,p->left);
                        sprintf(s,"mov rax, [rsp + %d]",p->left->symbol->offset * WORDSIZE);
                        emit(f,"",s,";load rax if expression");
                        break;
                  case IDENT:                         // if type is an ident take care of that first then store value in rax
                        emit_ident(f,p->left);
                        sprintf(s,"mov rax, [rax]");
                        emit(f,"",s,";load rax with value");
                        break;
            }
            t=CreateLab();                                  // create the jump to labels
            t2=CreateLab();                                 // create the jump to labels
            emit(f,"","CMP rax,0",";compare to end IF");    // compare the value stored in rax to 0 to see where to jump to 
            sprintf(s,"JE %s",t);                           // if value equals false then you will do the else part
            emit(f,"",s,";JUMP else");
            EmitAST(f,p->s1);                               // otherwise you are going to do the if part
            sprintf(s,"JMP %s",t2);
            emit(f,"",s,";jump to end");                    // when done jumpp out and continue with next part of code
            sprintf(s,"%s:",t);
            emit(f,s,"",";label for the else part");
            EmitAST(f,p->s2);
            sprintf(s,"%s:",t2);
            emit(f,s,"",";final label");
            break;
         case ITERSTMT :                        // case taking care of the while statement
            switch(p->left->type){              // same as before check what the condition statemtn is 
                  case NUMBER:                  // if number put value in rax
                        sprintf(s,"mov rax, %d",p->left->value);
                        emit(f,"",s,"; expression is  a number");
                        break;
                  case EXPR:                    // if  an expression evalueate the expression then store value in rax
                        emit_expression(f,p->left);
                        sprintf(s,"mov rax, [rsp + %d]",p->left->symbol->offset * WORDSIZE);
                        emit(f,"",s,";load rax if expression");
                        break;
                  case IDENT:                   // if identifier evaluate the identifier then store the value in rax                        
                        emit_ident(f,p->left);
                        sprintf(s,"mov rax, [rax]");
                        emit(f,"",s,";load rax with value");
                        break;
            }
            if(mydebug)
                  printf("HERE\n");
            t= CreateLab();                     // create the labels to jump to 
            t2= CreateLab();                    // create the label to jump to 
            if(mydebug)
                  printf("HERE\n");
            sprintf(s,"%s:",t);                 // create the top target to start the loop agin 
            emit(f,s,"",";WHILE top target");
            if(mydebug)
                  printf("HERE\n");                                   
            emit(f,"","CMP rax,0",";compare to end while");   // compare the value with zero to see if you can jump out or continue
            if(mydebug)
                  printf("HERE\n");
            sprintf(s,"JE %s",t2);              // if compare is true then jump out 
            emit(f,"",s,";JUMP out");
            EmitAST(f,p->right);
            sprintf(s,"JMP %s",t);
            emit(f,"",s,";JUMP to top");        // if compare was false continue with the loop
            sprintf(s,"%s:",t2);
            emit(f,s,"",";While bottom target");
            break;
         case CALL :
            break; 
         case IDENT :   // if is identifier calls emit identifier
            emit_ident(f,p);
            break; 
         case NUMBER :
            break; 
         case EXPR:     // if it is a expression calls emit expression
            emit_expression(f,p);
            break;

      }
      EmitAST(f,p->next);     // goes to the next node to get all the way through the tree
   }
}



/* dummy main program so I can compile for syntax error independently  
main()
{
}
/* */
