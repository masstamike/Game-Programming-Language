%{
#include "error.h"
//#include "gpl_assert.h"
//#include "indent.h"
#include "parser.h"
#include <iostream>
#include "expression.h"
using namespace std;
//#define YY_DECL extern "C" int yylex()
int line_count=1;

int emit_string(int token) {
    yylval.union_string = new string(yytext);

    return token;
}

int emit_int(int token) {
    yylval.union_int = atoi(yytext);
    return token;
}

int emit_double(int token) {
    yylval.union_double = atof(yytext);
    return token;
}

int emit_with_line_number(int token) {
    yylval.union_int = line_count;
    return token;
}

%}
%%
int                     return T_INT;
double                  return T_DOUBLE;
string                  return T_STRING;
triangle                return T_TRIANGLE;
pixmap                  return T_PIXMAP;
circle                  return T_CIRCLE;
rectangle               return T_RECTANGLE;
textbox                 return T_TEXTBOX;

 /*keywords*/

forward                 return emit_string(T_FORWARD);
initialization          return emit_string(T_INITIALIZATION);
on                      return emit_string(T_ON);
animation               return emit_string(T_ANIMATION);
if                      return emit_string(T_IF);
for                     return emit_string(T_FOR);
else                    return emit_string(T_ELSE);
exit                    return emit_string(T_EXIT);
print                   return emit_with_line_number(T_PRINT);
true                    return emit_string(T_TRUE);
false                   return emit_string(T_FALSE);

 /*event keys*/
space                   return emit_string(T_SPACE);
leftarrow               return emit_string(T_LEFTARROW);
rightarrow              return emit_string(T_RIGHTARROW);
uparrow                 return emit_string(T_UPARROW);
downarrow               return emit_string(T_DOWNARROW);
leftmouse_down          return emit_string(T_LEFTMOUSE_DOWN);
middlemouse_down        return emit_string(T_MIDDLEMOUSE_DOWN);
rightmouse_down         return emit_string(T_RIGHTMOUSE_DOWN);
leftmouse_up            return emit_string(T_LEFTMOUSE_UP);
middlemouse_up          return emit_string(T_MIDDLEMOUSE_UP);
rightmouse_up           return emit_string(T_RIGHTMOUSE_UP);
mouse_move              return emit_string(T_MOUSE_MOVE);
mouse_drag              return emit_string(T_MOUSE_DRAG);
f1                      return emit_string(T_F1);
akey                    return emit_string(T_AKEY);
skey                    return emit_string(T_SKEY);
dkey                    return emit_string(T_DKEY);
fkey                    return emit_string(T_FKEY);
hkey                    return emit_string(T_HKEY);
jkey                    return emit_string(T_JKEY);
kkey                    return emit_string(T_KKEY);
lkey                    return emit_string(T_LKEY);
wkey                    return emit_string(T_WKEY);

 /*punctuation*/
"("                     return T_LPAREN;
")"                     return T_RPAREN;
"{"                     return T_LBRACE;
"}"                     return T_RBRACE;
"["                     return T_LBRACKET;
"]"                     return T_RBRACKET;
";"                     return T_SEMIC;
","                     return T_COMMA;
"."                     return T_PERIOD;

 /* assignment operators*/
 /* unlike C/C++/Java, assignment operators are NOT part of expressions
  * thus they don't need to be assigned a precedence level*/
"="                     return T_ASSIGN;
"+="                    return T_PLUS_ASSIGN;
"-="                    return T_MINUS_ASSIGN;

 /*unary operators with textual names*/
 /* these "fake" functions are in the grammar in such a way
  * that they do not need to be assigned a precedence level
  */
sin                     return emit_string(T_SIN);
cos                     return emit_string(T_COS);
tan                     return emit_string(T_TAN);
asin                    return emit_string(T_ASIN);
acos                    return emit_string(T_ACOS);
atan                    return emit_string(T_ATAN);
sqrt                    return emit_string(T_SQRT);
abs                     return emit_string(T_ABS);
floor                   return emit_string(T_FLOOR);
random                  return emit_string(T_RANDOM);

 /*graphical operators*/
 /* these binary operators are in the grammar in such a way that
  * they don't need a precedence level */
touches                 return emit_string(T_TOUCHES);
near                    return emit_string(T_NEAR);

 /* mathematical operators */
\*                      return emit_string(T_ASTERISK);
\/                      return emit_string(T_DIVIDE);
\+                      return emit_string(T_PLUS);
\-                      return emit_string(T_MINUS);
\%                      return emit_string(T_MOD);

 /*logical operators*/
\<                      return emit_string(T_LESS);
\>                      return emit_string(T_GREATER);
\<\=                    return emit_string(T_LESS_EQUAL);
\>\=                    return emit_string(T_GREATER_EQUAL);
\=\=                    return emit_string(T_EQUAL);
\!\=                    return emit_string(T_NOT_EQUAL);
\!                      return emit_string(T_NOT);
\&\&                    return emit_string(T_AND);
\|\|                    return emit_string(T_OR);

[\t]                    ;
\n                      line_count++;
\/\/.*                  ;
[0-9]+                  return emit_int(T_INT_CONSTANT);
[0-9]*\.[0-9]+|[0-9]+\. return emit_double(T_DOUBLE_CONSTANT);
[a-zA-Z_]+[a-zA-Z0-9_]* return emit_string(T_ID);
\"[^\"]+\"              return emit_string(T_STRING_CONSTANT);
.                       ;
%%
