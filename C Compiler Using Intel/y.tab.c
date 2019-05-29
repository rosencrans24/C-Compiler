/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "lab6.y" /* yacc.c:339  */

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



#line 124 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT = 258,
    NUM = 259,
    LE = 260,
    GE = 261,
    EQ = 262,
    NE = 263,
    VOID = 264,
    WHILE = 265,
    IF = 266,
    ELSE = 267,
    READ = 268,
    WRITE = 269,
    RETURN = 270,
    ID = 271,
    STR = 272,
    UMINUS = 273
  };
#endif
/* Tokens.  */
#define INT 258
#define NUM 259
#define LE 260
#define GE 261
#define EQ 262
#define NE 263
#define VOID 264
#define WHILE 265
#define IF 266
#define ELSE 267
#define READ 268
#define WRITE 269
#define RETURN 270
#define ID 271
#define STR 272
#define UMINUS 273

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 62 "lab6.y" /* yacc.c:355  */

	int value;
	char * string;
	ASTnode * node;
	enum OPERATORS operator;

#line 207 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 222 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   127

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  73
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   273

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,    24,    19,     2,
      29,    30,    22,    20,    31,    21,     2,    23,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    26,
      35,    34,    36,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    27,     2,    28,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    32,    18,    33,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    25
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   104,   104,   107,   108,   112,   113,   116,   129,   148,
     149,   152,   164,   152,   179,   181,   185,   186,   189,   205,
     223,   223,   243,   244,   248,   249,   252,   253,   254,   255,
     256,   257,   258,   259,   262,   266,   269,   275,   278,   284,
     289,   290,   294,   298,   300,   304,   307,   316,   328,   329,
     338,   339,   340,   341,   342,   343,   346,   347,   362,   363,
     366,   367,   383,   384,   385,   388,   389,   391,   392,   395,
     411,   412,   415,   416
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "NUM", "LE", "GE", "EQ", "NE",
  "VOID", "WHILE", "IF", "ELSE", "READ", "WRITE", "RETURN", "ID", "STR",
  "'|'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "UMINUS", "';'", "'['",
  "']'", "'('", "')'", "','", "'{'", "'}'", "'='", "'<'", "'>'", "$accept",
  "p", "declarationlist", "declaration", "vardeclaration", "typespecifier",
  "fundeclaration", "$@1", "$@2", "params", "paramlist", "param",
  "compoundstmt", "$@3", "localdeclarations", "statementlist", "statement",
  "expressionstmt", "assignmentstmt", "selectionstmt", "iterationstmt",
  "returnstmt", "readstmt", "writestmt", "expression", "var",
  "simpleexpression", "relop", "additiveexpression", "addop", "term",
  "multop", "factor", "call", "args", "arglist", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   124,    38,
      43,    45,    42,    47,    37,   273,    59,    91,    93,    40,
      41,    44,   123,   125,    61,    60,    62
};
# endif

#define YYPACT_NINF -90

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-90)))

