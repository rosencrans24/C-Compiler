/*   Abstract syntax tree code

   This code is used to define an AST node, 
   routine for printing out the AST
   defining an enumerated type so we can figure out what we need to
   do with this.  The ENUM is basically going to be every non-terminal
   and terminal in our language.

   Shaun Cooper February 2015

   This file contains the abstract syntax tree code that prints out 
   the values checked by the yacc file that is a syntax checker 
   Joshua Rosencrans
   March 28, 2018

   Added a new function to AST that makes sure the two variables being used are of the same types
   Joshua Rosencrans
   April 11, 2018

*/

#include <stdio.h>
#include <malloc.h>
#include "ast.h"
static int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

/* uses malloc to create an ASTnode and passes back the heap address of the newly created node */
ASTnode *ASTCreateNode(enum ASTtype mytype)
{
   ASTnode *p;
   if (mydebug) fprintf(stderr,"Creating AST Node \n");
   p=(ASTnode *)malloc(sizeof(ASTnode));
   p->type=mytype;
   p->right=NULL;
   p->left=NULL;
   p->next=NULL;
   p->s1=NULL;
   p->s2=NULL;
   p->value=0;
   p->symbol=NULL;   // added the value of symbol and initilized it to null
   return(p);
}

/* attach q to the left most part of p */
void ASTattachnext(ASTnode *p,ASTnode *q)
{

}

ASTnode *program;


/* added function to check the type of operator since it wil be used 
   in multiple cases */
void typeCheck(enum OPERATORS barf){
   if(barf == VOIDDEC)
      printf("VOID ");
   else if(barf == INTDEC)
      printf("INT ");
   else{
      printf("type unspecified ");
   }
}
/* This is a new method created to do some type checking if the types of the operators do not match 
each other this will help throw an error */
int check(ASTnode *p, ASTnode *q){
  if( p == NULL && q == NULL)
    return 1;
  else if(p == NULL || q == NULL)
    return 0;
  else if (p->operator != q->operator )
    return 0;
  check (p->next , q->next);
}

/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p)
{
   int i;
   if (p == NULL ) return;
   else
   { 
   for (i=0;i<level;i++) printf(" "); /* print tabbing blanks */
      
      switch (p->type) {
         case VARDEC : printf("Variable ");
                       typeCheck(p->operator);
                       printf("%s",p->name);
                       if (p->value > 0)
                          printf("[%d]",p->value);
                       printf("\n");
                       break;
         case FUNDEC : typeCheck(p->operator);
                       printf("Function ");
                       printf("%s",p->name);
                       printf("\n");
                       level ++;
                     break;
         case PARAM: printf("Parameter ");
                       typeCheck(p->operator);
                       printf("%s",p->name);
                       if (p->value > 0)
                          printf("[%d]",p->value);
                       printf("\n");
                       break;
        case BLOCK: printf("BLOCK");
                    ASTprint( level + 1, p->right );
                    ASTprint( level + 1, p->left );
                    break;

      default: printf("unknown type in ASTprint\n");


      }
      ASTprint(level, p->next);
   }

}



/* dummy main program so I can compile for syntax error independently  
main()
{
}
/* */
