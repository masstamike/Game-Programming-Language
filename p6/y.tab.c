/* A Bison parser, made by GNU Bison 2.7.12-4996.  */

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
#define YYBISON_VERSION "2.7.12-4996"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "gpl.y"

//stuff from flex that bison needs to know about:
#include "expression.h"
extern int yylex();         // this lexer function returns next token
extern int yyerror(char *); // used to print errors
extern int line_count;      // the current line in the input; from arary.l
//extern "C" FILE *yyin;

#include "error.h"
#include "gpl_assert.h"
#include "parser.h"
#include <iostream>
#include <string>
#include <vector>
#include "symbol_table.h"
#include "symbol.h"
#include <cstdlib>
#include <sstream>
#include "gpl_type.h"
#include "variable.h"
#include "game_object.h"
//#include <map>
using namespace std;

vector<int> *int_vector;
Symbol_table* symbol_table = Symbol_table::instance();

/* Line 371 of yacc.c  */
#line 96 "y.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_OR = 258,
     T_AND = 259,
     T_NOT_EQUAL = 260,
     T_EQUAL = 261,
     T_LESS_EQUAL = 262,
     T_GREATER_EQUAL = 263,
     T_GREATER = 264,
     T_LESS = 265,
     T_PLUS = 266,
     T_MINUS = 267,
     T_MOD = 268,
     T_DIVIDE = 269,
     T_ASTERISK = 270,
     T_NOT = 271,
     UNARY_OPS = 272,
     T_MINUS_MINUS = 273,
     T_PLUS_PLUS = 274,
     T_ASSIGN = 275,
     IF_NO_ELSE = 276,
     T_ELSE = 277,
     T_INT = 278,
     T_DOUBLE = 279,
     T_STRING = 280,
     T_TRIANGLE = 281,
     T_PIXMAP = 282,
     T_CIRCLE = 283,
     T_RECTANGLE = 284,
     T_TEXTBOX = 285,
     T_FORWARD = 286,
     T_INITIALIZATION = 287,
     T_TRUE = 288,
     T_FALSE = 289,
     T_ON = 290,
     T_SPACE = 291,
     T_LEFTARROW = 292,
     T_RIGHTARROW = 293,
     T_UPARROW = 294,
     T_DOWNARROW = 295,
     T_LEFTMOUSE_DOWN = 296,
     T_MIDDLEMOUSE_DOWN = 297,
     T_RIGHTMOUSE_DOWN = 298,
     T_LEFTMOUSE_UP = 299,
     T_MIDDLEMOUSE_UP = 300,
     T_RIGHTMOUSE_UP = 301,
     T_MOUSE_MOVE = 302,
     T_MOUSE_DRAG = 303,
     T_F1 = 304,
     T_AKEY = 305,
     T_SKEY = 306,
     T_DKEY = 307,
     T_FKEY = 308,
     T_HKEY = 309,
     T_JKEY = 310,
     T_KKEY = 311,
     T_LKEY = 312,
     T_WKEY = 313,
     T_TOUCHES = 314,
     T_NEAR = 315,
     T_ANIMATION = 316,
     T_IF = 317,
     T_FOR = 318,
     T_EXIT = 319,
     T_LPAREN = 320,
     T_RPAREN = 321,
     T_LBRACE = 322,
     T_RBRACE = 323,
     T_LBRACKET = 324,
     T_RBRACKET = 325,
     T_SEMIC = 326,
     T_COMMA = 327,
     T_PERIOD = 328,
     T_PLUS_ASSIGN = 329,
     T_MINUS_ASSIGN = 330,
     T_SIN = 331,
     T_COS = 332,
     T_TAN = 333,
     T_ASIN = 334,
     T_ACOS = 335,
     T_ATAN = 336,
     T_SQRT = 337,
     T_FLOOR = 338,
     T_ABS = 339,
     T_RANDOM = 340,
     T_ID = 341,
     T_INT_CONSTANT = 342,
     T_DOUBLE_CONSTANT = 343,
     T_STRING_CONSTANT = 344,
     T_PRINT = 345,
     T_ERROR = 346
   };