#define YYTABLE_NINF -15

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      48,   -90,   -90,    30,   -90,    48,   -90,    21,   -90,   -90,
     -90,    -9,   -90,    52,   -90,    26,    50,    51,    46,    62,
     -90,   -90,    31,   -90,    53,    49,    48,    55,    54,   -90,
     -90,   -90,   -90,    48,    48,    65,    32,   -90,     8,   -90,
      56,    58,    68,    -1,    23,   -20,   -90,    15,   -90,    57,
      32,   -90,   -90,   -90,   -90,   -90,   -90,   -90,    63,    59,
     -90,     5,   -90,    44,   -90,    15,    15,    61,    66,    69,
      70,   -90,   -90,    71,    15,    15,    64,   -90,   -90,   -90,
      34,   -90,   -90,   -90,   -90,   -90,   -90,   -90,   -90,    15,
      15,   -90,   -90,   -90,    15,    72,    73,   -90,   -90,   -90,
     -90,    76,    60,    75,   -90,   -90,   -90,   -90,   -90,   -90,
      32,    32,   -90,    15,   -90,   -90,    86,   -90,    32,   -90
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     9,    10,     0,     2,     3,     5,     0,     6,     1,
       4,     0,     7,     0,    11,     0,     0,     0,    10,     0,
      12,    15,    16,     8,    18,     0,     0,     0,     0,    17,
      19,    20,    13,    22,    22,     0,    24,    23,     0,    66,
       0,     0,     0,     0,     0,    46,    35,     0,    27,     0,
      24,    26,    30,    28,    29,    31,    32,    33,     0,    67,
      45,    48,    56,    60,    68,     0,     0,    46,     0,     0,
       0,    67,    40,     0,     0,    70,     0,    21,    25,    34,
       0,    52,    53,    54,    55,    58,    59,    50,    51,     0,
       0,    62,    63,    64,     0,     0,     0,    42,    44,    43,
      41,     0,    72,     0,    71,    65,    36,    49,    57,    61,
       0,     0,    47,     0,    69,    39,    37,    73,     0,    38
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -90,   -90,    94,   -90,    36,    39,   -90,   -90,   -90,   -90,
      74,   -90,    78,   -90,    67,    77,   -89,    27,   -90,   -90,
     -90,   -90,   -90,   -90,   -42,   -36,    19,   -90,   -90,   -90,
     -86,   -90,   -90,   -90,   -90,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,     8,    16,    25,    20,
      21,    22,    48,    33,    36,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    71,    60,    89,    61,    90,
      62,    94,    63,    64,   103,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      59,    70,    73,    39,   108,    76,    68,    74,   109,    75,
      81,    82,    83,    84,    59,    45,    69,    12,    13,    39,
      14,   115,   116,    95,    96,    85,    86,    39,    47,   119,
       9,    45,   101,   102,    12,    13,    39,    11,    39,    45,
      87,    88,    40,    41,    47,    42,    43,    44,    45,    72,
      45,     1,    47,     1,    17,    19,    15,     2,    46,    18,
      46,    47,    26,    47,    31,    19,    91,    92,    93,    34,
      34,   102,    35,    35,    59,    59,   -14,    23,    24,    28,
      27,    38,    59,    30,    67,    65,    31,    66,    74,    79,
      77,   113,    97,    80,   105,    98,    99,   100,   118,    10,
      29,    37,   110,   111,   112,   114,    32,   106,   107,   117,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78
};

