/*  
      Emitter.h
      This file holds all the function prototypes for the emitter.c class 
      Joshua Rosencrans
      May 4, 2018

*/

#ifndef EMITTER_H
#define EMITTER_H

#define WORDSIZE 8
#define LOGICALSIZE 3

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "symtable.h"
#include "ast.h"

void Emit(FILE * f, ASTnode * p);
void emit(FILE * f,char * label,char * command,char * comment);
void emit_global(FILE * f, ASTnode * p);
void emit_string(FILE * f, ASTnode * p);
void EmitAST(FILE * f,ASTnode *p);
void emit_function(FILE * f, ASTnode * p);
void emit_ident(FILE * f, ASTnode * p);
void emit_expression(FILE * f,ASTnode *p);
void emit_espressionStmt(FILE * f, ASTnode *p);
char * CreateLab();


#endif