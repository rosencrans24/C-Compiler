	/*         
	   This is a small lex program that produces the tokens to be sent to the yacc file making sure to inclde all of the reserved words and 
		assignment operators you would encounter in a c minus program. This program is a syntax checker.
		Joshua Rosencrans
		February 23, 2018

		changes added
   	Joshua Rosencrans
  		March 28, 2018
   */
	
%{

int mydebug= 1;
int lineno = 1;                                // variable defined to count the number of new lines
#include "ast.h"
#include "y.tab.h"

%}


%%
int         {return (INT);}      // added all these cases so reserved words would be passed to yacc as tokens
void        {return (VOID);}
while       {return (WHILE);}
if          {return (IF);}
else        {return (ELSE);}
read        {return (READ);}
write       {return (WRITE);}
return      {return (RETURN);}
"<="        {return (LE);}       // added these cases to return the comparison statemetns as tokens
">="        {return (GE);}
"=="        {return (EQ);}
"!="        {return (NE);}
[a-zA-Z][a-zA-Z0-9]*		{yylval.string = strdup(yytext); return(ID);}          // added this case for variable declarations
[0-9][0-9]*	{yylval.value=atoi((const char *)yytext); return(NUM);}
[ \t]		{if (mydebug); }                                      // throws away white space
[()=\-+*/%&|;<>\[\]\{\},] 	{return (*yytext);}  //added semicolon comma square bracktes and curly brackets so they could be recognized
\n 		{ lineno++;}                            // added lineno so the line numbers were counted
\".*\"   {yylval.string = strdup(yytext);return(STR);}
%%

int yywrap(void)
{ return 1;}