static const yytype_int8 yycheck[] =
{
      36,    43,    44,     4,    90,    47,    42,    27,    94,    29,
       5,     6,     7,     8,    50,    16,    17,    26,    27,     4,
      29,   110,   111,    65,    66,    20,    21,     4,    29,   118,
       0,    16,    74,    75,    26,    27,     4,    16,     4,    16,
      35,    36,    10,    11,    29,    13,    14,    15,    16,    26,
      16,     3,    29,     3,    28,    16,     4,     9,    26,     9,
      26,    29,    31,    29,    32,    26,    22,    23,    24,    33,
      34,   113,    33,    34,   110,   111,    30,    26,    16,    30,
      27,    16,   118,    28,    16,    29,    32,    29,    27,    26,
      33,    31,    26,    34,    30,    26,    26,    26,    12,     5,
      26,    34,    30,    30,    28,    30,    28,    80,    89,   113,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    50
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     9,    38,    39,    40,    41,    42,    43,     0,
      39,    16,    26,    27,    29,     4,    44,    28,     9,    42,
      46,    47,    48,    26,    16,    45,    31,    27,    30,    47,
      28,    32,    49,    50,    41,    42,    51,    51,    16,     4,
      10,    11,    13,    14,    15,    16,    26,    29,    49,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    65,    67,    69,    70,    29,    29,    16,    62,    17,
      61,    62,    26,    61,    27,    29,    61,    33,    52,    26,
      34,     5,     6,     7,     8,    20,    21,    35,    36,    64,
      66,    22,    23,    24,    68,    61,    61,    26,    26,    26,
      26,    61,    61,    71,    72,    30,    54,    63,    67,    67,
      30,    30,    28,    31,    30,    53,    53,    72,    12,    53
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    40,    40,    41,    41,    42,
      42,    44,    45,    43,    46,    46,    47,    47,    48,    48,
      50,    49,    51,    51,    52,    52,    53,    53,    53,    53,
      53,    53,    53,    53,    54,    54,    55,    56,    56,    57,
      58,    58,    59,    60,    60,    61,    62,    62,    63,    63,
      64,    64,    64,    64,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    69,    69,    70,
      71,    71,    72,    72
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     6,     1,
       1,     0,     0,     8,     1,     1,     1,     3,     2,     4,
       0,     5,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     5,     7,     5,
       2,     3,     3,     3,     3,     1,     1,     4,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     4,
       0,     1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 104 "lab6.y" /* yacc.c:1646  */
    {program = (yyvsp[0].node);}
#line 1385 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 107 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1391 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 108 "lab6.y" /* yacc.c:1646  */
    {(yyvsp[-1].node) -> next = (yyvsp[0].node); (yyval.node) = (yyvsp[-1].node);}
#line 1397 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 112 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1403 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 113 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1409 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 116 "lab6.y" /* yacc.c:1646  */
    {struct SymbTab *p;
                                          if(Search ((yyvsp[-1].string), level, 0) == 0 )        /* checks to make sure the variable hasnt been declared already */
                                                {(yyval.node)=ASTCreateNode(VARDEC);       /* creates an AST node for a variable declaration */
                                                (yyval.node)->operator = (yyvsp[-2].operator);
                                                (yyval.node)->symbol = Insert((yyvsp[-1].string), (yyvsp[-2].operator), 0, level, 1, offset,NULL);  /* inserts the variable in symbol table */
                                                (yyval.node)->name=(yyvsp[-1].string);
                                                (yyval.node)->value=1;                                            /* and makes symbol point to that location */
                                                offset += 1;}                                           /* increments offset to the next locations */
                                          else  {
                                                yyerror("symbol already used");                  /* throws an error if declaration is already used */
                                                exit(0);
                                                }
                                          }
#line 1427 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 129 "lab6.y" /* yacc.c:1646  */
    { struct SymbTab *p;
                                                  if(Search((yyvsp[-4].string),level,0) == 0) {     /* checks to make sure the variable hasnt been declared already */
                                                      (yyval.node)=ASTCreateNode(VARDEC);
                                                      (yyval.node)->name = (yyvsp[-4].string);
                                                      (yyval.node)->isType = (yyvsp[-5].operator);              /* sets is type to the type specified for type checking */
                                                      (yyval.node)->operator = (yyvsp[-5].operator);
                                                      (yyval.node)->value = (yyvsp[-2].value);
                                                      (yyval.node)->symbol = Insert((yyvsp[-4].string),(yyvsp[-5].operator),2,level,(yyvsp[-2].value),offset,NULL); /* inserts the variable in symbol table */
                                                      offset += (yyvsp[-2].value);                                      /*sets offset equal to the array size */
                                                      /*printf("found an array declaration\n"); */
                                                  }
                                                  else {
                                                      yyerror((yyvsp[-4].string));
                                                      yyerror("symbol already used");     /* throws an error if declaration is already used */
                                                      (yyval.node) = NULL;      
                                                      }
                                                 }
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 148 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = INTDEC;}
#line 1455 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 149 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = VOIDDEC;}
#line 1461 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 152 "lab6.y" /* yacc.c:1646  */
    { if (Search((yyvsp[-1].string),level,0) == 0){           /* checks to make sure the variable hasnt been declared already */
                                                Insert((yyvsp[-1].string),(yyvsp[-2].operator),1,level,0,0,NULL);     /* inserts the variable in symbol table */
                                                goffset = offset;                   /* sets goffset equal to offset so you can retrun to it */
                                                offset = 2;
                                                maxoffset=offset;
                                          }
                                          else {
                                                yyerror("symbol already used");     /* throws an error if declaration is already used */
                                                exit(0);
                                               }
                                          }