#endif
/* Tokens.  */
#define T_OR 258
#define T_AND 259
#define T_NOT_EQUAL 260
#define T_EQUAL 261
#define T_LESS_EQUAL 262
#define T_GREATER_EQUAL 263
#define T_GREATER 264
#define T_LESS 265
#define T_PLUS 266
#define T_MINUS 267
#define T_MOD 268
#define T_DIVIDE 269
#define T_ASTERISK 270
#define T_NOT 271
#define UNARY_OPS 272
#define T_MINUS_MINUS 273
#define T_PLUS_PLUS 274
#define T_ASSIGN 275
#define IF_NO_ELSE 276
#define T_ELSE 277
#define T_INT 278
#define T_DOUBLE 279
#define T_STRING 280
#define T_TRIANGLE 281
#define T_PIXMAP 282
#define T_CIRCLE 283
#define T_RECTANGLE 284
#define T_TEXTBOX 285
#define T_FORWARD 286
#define T_INITIALIZATION 287
#define T_TRUE 288
#define T_FALSE 289
#define T_ON 290
#define T_SPACE 291
#define T_LEFTARROW 292
#define T_RIGHTARROW 293
#define T_UPARROW 294
#define T_DOWNARROW 295
#define T_LEFTMOUSE_DOWN 296
#define T_MIDDLEMOUSE_DOWN 297
#define T_RIGHTMOUSE_DOWN 298
#define T_LEFTMOUSE_UP 299
#define T_MIDDLEMOUSE_UP 300
#define T_RIGHTMOUSE_UP 301
#define T_MOUSE_MOVE 302
#define T_MOUSE_DRAG 303
#define T_F1 304
#define T_AKEY 305
#define T_SKEY 306
#define T_DKEY 307
#define T_FKEY 308
#define T_HKEY 309
#define T_JKEY 310
#define T_KKEY 311
#define T_LKEY 312
#define T_WKEY 313
#define T_TOUCHES 314
#define T_NEAR 315
#define T_ANIMATION 316
#define T_IF 317
#define T_FOR 318
#define T_EXIT 319
#define T_LPAREN 320
#define T_RPAREN 321
#define T_LBRACE 322
#define T_RBRACE 323
#define T_LBRACKET 324
#define T_RBRACKET 325
#define T_SEMIC 326
#define T_COMMA 327
#define T_PERIOD 328
#define T_PLUS_ASSIGN 329
#define T_MINUS_ASSIGN 330
#define T_SIN 331
#define T_COS 332
#define T_TAN 333
#define T_ASIN 334
#define T_ACOS 335
#define T_ATAN 336
#define T_SQRT 337
#define T_FLOOR 338
#define T_ABS 339
#define T_RANDOM 340
#define T_ID 341
#define T_INT_CONSTANT 342
#define T_DOUBLE_CONSTANT 343
#define T_STRING_CONSTANT 344
#define T_PRINT 345
#define T_ERROR 346



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 35 "gpl.y"

 int            union_int;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 double         union_double;
 Gpl_type       union_variable_type;
 Variable*       union_variable;
 Operator_type  union_operator_type;
 Expr*          union_expr;


/* Line 387 of yacc.c  */
#line 332 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 360 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

#ifndef __attribute__
/* This feature is available in gcc versions 2.5 and later.  */
# if (! defined __GNUC__ || __GNUC__ < 2 \
      || (__GNUC__ == 2 && __GNUC_MINOR__ < 5))
#  define __attribute__(Spec) /* empty */
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif


/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   366

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  92
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  127
/* YYNRULES -- Number of states.  */
#define YYNSTATES  227

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   346

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     9,    11,    14,    17,    20,    24,
      30,    32,    34,    36,    39,    41,    47,    53,    55,    57,
      59,    61,    63,    65,    67,    71,    73,    77,    84,    87,
      89,    91,    93,    95,    98,    99,   110,   113,   116,   119,
     122,   125,   128,   132,   134,   136,   138,   140,   142,   144,
     146,   148,   150,   152,   154,   156,   158,   160,   162,   164,
     166,   168,   170,   172,   174,   176,   178,   182,   184,   190,
     191,   192,   195,   197,   199,   201,   204,   207,   210,   216,
     224,   238,   243,   248,   252,   256,   260,   262,   267,   271,
     278,   280,   284,   288,   292,   296,   300,   304,   308,   312,
     316,   320,   324,   328,   332,   335,   338,   343,   347,   351,
     353,   355,   357,   359,   361,   363,   365,   367,   369,   371,
     373,   375,   377,   379,   381,   383,   385,   387
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      93,     0,    -1,    94,   105,    -1,    94,    95,    -1,   130,
      -1,    96,    71,    -1,    99,    71,    -1,   104,    71,    -1,
      97,    86,    98,    -1,    97,    86,    69,   126,    70,    -1,
      23,    -1,    24,    -1,    25,    -1,    20,   126,    -1,   130,
      -1,   100,    86,    65,   101,    66,    -1,   100,    86,    69,
     126,    70,    -1,    26,    -1,    27,    -1,    28,    -1,    29,
      -1,    30,    -1,   102,    -1,   130,    -1,   102,    72,   103,
      -1,   103,    -1,    86,    20,   126,    -1,    31,    61,    86,
      65,   110,    66,    -1,   105,   106,    -1,   130,    -1,   107,
      -1,   108,    -1,   112,    -1,    32,   115,    -1,    -1,    61,
      86,    65,   111,    66,    67,   109,   118,    68,   117,    -1,
     100,    86,    -1,    26,    86,    -1,    27,    86,    -1,    28,
      86,    -1,    29,    86,    -1,    30,    86,    -1,    35,   113,
     115,    -1,    36,    -1,    39,    -1,    40,    -1,    37,    -1,
      38,    -1,    41,    -1,    42,    -1,    43,    -1,    44,    -1,
      45,    -1,    46,    -1,    47,    -1,    48,    -1,    50,    -1,
      51,    -1,    52,    -1,    53,    -1,    54,    -1,    55,    -1,
      56,    -1,    57,    -1,    58,    -1,    49,    -1,   116,   119,
     117,    -1,   115,    -1,    67,   116,   118,    68,   117,    -1,
      -1,    -1,   118,   119,    -1,   130,    -1,   120,    -1,   121,
      -1,   124,    71,    -1,   122,    71,    -1,   123,    71,    -1,
      62,    65,   126,    66,   114,    -1,    62,    65,   126,    66,
     114,    22,   114,    -1,    63,    65,   116,   124,   117,    71,
     126,    71,   116,   124,   117,    66,   115,    -1,    90,    65,
     126,    66,    -1,    64,    65,   126,    66,    -1,   125,    20,
     126,    -1,   125,    74,   126,    -1,   125,    75,   126,    -1,
      86,    -1,    86,    69,   126,    70,    -1,    86,    73,    86,
      -1,    86,    69,   126,    70,    73,    86,    -1,   127,    -1,
     126,     3,   126,    -1,   126,     4,   126,    -1,   126,     7,
     126,    -1,   126,     8,   126,    -1,   126,    10,   126,    -1,
     126,     9,   126,    -1,   126,     6,   126,    -1,   126,     5,
     126,    -1,   126,    11,   126,    -1,   126,    12,   126,    -1,
     126,    15,   126,    -1,   126,    14,   126,    -1,   126,    13,
     126,    -1,    12,   126,    -1,    16,   126,    -1,   129,    65,
     126,    66,    -1,   125,   128,   125,    -1,    65,   126,    66,
      -1,   125,    -1,    87,    -1,    33,    -1,    34,    -1,    88,
      -1,    89,    -1,    59,    -1,    60,    -1,    76,    -1,    77,
      -1,    78,    -1,    79,    -1,    80,    -1,    81,    -1,    82,
      -1,    84,    -1,    83,    -1,    85,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   179,   179,   184,   185,   190,   191,   192,   197,   235,
     278,   279,   280,   285,   288,   293,   294,   299,   300,   301,
     302,   303,   308,   309,   314,   315,   320,   325,   330,   331,
     336,   337,   338,   343,   348,   348,   353,   358,   359,   360,
     361,   362,   367,   372,   373,   374,   375,   376,   377,   378,
     379,   380,   381,   382,   383,   384,   385,   386,   387,   388,
     389,   390,   391,   392,   393,   394,   399,   400,   405,   409,
     414,   420,   421,   426,   427,   428,   429,   430,   435,   436,
     441,   446,   451,   456,   457,   458,   463,   477,   504,   505,
     510,   511,   520,   529,   530,   533,   534,   535,   538,   539,
     542,   550,   558,   564,   565,   568,   571,   590,   595,   598,
     604,   607,   610,   613,   616,   623,   624,   629,   630,   631,
     632,   633,   634,   635,   636,   637,   638,   642
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_OR", "T_AND", "T_NOT_EQUAL",
  "T_EQUAL", "T_LESS_EQUAL", "T_GREATER_EQUAL", "T_GREATER", "T_LESS",
  "T_PLUS", "T_MINUS", "T_MOD", "T_DIVIDE", "T_ASTERISK", "T_NOT",
  "UNARY_OPS", "T_MINUS_MINUS", "T_PLUS_PLUS", "T_ASSIGN", "IF_NO_ELSE",
  "T_ELSE", "T_INT", "T_DOUBLE", "T_STRING", "T_TRIANGLE", "T_PIXMAP",
  "T_CIRCLE", "T_RECTANGLE", "T_TEXTBOX", "T_FORWARD", "T_INITIALIZATION",
  "T_TRUE", "T_FALSE", "T_ON", "T_SPACE", "T_LEFTARROW", "T_RIGHTARROW",
  "T_UPARROW", "T_DOWNARROW", "T_LEFTMOUSE_DOWN", "T_MIDDLEMOUSE_DOWN",
  "T_RIGHTMOUSE_DOWN", "T_LEFTMOUSE_UP", "T_MIDDLEMOUSE_UP",
  "T_RIGHTMOUSE_UP", "T_MOUSE_MOVE", "T_MOUSE_DRAG", "T_F1", "T_AKEY",
  "T_SKEY", "T_DKEY", "T_FKEY", "T_HKEY", "T_JKEY", "T_KKEY", "T_LKEY",
  "T_WKEY", "T_TOUCHES", "T_NEAR", "T_ANIMATION", "T_IF", "T_FOR",
  "T_EXIT", "T_LPAREN", "T_RPAREN", "T_LBRACE", "T_RBRACE", "T_LBRACKET",
  "T_RBRACKET", "T_SEMIC", "T_COMMA", "T_PERIOD", "T_PLUS_ASSIGN",
  "T_MINUS_ASSIGN", "T_SIN", "T_COS", "T_TAN", "T_ASIN", "T_ACOS",
  "T_ATAN", "T_SQRT", "T_FLOOR", "T_ABS", "T_RANDOM", "T_ID",
  "T_INT_CONSTANT", "T_DOUBLE_CONSTANT", "T_STRING_CONSTANT", "T_PRINT",
  "T_ERROR", "$accept", "program", "declaration_list", "declaration",
  "variable_declaration", "simple_type", "optional_initializer",
  "object_declaration", "object_type", "parameter_list_or_empty",
  "parameter_list", "parameter", "forward_declaration", "block_list",
  "block", "initialization_block", "animation_block", "$@1",
  "animation_parameter", "check_animation_parameter", "on_block",
  "keystroke", "if_block", "statement_block", "statement_block_creator",
  "end_of_statement_block", "statement_list", "statement", "if_statement",
  "for_statement", "print_statement", "exit_statement", "assign_statement",
  "variable", "expression", "primary_expression", "geometric_operator",
  "math_operator", "empty", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    92,    93,    94,    94,    95,    95,    95,    96,    96,
      97,    97,    97,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   104,   105,   105,
     106,   106,   106,   107,   109,   108,   110,   111,   111,   111,
     111,   111,   112,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   113,
     113,   113,   113,   113,   113,   113,   114,   114,   115,   116,
     117,   118,   118,   119,   119,   119,   119,   119,   120,   120,
     121,   122,   123,   124,   124,   124,   125,   125,   125,   125,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   129,
     129,   129,   129,   129,   129,   129,   129,   130
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     2,     1,     2,     2,     2,     3,     5,
       1,     1,     1,     2,     1,     5,     5,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     6,     2,     1,
       1,     1,     1,     2,     0,    10,     2,     2,     2,     2,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     5,     0,
       0,     2,     1,     1,     1,     2,     2,     2,     5,     7,
      13,     4,     4,     3,     3,     3,     1,     4,     3,     6,
       1,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     127,     0,   127,     4,     1,    10,    11,    12,    17,    18,
      19,    20,    21,     0,     3,     0,     0,     0,     0,     0,
       2,    29,     0,     5,   127,     6,     0,     7,     0,     0,
       0,    28,    30,    31,    32,     0,     0,     0,     8,    14,
     127,     0,    69,    33,    43,    46,    47,    44,    45,    48,
      49,    50,    51,    52,    53,    54,    55,    65,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,     0,     0,
       0,     0,   111,   112,     0,   117,   118,   119,   120,   121,
     122,   123,   125,   124,   126,    86,   110,   113,   114,   109,
      13,    90,     0,     0,     0,     0,    22,    25,    23,     0,
     127,    42,     0,     0,     0,   104,   105,     0,     0,     0,
     115,   116,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,     0,    15,
       0,    16,     0,    72,     0,     0,     0,     0,     0,     0,
      36,    27,   108,     0,    88,   107,    91,    92,    98,    97,
      93,    94,    96,    95,    99,   100,   103,   102,   101,     0,
      26,    24,     0,     0,     0,    70,     0,    71,    73,    74,
       0,     0,     0,     0,    37,    38,    39,    40,    41,     0,
      87,   106,     0,    69,     0,    68,     0,    76,    77,    75,
       0,     0,     0,    34,     0,     0,     0,     0,     0,    83,
      84,    85,   127,    89,    69,    70,    82,    81,     0,    78,
      67,     0,     0,    70,    69,    70,     0,    35,    79,    66,
       0,    69,     0,    70,     0,     0,    80
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    14,    15,    16,    38,    17,    18,    95,
      96,    97,    19,    20,    31,    32,    33,   202,   104,   139,
      34,    67,   209,   210,   211,   185,   132,   167,   168,   169,
     170,   171,   172,    89,    90,    91,   112,    92,   133
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -167
static const yytype_int16 yypact[] =
{
    -167,     3,    39,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,   -30,  -167,   -38,   -29,   -12,   -13,    31,
      -6,  -167,    18,  -167,   -16,  -167,   -37,  -167,     7,   253,
      19,  -167,  -167,  -167,  -167,    45,    42,    42,  -167,  -167,
      29,    42,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,     7,    51,    -5,
      42,    42,  -167,  -167,    42,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,    66,  -167,  -167,  -167,   -23,
     311,  -167,    67,   154,   117,    72,    69,  -167,  -167,   179,
    -167,  -167,   144,    59,    81,  -167,  -167,     5,    42,    65,
    -167,  -167,   110,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,  -167,    42,  -167,
      29,  -167,   177,  -167,   152,   160,   161,   178,   182,    87,
    -167,  -167,  -167,   195,  -167,  -167,   335,   322,    86,    86,
     164,   164,   164,   164,   258,   258,  -167,  -167,  -167,   208,
     311,  -167,   130,   204,   286,  -167,   287,  -167,  -167,  -167,
     241,   282,   283,   -14,  -167,  -167,  -167,  -167,  -167,   288,
     284,  -167,    42,  -167,    42,  -167,    42,  -167,  -167,  -167,
      42,    42,    42,  -167,   270,   222,   110,   247,   272,   311,
     311,   311,  -167,  -167,     7,  -167,  -167,  -167,   180,   336,
    -167,    50,   289,  -167,     7,  -167,    42,  -167,  -167,  -167,
      37,  -167,   110,  -167,   293,     7,  -167
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,   292,  -167,
    -167,   232,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   149,   -28,   -40,   -71,   162,   155,  -167,  -167,
    -167,  -167,  -166,  -105,   -36,  -167,  -167,  -167,   109
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      43,    93,   100,     4,    36,    99,   190,   145,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,     8,     9,    10,    11,    12,    28,   173,    40,    29,
     205,    22,    41,    23,   105,   106,   110,   111,   107,   101,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    37,    70,    30,   223,    24,    71,    25,
     191,   192,     5,     6,     7,     8,     9,    10,    11,    12,
      13,   142,   143,    26,    42,    72,    73,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   155,   156,   157,   158,
     159,   173,   160,   117,   118,   119,   120,   121,   122,   123,
     124,   125,    27,   173,    35,    68,   173,    74,   221,     3,
      69,    21,   162,   163,   164,    94,   102,   173,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,   126,    39,   212,   108,    85,   128,   129,   109,
     166,   130,   217,   196,   219,   140,   195,   141,   197,    98,
     198,   144,   224,   179,   199,   200,   201,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     134,   135,   136,   137,   138,   121,   122,   123,   124,   125,
     220,   222,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   182,    85,   226,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,   123,   124,   125,   127,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   174,   162,
     163,   164,   162,   163,   164,   165,   175,   176,   213,   131,
     113,   114,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,   125,    85,   177,   180,    85,   166,   178,   183,
     166,   123,   124,   125,   181,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   204,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,   187,   206,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,   125,   207,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   184,   186,   188,   189,   193,   203,   194,   214,   225,
     216,   103,   161,   218,   208,     0,   215
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
      28,    37,    42,     0,    20,    41,    20,   112,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    26,    27,    28,    29,    30,    32,   132,    65,    35,
     196,    61,    69,    71,    70,    71,    59,    60,    74,    67,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    69,    12,    61,   222,    86,    16,    71,
      74,    75,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    66,   108,    86,    67,    33,    34,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   196,   128,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    71,   208,    86,    86,   211,    65,    71,     0,
      65,     2,    62,    63,    64,    86,    65,   222,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    65,    24,   205,    69,    86,    20,    66,    73,
      90,    72,   213,   183,   215,    86,   182,    66,   184,    40,
     186,    86,   223,    66,   190,   191,   192,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      26,    27,    28,    29,    30,    11,    12,    13,    14,    15,
     216,   221,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    65,    86,   225,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    70,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    86,    62,
      63,    64,    62,    63,    64,    68,    86,    86,    68,    70,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    86,    86,    70,    86,    90,    86,    65,
      90,    13,    14,    15,    66,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    66,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    71,    66,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    66,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    65,    65,    71,    71,    67,    86,    73,    22,    66,
      71,    69,   130,   214,   202,    -1,   211
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    93,    94,   130,     0,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    95,    96,    97,    99,   100,   104,
     105,   130,    61,    71,    86,    71,    86,    71,    32,    35,
      61,   106,   107,   108,   112,    86,    20,    69,    98,   130,
      65,    69,    67,   115,    36,    37,    38,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,   113,    86,    65,
      12,    16,    33,    34,    65,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,   125,
     126,   127,   129,   126,    86,   101,   102,   103,   130,   126,
     116,   115,    65,   100,   110,   126,   126,   126,    69,    73,
      59,    60,   128,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    65,    70,    20,    66,
      72,    70,   118,   130,    26,    27,    28,    29,    30,   111,
      86,    66,    66,   126,    86,   125,   126,   126,   126,   126,
     126,   126,   126,   126,   126,   126,   126,   126,   126,   126,
     126,   103,    62,    63,    64,    68,    90,   119,   120,   121,
     122,   123,   124,   125,    86,    86,    86,    86,    86,    66,
      70,    66,    65,    65,    65,   117,    65,    71,    71,    71,
      20,    74,    75,    67,    73,   126,   116,   126,   126,   126,
     126,   126,   109,    86,    66,   124,    66,    66,   118,   114,
     115,   116,   117,    68,    22,   119,    71,   117,   114,   117,
     126,    71,   116,   124,   117,    66,   115
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YYUSE (yytype);
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 8:
/* Line 1787 of yacc.c  */
#line 198 "gpl.y"
    {
        string array = *(yyvsp[(2) - (3)].union_string);
        array = array + "[0]";
        if(symbol_table->find(*(yyvsp[(2) - (3)].union_string)) || symbol_table->find(array)){
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE,
                *(yyvsp[(2) - (3)].union_string));
        }
        if((yyvsp[(3) - (3)].union_expr) && ((yyvsp[(3) - (3)].union_expr)->get_kind()=="constant" || (yyvsp[(3) - (3)].union_expr)->get_kind()=="variable") &&
             ((yyvsp[(3) - (3)].union_expr)->get_type()!=gpl_type_to_string((yyvsp[(1) - (3)].union_variable_type))) && (yyvsp[(1) - (3)].union_variable_type)!=STRING) {
            if(!((yyvsp[(1) - (3)].union_variable_type)==DOUBLE && (yyvsp[(3) - (3)].union_expr)->get_type()=="int"))
                Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*(yyvsp[(2) - (3)].union_string));
        }
        else if((yyvsp[(3) - (3)].union_expr) && (yyvsp[(1) - (3)].union_variable_type)==INT && (yyvsp[(3) - (3)].union_expr)->get_type()!="int")
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*(yyvsp[(2) - (3)].union_string));
        else if((yyvsp[(3) - (3)].union_expr) && (yyvsp[(1) - (3)].union_variable_type)==DOUBLE && (yyvsp[(3) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*(yyvsp[(2) - (3)].union_string));
        if((yyvsp[(1) - (3)].union_variable_type) == INT)
            symbol_table->add(*(yyvsp[(2) - (3)].union_string), new Symbol(*(yyvsp[(2) - (3)].union_string),new int((yyvsp[(3) - (3)].union_expr)?(yyvsp[(3) - (3)].union_expr)->eval_int():
                0),"int"));
        else if((yyvsp[(1) - (3)].union_variable_type) == DOUBLE)
            symbol_table->add(*(yyvsp[(2) - (3)].union_string), new Symbol(*(yyvsp[(2) - (3)].union_string),new double((yyvsp[(3) - (3)].union_expr)?
                (yyvsp[(3) - (3)].union_expr)->eval_double():0.0),"double"));
        else if((yyvsp[(1) - (3)].union_variable_type) == STRING) {
            stringstream ss;
            if(!(yyvsp[(3) - (3)].union_expr))
                ss << "";
            else if((yyvsp[(3) - (3)].union_expr)->get_type() == "int") {
                ss << (yyvsp[(3) - (3)].union_expr)->eval_int();}
            else if((yyvsp[(3) - (3)].union_expr)->get_type() == "double")
                ss << (yyvsp[(3) - (3)].union_expr)->eval_double();
            else
                ss << (yyvsp[(3) - (3)].union_expr)->eval_string();
            symbol_table->add(*(yyvsp[(2) - (3)].union_string), new Symbol(*(yyvsp[(2) - (3)].union_string),
            new string(ss.str()),
            "string"));
        }
    }
    break;

  case 9:
/* Line 1787 of yacc.c  */
#line 235 "gpl.y"
    {
        string array = *(yyvsp[(2) - (5)].union_string);
        array = array + "[0]";
        if(symbol_table->find(*(yyvsp[(2) - (5)].union_string)) || symbol_table->find(array)){
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE,
                *(yyvsp[(2) - (5)].union_string));
        }
        if((yyvsp[(4) - (5)].union_expr)->get_type()=="int" && (yyvsp[(4) - (5)].union_expr)->eval_int() <1) {
            if((yyvsp[(4) - (5)].union_expr)->get_type() == "int") {
                stringstream ss;
                ss<<(yyvsp[(4) - (5)].union_expr)->eval_int();
                Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),ss.str());
            } else if((yyvsp[(4) - (5)].union_expr)->get_type() == "double") {
                stringstream ss;
                ss<<(yyvsp[(4) - (5)].union_expr)->eval_double();
                Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),ss.str());
            } else if((yyvsp[(4) - (5)].union_expr)->get_type() == "string") {
                Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expr)->eval_string());
            }
        }
        if((yyvsp[(4) - (5)].union_expr)->get_type() != "int") {
            Error::error(Error::INVALID_ARRAY_SIZE,*(yyvsp[(2) - (5)].union_string),(yyvsp[(4) - (5)].union_expr)->eval_string());
        }
        for (int x = 0; x<(yyvsp[(4) - (5)].union_expr)->eval_int(); x++) {
            string name = *(yyvsp[(2) - (5)].union_string);
            std::stringstream out;
            out<<x;
            name = name + '['+out.str()+']';
            if((yyvsp[(1) - (5)].union_variable_type) == INT)
                symbol_table->add(name, new Symbol(*(yyvsp[(2) - (5)].union_string),new int(0),"int"));
            else if((yyvsp[(1) - (5)].union_variable_type) == DOUBLE)
                symbol_table->add(name, new Symbol(*(yyvsp[(2) - (5)].union_string),new double(0.0),
                "double"));
            else if((yyvsp[(1) - (5)].union_variable_type) == STRING)
                symbol_table->add(name, new Symbol(*(yyvsp[(2) - (5)].union_string),
                new string(""),
                "string"));
    }
    }
    break;

  case 10:
