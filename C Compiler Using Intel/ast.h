/* 
   Header file for the Abstarct Syntax Tree 
   Joshua Rosencrans
   March 28, 2018

   Added a new struct symbol to see where you are in the symbol table and also added
   a new enumerator istype to ensure correct type being used
   Joshua Rosencrans
   April 11, 2018
*/

#ifndef AST_H
#define AST_H

enum ASTtype{
   PROGRAM,
   VARDEC,
   INTTYPE,
   IDENT,
   FUNDEC,
   PARAM,
   PARAMS,
   BLOCK,
   NUMBER,
   EXPRSTMT,
   ASSIGNSTMT,
   IFSTMT,
   ITERSTMT,
   RETURNSTMT,
   READSTMT,
   OUT,
   CALL,
   EXPR,
   
};
enum OPERATORS{
   PLUS,
   MINUS,
   TIMES,
   INTDEC,
   VOIDDEC,
   DIV,
   MOD,
   EQUAL,
   NOTEQ,
   LESSTHAN,
   LESSTHANEQ,
   GREATERTHAN,
   GREATERTHANEQ,

};
typedef struct ASTnodetype
{
     enum ASTtype type;
     enum OPERATORS operator;
     enum OPERATORS isType;   /* created to check which type the operator being used is */
     char * name;
     int value;
     struct ASTnodetype *next,*right,*left; /* left is usually the connector for statements */
     struct ASTnodetype *s1,*s2 ; /* used for holding IF and WHILE components -- not very descriptive */
     struct SymbTab *symbol;   /* created to have a pointer to where you are in the symbol table */ 
} ASTnode;
ASTnode *ASTCreateNode(enum ASTtype );
void ASTattachleft(ASTnode *p,ASTnode *q);
void ASTprint(int level,ASTnode *p);
int check(ASTnode *p, ASTnode *q);


#endif 