#line 1477 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 164 "lab6.y" /* yacc.c:1646  */
    {(Search ((yyvsp[-3].string),0,0)) -> fparms = (yyvsp[0].node);}
#line 1483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 166 "lab6.y" /* yacc.c:1646  */
    {(yyval.node)=ASTCreateNode(FUNDEC);
                                                      (yyval.node)->name = (yyvsp[-6].string);
                                                      (yyval.node)->left = (yyvsp[-3].node);
                                                      (yyval.node)->operator = (yyvsp[-7].operator);
                                                      (yyval.node)->isType = (yyvsp[-7].operator);        /* sets is type to the type specified for type checking */
                                                      (yyval.node)->right = (yyvsp[0].node);
                                                      (yyval.node)->symbol=Search((yyvsp[-6].string),0,0);
                                                      offset = goffset;
                                                      (yyval.node) ->value = maxoffset;
                                                      }
#line 1498 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 179 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(PARAMS);
               (yyval.node)->operator= VOIDDEC;}
#line 1505 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 181 "lab6.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(PARAMS);
                          (yyval.node) -> left = (yyvsp[0].node);}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 185 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 186 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 189 "lab6.y" /* yacc.c:1646  */
    {
                              if (Search ((yyvsp[0].string),level+1,0) == NULL)  /* checks to make sure the variable hasnt been declared already */
                            {
                            (yyval.node)=ASTCreateNode(PARAM);
                            (yyval.node)->operator = (yyvsp[-1].operator);
                            (yyval.node)->isType = (yyvsp[-1].operator);                      /* sets is type to the type specified for type checking */
                            (yyval.node)->name=(yyvsp[0].string);
                            (yyval.node)->symbol = Insert((yyvsp[0].string),(yyvsp[-1].operator),0,level+1,1,offset,NULL);  /* inserts the variable in symbol table */
                            (yyval.node)->value = 0;
                            offset += 1;
                            }    
                            else{
                              yyerror("symbol already used");     /* throws an error if declaration is already used */
                              exit(0);
                                } 
                            }
#line 1545 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 205 "lab6.y" /* yacc.c:1646  */
    {
                                 if(Search((yyvsp[-2].string),level+1,0) == NULL)       /* checks to make sure the variable hasnt been declared already */
                                 {
                                  (yyval.node)=ASTCreateNode(PARAM);
                                  (yyval.node)->name = (yyvsp[-2].string);
                                  (yyval.node)->operator = (yyvsp[-3].operator);
                                  (yyval.node)->isType = (yyvsp[-3].operator);                      /* sets is type to the type specified for type checking */
                                  (yyval.node)->symbol = Insert((yyvsp[-2].string),(yyvsp[-3].operator),2,level+1,1,offset,NULL);  /* inserts the variable in symbol table */
                                  (yyval.node)->value=-1;
                                  offset +=1;
                                  }
                                  else {
                                      yyerror("symbol already used");   /* throws an error if declaration is already used */
                                      exit(0);   
                                       }
                                }
#line 1566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 223 "lab6.y" /* yacc.c:1646  */
    {level++;}
#line 1572 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(BLOCK);
                                          if ((yyvsp[-2].node)==NULL)
                                                (yyval.node) -> left=(yyvsp[-1].node);
                                          else {
                                                (yyval.node) -> left = (yyvsp[-1].node);
                                                (yyval.node) -> right = (yyvsp[-2].node);            
                                                }
                                          if(mydebug)
                                                Display(); 
                                          if(offset > maxoffset)
                                                maxoffset = offset;                   /* prints out what exist inside the compund statemnt */
                                          offset -=Delete(level);       /* deletes the current level from the table and decrements offset */
                                          level --;                  
                                          }