/* Line 1787 of yacc.c  */
#line 278 "gpl.y"
    {(yyval.union_variable_type)=INT;}
    break;

  case 11:
/* Line 1787 of yacc.c  */
#line 279 "gpl.y"
    {(yyval.union_variable_type)=DOUBLE;}
    break;

  case 12:
/* Line 1787 of yacc.c  */
#line 280 "gpl.y"
    {(yyval.union_variable_type)=STRING;}
    break;

  case 13:
/* Line 1787 of yacc.c  */
#line 285 "gpl.y"
    {
        (yyval.union_expr)=(yyvsp[(2) - (2)].union_expr);
    }
    break;

  case 14:
/* Line 1787 of yacc.c  */
#line 288 "gpl.y"
    {(yyval.union_expr)=NULL;}
    break;

  case 34:
/* Line 1787 of yacc.c  */
#line 348 "gpl.y"
    { }
    break;

  case 86:
/* Line 1787 of yacc.c  */
#line 463 "gpl.y"
    {
        Symbol* var = symbol_table->find(*(yyvsp[(1) - (1)].union_string));
        if(var) {
            if(var->m_type == "int")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (1)].union_string),var,"int");
            else if(var->m_type == "double")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (1)].union_string),var,"double");
            else if(var->m_type == "string")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (1)].union_string),var,"string");
        } else {
            Error::error(Error::UNDECLARED_VARIABLE,*(yyvsp[(1) - (1)].union_string));
            (yyval.union_variable)=NULL;
        }
    }
    break;

  case 87:
