/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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

/* Line 2068 of yacc.c  */
#line 54 "gpl.y"

 int            union_int;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 double         union_double;
 Gpl_type       union_variable_type;
 Variable*      union_variable;
 Operator_type  union_operator_type;
 Expr*          union_expr;
 Symbol*        union_symbol;
 Statement*     union_stmt;
 Statement_block*   union_stmt_block;
 



/* Line 2068 of yacc.c  */
#line 248 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