#line 1591 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 243 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 244 "lab6.y" /* yacc.c:1646  */
    {(yyvsp[-1].node) -> next = (yyvsp[0].node);
                                                      (yyval.node) = (yyvsp[-1].node);}
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 248 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1610 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 249 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node); (yyval.node)->next=(yyvsp[0].node);}
#line 1616 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 252 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 253 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1628 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 254 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1634 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 255 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1640 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 256 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 257 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1652 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 258 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1658 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 259 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1664 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 262 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);
                                     (yyval.node) ->name = CreateTemp();
                                     (yyval.node)->symbol = Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                                     offset++;}
#line 1673 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 266 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 269 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(ASSIGNSTMT);
                                           (yyval.node) -> right =  (yyvsp[0].node);
                                           (yyval.node) -> operator = EQUAL;
                                           (yyval.node) -> left = (yyvsp[-2].node);}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 275 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(IFSTMT);
                                                                (yyval.node) -> left = (yyvsp[-2].node);
                                                                (yyval.node) -> s1 = (yyvsp[0].node);}
#line 1696 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 278 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(IFSTMT);
                                                                (yyval.node) -> left = (yyvsp[-4].node);
                                                                (yyval.node) -> s1 = (yyvsp[-2].node);
                                                                (yyval.node) -> s2 = (yyvsp[0].node);}
#line 1705 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 284 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(ITERSTMT);
                                                       (yyval.node) -> right = (yyvsp[0].node);
                                                       (yyval.node) -> left = (yyvsp[-2].node);}
#line 1713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 289 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(RETURNSTMT);}
#line 1719 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 290 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(RETURNSTMT);
                                    (yyval.node) -> right = (yyvsp[-1].node);}
#line 1726 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 294 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(READSTMT);
                                 (yyval.node) -> right = (yyvsp[-1].node);}
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 298 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(OUT);
                                   (yyval.node) -> right = (yyvsp[-1].node);}
#line 1740 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 300 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(OUT);
                                     (yyval.node) ->name = (yyvsp[-1].string);}
#line 1747 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 304 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1753 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 307 "lab6.y" /* yacc.c:1646  */
    {if(Search((yyvsp[0].string),level,1) == NULL){     /* checks to make sure the variable hasnt been declared already */
                                        yyerror((yyvsp[0].string));
                                        yyerror("variable not defined");
                                        exit (1);
                                    }
                                   (yyval.node) = ASTCreateNode(IDENT);
                                   (yyval.node) -> name = (yyvsp[0].string);
                                   (yyval.node) -> symbol = Search((yyvsp[0].string),level,1);
                                   (yyval.node)->isType = Search((yyvsp[0].string),level,1)->Type;}
#line 1767 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 316 "lab6.y" /* yacc.c:1646  */
    {if(Search((yyvsp[-3].string),level,1) == NULL){
                                        yyerror((yyvsp[-3].string));
                                        yyerror("variable not defined");
                                        exit (1);
                                          }
                                    (yyval.node) = ASTCreateNode(IDENT);
                                    (yyval.node) -> right = (yyvsp[-1].node); 
                                    (yyval.node) -> name = (yyvsp[-3].string);
                                    (yyval.node)->isType = Search((yyvsp[-3].string),level,1)->Type;
                                    (yyval.node)->symbol = Search((yyvsp[-3].string),level,1); }
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 328 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1788 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 329 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(EXPR);
                                                              (yyval.node)->left = (yyvsp[-2].node);
                                                              (yyval.node)->right = (yyvsp[0].node);
                                                              (yyval.node)-> operator = (yyvsp[-1].operator);
                                                              (yyval.node) ->name = CreateTemp();
                                                              (yyval.node)->symbol = Insert((yyval.node)->name,(yyval.node)->isType,0,level,1,offset,NULL);
                                                              offset++;}