/* Line 1787 of yacc.c  */
#line 477 "gpl.y"
    {
        if((yyvsp[(3) - (4)].union_expr)->get_type() !=  "int") {
            string s2=(yyvsp[(3) - (4)].union_expr)->get_type();
            s2="A "+s2+" expression";
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*(yyvsp[(1) - (4)].union_string),s2);
            (yyval.union_variable)=NULL;
        }
        string array = *(yyvsp[(1) - (4)].union_string);
        int index = (yyvsp[(3) - (4)].union_expr)->eval_int();
        stringstream ss;
        ss<<index;
        array = array + "[" + ss.str() + "]";
        Symbol* sym = symbol_table->find(array);
        if(sym) {
            if(sym->m_type == "int")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (4)].union_string),sym,"int");
            else if(sym->m_type == "double")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (4)].union_string),sym,"double");
            else if(sym->m_type == "string")
                (yyval.union_variable)=new Variable(*(yyvsp[(1) - (4)].union_string),sym,"string");
        } else {
            stringstream ss;
            ss<<(yyvsp[(3) - (4)].union_expr)->eval_int();
            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*(yyvsp[(1) - (4)].union_string),ss.str());
            (yyval.union_variable)=NULL;
        }
    }
    break;

  case 90:
/* Line 1787 of yacc.c  */
#line 510 "gpl.y"
    {(yyval.union_expr)=(yyvsp[(1) - (1)].union_expr);}
    break;

  case 91:
