%{
      /*         
	   This yacc program is the driver program for our syntax checker, it recieves the tokens from lex and using the grammer rules defined 
         in the yacc can go through and find the line in which something is not syntacticly correct
         Joshua Rosencrans
	   February 23, 2018

         Semantic action added in order for the syntax to be put into an
         abstract syntax tree  
         Joshua Rosencrans
         March 28, 2018

         Added actions along with the semantic action to intruduce the symbol table in various locations. The sybmol table helps 
         insure that there are no duplicate declarations and helps make sure that declarations can be made as long as they are 
         at different levels    
         Joshua Rosencrans
         April 11, 2018
         
         Added some action to help with the nasm generation
         Joshua Rosencrans
         May 4, 2018
      */






#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "symtable.h"
#include "ast.h"
#include "emitter.h"


extern int mydebug;
extern int lineno;
int goffset = 0;              /* global offset */
int offset = 0;               /* offset to be used within the production rules */
int level = 0;
int maxoffset =0;
char * filename;
FILE *fp;                /* insures that you are declaring variables on the correct level  */
extern ASTnode * program;

int base, debugsw;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line %d\n", s,lineno);        /* Added lineno to count which line error is on */ 
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start p

%union {
	int value;
	char * string;
	ASTnode * node;
	enum OPERATORS operator;
}
  /* tokens to be expected from lex */
%token <value> INT 
%token <value> NUM   
%token LE GE EQ NE VOID WHILE IF ELSE READ WRITE RETURN
%token <string> ID
%token <string> STR

/* declaring all the productions as nodes in the AST tree */
%type <node> declarationlist
%type <node> declaration
%type <node> vardeclaration
%type <node> fundeclaration
%type <node> params paramlist param
%type <node> compoundstmt
%type <node> localdeclarations
%type <node> statementlist
%type <node> statement
%type <node> expressionstmt selectionstmt iterationstmt expression
%type <node> assignmentstmt returnstmt readstmt writestmt var
%type <node> simpleexpression additiveexpression
%type <node> factor term call args arglist
%type <operator> typespecifier
%type <operator> relop
%type <operator> addop
%type <operator> multop


%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

p : declarationlist  {program = $1;}                     /* The main beginning of a grammer is the program which moves to a declarion list */
        ;

declarationlist : declaration {$$ = $1;}                 /* all definitons in this file are going to be right recursive */ 
                | declaration declarationlist {$1 -> next = $2; $$ = $1;}
                                                  
                ;

declaration : vardeclaration {$$ = $1;}                   /* A declaration can either be a variable or a function */
            | fundeclaration {$$ = $1;}
            ;

vardeclaration : typespecifier ID ';'    {struct SymbTab *p;
                                          if(Search ($2, level, 0) == 0 )        /* checks to make sure the variable hasnt been declared already */
                                                {$$=ASTCreateNode(VARDEC);       /* creates an AST node for a variable declaration */
                                                $$->operator = $1;
                                                $$->symbol = Insert($2, $1, 0, level, 1, offset,NULL);  /* inserts the variable in symbol table */
                                                $$->name=$2;
                                                $$->value=1;                                            /* and makes symbol point to that location */
                                                offset += 1;}                                           /* increments offset to the next locations */
                                          else  {
                                                yyerror("symbol already used");                  /* throws an error if declaration is already used */
                                                exit(0);
                                                }
                                          }                 /* A variable declaration can either be the type like int followed by an identifier */
               | typespecifier ID '['NUM']' ';' { struct SymbTab *p;
                                                  if(Search($2,level,0) == 0) {     /* checks to make sure the variable hasnt been declared already */
                                                      $$=ASTCreateNode(VARDEC);
                                                      $$->name = $2;
                                                      $$->isType = $1;              /* sets is type to the type specified for type checking */
                                                      $$->operator = $1;
                                                      $$->value = $4;
                                                      $$->symbol = Insert($2,$1,2,level,$4,offset,NULL); /* inserts the variable in symbol table */
                                                      offset += $4;                                      /*sets offset equal to the array size */
                                                      /*printf("found an array declaration\n"); */
                                                  }
                                                  else {
                                                      yyerror($2);
                                                      yyerror("symbol already used");     /* throws an error if declaration is already used */
                                                      $$ = NULL;      
                                                      }
                                                 }  /* Or it can be a type folowed by and identifier follewed by the number associated */
               ;

typespecifier : INT {$$ = INTDEC;}                            /* The only types it accepts is either int or void */
              | VOID {$$ = VOIDDEC;}
              ;

fundeclaration : typespecifier ID '('     { if (Search($2,level,0) == 0){           /* checks to make sure the variable hasnt been declared already */
                                                Insert($2,$1,1,level,0,0,NULL);     /* inserts the variable in symbol table */
                                                goffset = offset;                   /* sets goffset equal to offset so you can retrun to it */
                                                offset = 2;
                                                maxoffset=offset;
                                          }
                                          else {
                                                yyerror("symbol already used");     /* throws an error if declaration is already used */
                                                exit(0);
                                               }
                                          } 

                        params {(Search ($2,0,0)) -> fparms = $5;}
                        
                         ')' compoundstmt            {$$=ASTCreateNode(FUNDEC);
                                                      $$->name = $2;
                                                      $$->left = $5;
                                                      $$->operator = $1;
                                                      $$->isType = $1;        /* sets is type to the type specified for type checking */
                                                      $$->right = $8;
                                                      $$->symbol=Search($2,0,0);
                                                      offset = goffset;
                                                      $$ ->value = maxoffset;
                                                      }
                                                                /* A function is made up of a type the identifier and also the parameters */ 
               ;                                                /* Also followed next by the curly brackets */

params : VOID {$$ = ASTCreateNode(PARAMS);
               $$->operator= VOIDDEC;}                                             /* A parameter could be void no paramters or have a list of parameters */
       | paramlist      { $$ = ASTCreateNode(PARAMS);
                          $$ -> left = $1;}
       ;

paramlist : param    {$$ = $1;}                                   /* A param list is one parameter followed by a comma then the next parameter */
          | param ',' paramlist  {$$ = $1; $$->next=$3;}
          ;

param : typespecifier ID   {
                              if (Search ($2,level+1,0) == NULL)  /* checks to make sure the variable hasnt been declared already */
                            {
                            $$=ASTCreateNode(PARAM);
                            $$->operator = $1;
                            $$->isType = $1;                      /* sets is type to the type specified for type checking */
                            $$->name=$2;
                            $$->symbol = Insert($2,$1,0,level+1,1,offset,NULL);  /* inserts the variable in symbol table */
                            $$->value = 0;
                            offset += 1;
                            }    
                            else{
                              yyerror("symbol already used");     /* throws an error if declaration is already used */
                              exit(0);
                                } 
                            }                                /* A paramter is made up of a type and an identifier maybe followed by a number */
      | typespecifier ID '[' ']' {
                                 if(Search($2,level+1,0) == NULL)       /* checks to make sure the variable hasnt been declared already */
                                 {
                                  $$=ASTCreateNode(PARAM);
                                  $$->name = $2;
                                  $$->operator = $1;
                                  $$->isType = $1;                      /* sets is type to the type specified for type checking */
                                  $$->symbol = Insert($2,$1,2,level+1,1,offset,NULL);  /* inserts the variable in symbol table */
                                  $$->value=-1;
                                  offset +=1;
                                  }
                                  else {
                                      yyerror("symbol already used");   /* throws an error if declaration is already used */
                                      exit(0);   
                                       }
                                }
      ;

compoundstmt :  '{' {level++;} 
                localdeclarations 
                statementlist 
                '}'   
                                          {$$ = ASTCreateNode(BLOCK);
                                          if ($3==NULL)
                                                $$ -> left=$4;
                                          else {
                                                $$ -> left = $4;
                                                $$ -> right = $3;            
                                                }
                                          if(mydebug)
                                                Display(); 
                                          if(offset > maxoffset)
                                                maxoffset = offset;                   /* prints out what exist inside the compund statemnt */
                                          offset -=Delete(level);       /* deletes the current level from the table and decrements offset */
                                          level --;                  
                                          }      /* A compound statemnt is made up of curly braces then the declaraions and list */
             ;                                                 /* or statements */

localdeclarations : /* empty */   {$$ = NULL;}                             /* This local declaration can be empty or have a variable followed by a local */
                  | vardeclaration localdeclarations {$1 -> next = $2;
                                                      $$ = $1;}          /* variable */
                  ;

statementlist : /* empty */   {$$ = NULL;}                        /* A statement list is either empty or a statemnt followed by more staetments   */ 
              | statement statementlist  {$$ = $1; $$->next=$2;}                      /* right recursive */
              ;

statement : expressionstmt    {$$ = $1;}                                /* A statemnt could be any of these possibilites  */
          | compoundstmt      {$$ = $1;}       
          | selectionstmt     {$$ = $1;}     
          | iterationstmt     {$$ = $1;}
          | assignmentstmt    {$$ = $1;}
          | returnstmt        {$$ = $1;}
          | readstmt          {$$ = $1;}
          | writestmt         {$$ = $1;}
          ;

expressionstmt : expression ';'     {$$ = $1;
                                     $$ ->name = CreateTemp();
                                     $$->symbol = Insert($$->name,$$->isType,0,level,1,offset,NULL);
                                     offset++;}                           /* an expression statement is an expression followed by a semi colon  */
               | ';'                {$$ = NULL;}                           /* Or can exist as just the semi colon */
               ;

assignmentstmt : var '=' expressionstmt   {$$ = ASTCreateNode(ASSIGNSTMT);
                                           $$ -> right =  $3;
                                           $$ -> operator = EQUAL;
                                           $$ -> left = $1;}                        /* An assignment statement is a variable equals some expression */
               ;

selectionstmt : IF '(' expression ')' statement                {$$ = ASTCreateNode(IFSTMT);
                                                                $$ -> left = $3;
                                                                $$ -> s1 = $5;}      /* Selection statement is an if statement with the correct format */
              | IF '(' expression ')' statement ELSE statement {$$ = ASTCreateNode(IFSTMT);
                                                                $$ -> left = $3;
                                                                $$ -> s1 = $5;
                                                                $$ -> s2 = $7;}
              ;

iterationstmt : WHILE '(' expression ')' statement     {$$ = ASTCreateNode(ITERSTMT);
                                                       $$ -> right = $5;
                                                       $$ -> left = $3;}        /* an iteration statement is just a typical formated while loop */
              ;

returnstmt : RETURN ';'             {$$ = ASTCreateNode(RETURNSTMT);}                           /* this is for a return statemnt which is followed by a semicolon */
           | RETURN expression ';'  {$$ = ASTCreateNode(RETURNSTMT);
                                    $$ -> right = $2;} 
           ;

readstmt : READ var ';'          {$$ = ASTCreateNode(READSTMT);
                                 $$ -> right = $2;}                               /* read statement is a read reserved word followed by a variable then semi colon */
         ;

writestmt : WRITE expression ';'   {$$ = ASTCreateNode(OUT);
                                   $$ -> right = $2;}                            /* write statement is a write reserved word followed by a variable then semi colon */
          | WRITE STR ';'           {$$ = ASTCreateNode(OUT);
                                     $$ ->name = $2;}
          ;

expression : simpleexpression      {$$ = $1;}                           /* an expression is just a simple expression which boild down to a term */
           ;

var : ID                           {if(Search($1,level,1) == NULL){     /* checks to make sure the variable hasnt been declared already */
                                        yyerror($1);
                                        yyerror("variable not defined");
                                        exit (1);
                                    }
                                   $$ = ASTCreateNode(IDENT);
                                   $$ -> name = $1;
                                   $$ -> symbol = Search($1,level,1);
                                   $$->isType = Search($1,level,1)->Type;}                           /* a variable is just an identifier or a identifier followed by expression */
    | ID '[' expression ']'        {if(Search($1,level,1) == NULL){
                                        yyerror($1);
                                        yyerror("variable not defined");
                                        exit (1);
                                          }
                                    $$ = ASTCreateNode(IDENT);
                                    $$ -> right = $3; 
                                    $$ -> name = $1;
                                    $$->isType = Search($1,level,1)->Type;
                                    $$->symbol = Search($1,level,1); }   /* sets is type to the type specified for type checking */
    ;

simpleexpression : additiveexpression           {$$ = $1;}                    /* A simpleexpressoin is an expression of terms */
                 | additiveexpression relop simpleexpression {$$ = ASTCreateNode(EXPR);
                                                              $$->left = $1;
                                                              $$->right = $3;
                                                              $$-> operator = $2;
                                                              $$ ->name = CreateTemp();
                                                              $$->symbol = Insert($$->name,$$->isType,0,level,1,offset,NULL);
                                                              offset++;}
                 ;

relop : '<'       {$$ = LESSTHAN;}                                               /* These are the comparison operators */
      | '>'       {$$ = GREATERTHAN;}        
      | LE        {$$ = LESSTHANEQ;}    
      | GE        {$$ = GREATERTHANEQ;}    
      | EQ        {$$ = EQUAL;}    
      | NE        {$$ = NOTEQ;}   
      ;

additiveexpression : term                            { $$ = $1; }
                   |additiveexpression addop term   { if($1->isType != $3->isType)  /* checking for correct types*/
                                                      {
                                                          yyerror("additiv expression type mismatch");
                                                          exit(1);
                                                      }      
                         
                                                      $$ = ASTCreateNode( EXPR );
                                                      $$->left = $1;
                                                      $$->right = $3;
                                                      $$->operator = $2;
                                                      $$->isType = $1->isType;          /* sets is type to the type specified for type checking */
                                                      $$->name = CreateTemp();      /* creates a temp variable with the specified name*/
                                                      $$->symbol = Insert($$->name,INTDEC,0,level,1,offset,NULL);  /* inserts the variable in symbol table */
                                                      offset ++;}

addop : '+'   {$$ = PLUS;}                                           /* addop is just either the plus or minus operator */           
      | '-'   {$$ = MINUS;} 
      ;

term : factor  {$$ = $1;}                                                /* term is a factor multiplying another factor */
     | factor multop term { if($1->isType != $3->isType)    /* Making sure the terms are of same type otherwise throw error */
                              {
                                    yyerror("Term type mismatch");
                                    exit(1);
                              }      
                         
                              $$ = ASTCreateNode( EXPR );
                              $$->left = $1;
                              $$->right = $3;
                              $$->operator = $2;
                              $$->isType = $1->isType;                /* sets is type to the type specified for type checking */
                              $$->name = CreateTemp();            /* creates a temp variable with the specified name*/
                              $$->symbol = Insert($$->name,INTDEC,0,level,1,offset,NULL);  /* inserts the variable in symbol table */
                              offset ++;}
     ;

multop : '*'      {$$ = TIMES;}                                                   /* a multop is just the multiply or divide operator  */
       | '/'      {$$ = DIV;} 
       | '%'      {$$ = MOD;}
       ;

factor : '(' expression ')'   {$$ = $2;}                                   /* a factor is an expression or can be any of the others number variable or call */
       | NUM                  {$$ = ASTCreateNode(NUMBER);
                               $$ -> value = $1; $$->isType = INTDEC;} 
       | var                  {$$ = $1;} 
       | call                 {$$ = $1;} 
       ;

call : ID '(' args ')'        {if( check(Search($1,level,1)->fparms,$3)==0){  /* checks to make sure the variable hasnt been declared already */
                                    yyerror($1);                              /* throws an error if declaration is already used */
                                    yyerror("function not defined");
                                    exit (1);
                              }
                              if(Search($1,level,1)->IsAFunc != 1){     /* checks to make sure the variable hasnt been declared already */
                                    yyerror($1);                        /* throws an error if declaration is already used */
                                    yyerror("function not defined");
                                    exit (1);
                              }
                               $$ = ASTCreateNode(CALL);
                               $$ -> name = $1;
                               $$->isType = Search($1,level,1)->Type;
                               $$ -> right = $3;}                                  /* a call is an identifier followed by an argument  */
     ;

args : /* empty */     {$$ = NULL;}                                                 /* list of arguemtns  */
     | arglist         {$$ = $1;}
     ;

arglist : expression              {$$ = $1;}               /* an argument list is an expression by itself or and expression followed by more expressions */
        | expression ',' arglist  {$$ = $1;
                                   $$ -> next = $3;}  
        ;

%% 
main(int argv, char * argc[])

{ 
  char a[100];                            /* create array to hold filename */
  mydebug =0;
      int i;                              /*iterator for the for statement */
      for (i=0; i < argv;i++){            /*go thourgh to find the parts of the string you need for the file */
            if(strcmp(argc[i],"-d")==0)   /*check if the debug flag is set */
                  mydebug =1;
            if(strcmp(argc[i], "-o")==0)  /*check input for the -o flag */
                  filename = argc[i+1];
      
  
  }
  sprintf(a,"%s.asm",filename);           /* take the filename and append .asm onto the end*/
  fp = fopen(a, "w");                     /* open the file and write to it*/
  if(fp == NULL){fprintf(stderr, "cannot open file %s\n",filename);exit(1);}  /* throw error if the file could not be opened*/
  yyparse();
  fprintf(stderr,"Main symbol table START\n");
  /* ASTprint(0,program);  /* this is where we can do things with the AST like print it or process it */
  Display();               /* call the sybmol table display function to see what was stored */
  fprintf(stderr,"Main symbol table END\n");
  Emit(fp,program);
  fclose(fp);              /* close */
  exit(0);
}