#line 1800 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 338 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = LESSTHAN;}
#line 1806 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 339 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = GREATERTHAN;}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 340 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = LESSTHANEQ;}
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 341 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = GREATERTHANEQ;}
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 342 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = EQUAL;}
#line 1830 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 343 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = NOTEQ;}
#line 1836 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 346 "lab6.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1842 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 347 "lab6.y" /* yacc.c:1646  */
    { if((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType)  /* checking for correct types*/
                                                      {
                                                          yyerror("additiv expression type mismatch");
                                                          exit(1);
                                                      }      
                         
                                                      (yyval.node) = ASTCreateNode( EXPR );
                                                      (yyval.node)->left = (yyvsp[-2].node);
                                                      (yyval.node)->right = (yyvsp[0].node);
                                                      (yyval.node)->operator = (yyvsp[-1].operator);
                                                      (yyval.node)->isType = (yyvsp[-2].node)->isType;          /* sets is type to the type specified for type checking */
                                                      (yyval.node)->name = CreateTemp();      /* creates a temp variable with the specified name*/
                                                      (yyval.node)->symbol = Insert((yyval.node)->name,INTDEC,0,level,1,offset,NULL);  /* inserts the variable in symbol table */
                                                      offset ++;}
#line 1861 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 362 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = PLUS;}
#line 1867 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 363 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = MINUS;}
#line 1873 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 366 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1879 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 367 "lab6.y" /* yacc.c:1646  */
    { if((yyvsp[-2].node)->isType != (yyvsp[0].node)->isType)    /* Making sure the terms are of same type otherwise throw error */
                              {
                                    yyerror("Term type mismatch");
                                    exit(1);
                              }      
                         
                              (yyval.node) = ASTCreateNode( EXPR );
                              (yyval.node)->left = (yyvsp[-2].node);
                              (yyval.node)->right = (yyvsp[0].node);
                              (yyval.node)->operator = (yyvsp[-1].operator);
                              (yyval.node)->isType = (yyvsp[-2].node)->isType;                /* sets is type to the type specified for type checking */
                              (yyval.node)->name = CreateTemp();            /* creates a temp variable with the specified name*/
                              (yyval.node)->symbol = Insert((yyval.node)->name,INTDEC,0,level,1,offset,NULL);  /* inserts the variable in symbol table */
                              offset ++;}
#line 1898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 383 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = TIMES;}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 384 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = DIV;}
#line 1910 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 385 "lab6.y" /* yacc.c:1646  */
    {(yyval.operator) = MOD;}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 388 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-1].node);}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 389 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = ASTCreateNode(NUMBER);
                               (yyval.node) -> value = (yyvsp[0].value); (yyval.node)->isType = INTDEC;}
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 391 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 392 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 395 "lab6.y" /* yacc.c:1646  */
    {if( check(Search((yyvsp[-3].string),level,1)->fparms,(yyvsp[-1].node))==0){  /* checks to make sure the variable hasnt been declared already */
                                    yyerror((yyvsp[-3].string));                              /* throws an error if declaration is already used */
                                    yyerror("function not defined");
                                    exit (1);
                              }
                              if(Search((yyvsp[-3].string),level,1)->IsAFunc != 1){     /* checks to make sure the variable hasnt been declared already */
                                    yyerror((yyvsp[-3].string));                        /* throws an error if declaration is already used */
                                    yyerror("function not defined");
                                    exit (1);
                              }
                               (yyval.node) = ASTCreateNode(CALL);
                               (yyval.node) -> name = (yyvsp[-3].string);
                               (yyval.node)->isType = Search((yyvsp[-3].string),level,1)->Type;
                               (yyval.node) -> right = (yyvsp[-1].node);}
#line 1960 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 411 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = NULL;}
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 412 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1972 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 415 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[0].node);}
#line 1978 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 416 "lab6.y" /* yacc.c:1646  */
    {(yyval.node) = (yyvsp[-2].node);
                                   (yyval.node) -> next = (yyvsp[0].node);}
#line 1985 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1989 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 420 "lab6.y" /* yacc.c:1906  */
 
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