/* Line 1787 of yacc.c  */
#line 512 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"||");
        else if((yyvsp[(3) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"||");
        else
            (yyval.union_expr)=new Expr(OR, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 92:
/* Line 1787 of yacc.c  */
#line 521 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"&&");
        else if((yyvsp[(3) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"&&");
        else
            (yyval.union_expr)=new Expr(AND, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 93:
/* Line 1787 of yacc.c  */
#line 529 "gpl.y"
    {(yyval.union_expr)=new Expr(LESS_THAN_EQUAL,(yyvsp[(1) - (3)].union_expr),(yyvsp[(3) - (3)].union_expr));}
    break;

  case 94:
/* Line 1787 of yacc.c  */
#line 530 "gpl.y"
    {
        (yyval.union_expr)=new Expr(GREATER_THAN_EQUAL,(yyvsp[(1) - (3)].union_expr),(yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 95:
/* Line 1787 of yacc.c  */
#line 533 "gpl.y"
    {(yyval.union_expr)=new Expr(LESS_THAN, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));}
    break;

  case 96:
/* Line 1787 of yacc.c  */
#line 534 "gpl.y"
    {(yyval.union_expr)=new Expr(GREATER_THAN,(yyvsp[(1) - (3)].union_expr),(yyvsp[(3) - (3)].union_expr));}
    break;

  case 97:
/* Line 1787 of yacc.c  */
#line 535 "gpl.y"
    {
        (yyval.union_expr)=new Expr(EQUAL, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 98:
/* Line 1787 of yacc.c  */
#line 538 "gpl.y"
    {(yyval.union_expr)=new Expr(NOT_EQUAL,(yyvsp[(1) - (3)].union_expr),(yyvsp[(3) - (3)].union_expr));}
    break;

  case 99:
/* Line 1787 of yacc.c  */
#line 539 "gpl.y"
    {
        (yyval.union_expr)=new Expr(PLUS, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 100:
/* Line 1787 of yacc.c  */
#line 542 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"-");
        else if((yyvsp[(3) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"-");
        else
            (yyval.union_expr)=new Expr(MINUS, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 101:
/* Line 1787 of yacc.c  */
#line 550 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"*");
        else if((yyvsp[(3) - (3)].union_expr)->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"*");
        else
            (yyval.union_expr)=new Expr(MULTIPLY, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 102:
/* Line 1787 of yacc.c  */
#line 558 "gpl.y"
    {
        if((yyvsp[(1) - (3)].union_expr)->get_type() == "string" || (yyvsp[(3) - (3)].union_expr)->get_type() == "string");
            //error
        else
            (yyval.union_expr)=new Expr(DIVIDE, (yyvsp[(1) - (3)].union_expr), (yyvsp[(3) - (3)].union_expr));
    }
    break;

  case 103:
/* Line 1787 of yacc.c  */
#line 564 "gpl.y"
    {(yyval.union_expr)=new Expr(MOD,(yyvsp[(1) - (3)].union_expr),(yyvsp[(3) - (3)].union_expr));}
    break;

  case 104:
/* Line 1787 of yacc.c  */
#line 565 "gpl.y"
    {
        (yyval.union_expr)=new Expr(UNARY_MINUS, (yyvsp[(2) - (2)].union_expr));
    }
    break;

  case 105:
/* Line 1787 of yacc.c  */
#line 568 "gpl.y"
    {
        (yyval.union_expr)=new Expr(NOT, (yyvsp[(2) - (2)].union_expr));
    }
    break;

  case 106:
/* Line 1787 of yacc.c  */
#line 571 "gpl.y"
    {
        if((yyvsp[(1) - (4)].union_operator_type)==SQRT && (yyvsp[(3) - (4)].union_expr)->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"sqrt");
            (yyval.union_expr)=new Expr(0);
        } else if((yyvsp[(1) - (4)].union_operator_type)==ABS && (yyvsp[(3) - (4)].union_expr)->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"abs");
            (yyval.union_expr)=new Expr(0);
        } else if((yyvsp[(1) - (4)].union_operator_type)==FLOOR && (yyvsp[(3) - (4)].union_expr)->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"floor");
            (yyval.union_expr)=new Expr(0);
        } else if((yyvsp[(1) - (4)].union_operator_type)==RANDOM && (yyvsp[(3) - (4)].union_expr)->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"random");
            (yyval.union_expr)=new Expr(0);
        }
        if((yyvsp[(3) - (4)].union_expr)->get_type()=="int" || (yyvsp[(3) - (4)].union_expr)->get_type()=="double")
            (yyval.union_expr)=new Expr((yyvsp[(1) - (4)].union_operator_type),(yyvsp[(3) - (4)].union_expr));
//        else
            //error
    }
    break;

  case 108:
/* Line 1787 of yacc.c  */
#line 595 "gpl.y"
    {
        (yyval.union_expr)=(yyvsp[(2) - (3)].union_expr);
    }
    break;

  case 109:
/* Line 1787 of yacc.c  */
#line 598 "gpl.y"
    {
        if((yyvsp[(1) - (1)].union_variable))
            (yyval.union_expr) = new Expr((yyvsp[(1) - (1)].union_variable));
        else
            (yyval.union_expr)=new Expr(0);
    }
    break;

  case 110:
/* Line 1787 of yacc.c  */
#line 604 "gpl.y"
    {
        (yyval.union_expr)=new Expr((yyvsp[(1) - (1)].union_int));
    }
    break;

  case 111:
/* Line 1787 of yacc.c  */
#line 607 "gpl.y"
    {
        (yyval.union_expr)=new Expr(1);
    }
    break;

  case 112:
/* Line 1787 of yacc.c  */
#line 610 "gpl.y"
    {
        (yyval.union_expr)=new Expr(0);
    }
    break;

  case 113:
/* Line 1787 of yacc.c  */
#line 613 "gpl.y"
    {
        (yyval.union_expr)=new Expr((yyvsp[(1) - (1)].union_double));
    }
    break;

  case 114:
/* Line 1787 of yacc.c  */
#line 616 "gpl.y"
    {
        (yyval.union_expr)=new Expr(*(yyvsp[(1) - (1)].union_string));
    }
    break;

  case 117:
/* Line 1787 of yacc.c  */
#line 629 "gpl.y"
    {(yyval.union_operator_type)=SIN;}
    break;

  case 118:
/* Line 1787 of yacc.c  */
#line 630 "gpl.y"
    {(yyval.union_operator_type)=COS;}
    break;

  case 119:
/* Line 1787 of yacc.c  */
#line 631 "gpl.y"
    {(yyval.union_operator_type)=TAN;}
    break;

  case 120:
/* Line 1787 of yacc.c  */
#line 632 "gpl.y"
    {(yyval.union_operator_type)=ASIN;}
    break;

  case 121:
/* Line 1787 of yacc.c  */
#line 633 "gpl.y"
    {(yyval.union_operator_type)=ACOS;}
    break;

  case 122:
/* Line 1787 of yacc.c  */
#line 634 "gpl.y"
    {(yyval.union_operator_type)=ATAN;}
    break;

  case 123:
/* Line 1787 of yacc.c  */
#line 635 "gpl.y"
    {(yyval.union_operator_type)=SQRT;}
    break;

  case 124:
/* Line 1787 of yacc.c  */
#line 636 "gpl.y"
    {(yyval.union_operator_type)=ABS;}
    break;

  case 125:
/* Line 1787 of yacc.c  */
#line 637 "gpl.y"
    {(yyval.union_operator_type)=FLOOR;}
    break;

  case 126:
/* Line 1787 of yacc.c  */
#line 638 "gpl.y"
    {(yyval.union_operator_type)=RANDOM;}
    break;


/* Line 1787 of yacc.c  */
#line 2266 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


