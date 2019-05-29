all:lab9

lab9:y.tab.c lex.yy.c ast.c symtable.c emitter.c
	gcc y.tab.c lex.yy.c ast.c symtable.c emitter.c -o lab9
lex.yy.c: lab6.l
	lex lab6.l
y.tab.c: lab6.y ast.c
	yacc -d lab6.y
ast.c: ast.c ast.h
	gcc -c ast.c ast.h
symtable.c: symtable.c symtable.h
	gcc -c symtable.c symtable.h
emitter.c: emitter.c emitter.h
	gcc -c emitter.c emitter.h