%{
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
//#include <map>
using namespace std;

vector<int> *int_vector;
Symbol_table* symbol_table = Symbol_table::instance();
%}

// Bison fundamentally works by asking flex to get the next token, which it
// returns as an object of type "yystype".  But tokens could be of any
// arbitrary data type!  So we deal with that in Bison by defining a C union
// holding each of the types of tokens that Flex could return, and have Bison
// use that union instead of "int" for the definition of "yystype":

%union {
 int            union_int;
 std::string    *union_string;  // MUST be a pointer to a string (this sucks!)
 double         union_double;
 Gpl_type       union_variable_type;
 Variable*       union_variable;
 Operator_type  union_operator_type;
 Expr*          union_expr;
}
// Precedence Levels:
%left T_OR
%left T_AND
%left T_EQUAL T_NOT_EQUAL
%left T_LESS T_GREATER T_GREATER_EQUAL T_LESS_EQUAL
%left T_MINUS T_PLUS
%left T_ASTERISK T_DIVIDE T_MOD
%nonassoc UNARY_OPS T_NOT
%nonassoc T_PLUS_PLUS T_MINUS_MINUS
%right T_ASSIGN
%nonassoc IF_NO_ELSE
%nonassoc T_ELSE


// define the constant-string tokens:
%token <union_string> T_INT
%token T_DOUBLE
%token T_STRING
%token T_TRIANGLE
%token T_PIXMAP
%token T_CIRCLE
%token T_RECTANGLE
%token T_TEXTBOX
%token T_FORWARD
%token T_INITIALIZATION

%token T_TRUE
%token T_FALSE

%token T_ON
%token T_SPACE
%token T_LEFTARROW
%token T_RIGHTARROW
%token T_UPARROW
%token T_DOWNARROW
%token T_LEFTMOUSE_DOWN
%token T_MIDDLEMOUSE_DOWN
%token T_RIGHTMOUSE_DOWN
%token T_LEFTMOUSE_UP
%token T_MIDDLEMOUSE_UP
%token T_RIGHTMOUSE_UP
%token T_MOUSE_MOVE
%token T_MOUSE_DRAG

%token T_F1
%token T_AKEY
%token T_SKEY
%token T_DKEY
%token T_FKEY
%token T_HKEY
%token T_JKEY
%token T_KKEY
%token T_LKEY
%token T_WKEY

%token T_TOUCHES
%token T_NEAR

%token T_ANIMATION

%token T_IF
%token T_FOR
%token T_ELSE

%token T_EXIT
//%token T_PRINT

%token T_LPAREN
%token T_RPAREN
%token T_LBRACE
%token T_RBRACE
%token T_LBRACKET
%token T_RBRACKET
%token T_SEMIC
%token T_COMMA
%token T_PERIOD

%token T_ASSIGN
%token T_PLUS_ASSIGN
%token T_MINUS_ASSIGN
%token T_PLUS_PLUS
%token T_MINUS_MINUS

%token T_ASTERISK
%token T_DIVIDE
%token T_MOD
%token T_PLUS
%token T_MINUS
%token T_SIN
%token T_COS
%token T_TAN
%token T_ASIN
%token T_ACOS
%token T_ATAN
%token T_SQRT
%token T_FLOOR
%token T_ABS
%token T_RANDOM

%token T_LESS
%token T_GREATER
%token T_LESS_EQUAL
%token T_GREATER_EQUAL
%token T_EQUAL
%token T_NOT_EQUAL

%token T_AND
%token T_OR
%token T_NOT

// the following need a type
// %token <type goes here> TOKEN
%token <union_string> T_ID
%token <union_int> T_INT_CONSTANT
%token <union_double> T_DOUBLE_CONSTANT
%token <union_string> T_STRING_CONSTANT
%token <union_int> T_PRINT
%type <union_expr> optional_initializer
%type <union_expr> primary_expression
%type <union_variable_type> simple_type
%type <union_expr> expression
%type <union_variable> variable
%type <union_operator_type> math_operator

// special token that does not match any production
// used for characters that are not part of the language
%token T_ERROR

%%

// the first rule defined is the highest-level rule, which in our
// case is just the concept of a whole "gpl program":
//----------------------------------------------------------------------------
//---------------------------------------------------------------------
program:
    declaration_list block_list
    ;

//---------------------------------------------------------------------
declaration_list:
    declaration_list declaration
    | empty
    ;

//---------------------------------------------------------------------
declaration:
    variable_declaration T_SEMIC
    | object_declaration T_SEMIC
    | forward_declaration T_SEMIC
    ;

//---------------------------------------------------------------------
variable_declaration:
    simple_type  T_ID  optional_initializer
    {
        string array = *$2;
        array = array + "[0]";
        if(symbol_table->find(*$2) || symbol_table->find(array)){
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE,
                *$2);
        }
        if($3 && ($3->get_kind()=="constant" || $3->get_kind()=="variable") &&
             ($3->get_type()!=gpl_type_to_string($1)) && $1!=STRING) {
            if(!($1==DOUBLE && $3->get_type()=="int"))
                Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*$2);
        }
        else if($3 && $1==INT && $3->get_type()!="int")
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*$2);
        else if($3 && $1==DOUBLE && $3->get_type()=="string")
            Error::error(Error::INVALID_TYPE_FOR_INITIAL_VALUE,*$2);
        if($1 == INT)
            symbol_table->add(*$2, new Symbol(*$2,new int($3?$3->eval_int():
                0),"int"));
        else if($1 == DOUBLE)
            symbol_table->add(*$2, new Symbol(*$2,new double($3?
                $3->eval_double():0.0),"double"));
        else if($1 == STRING) {
            stringstream ss;
            if(!$3)
                ss << "";
            else if($3->get_type() == "int") {
                ss << $3->eval_int();}
            else if($3->get_type() == "double")
                ss << $3->eval_double();
            else
                ss << $3->eval_string();
            symbol_table->add(*$2, new Symbol(*$2,
            new string(ss.str()),
            "string"));
        }
    }
    | simple_type  T_ID  T_LBRACKET expression T_RBRACKET {
        string array = *$2;
        array = array + "[0]";
        if(symbol_table->find(*$2) || symbol_table->find(array)){
            Error::error(Error::PREVIOUSLY_DECLARED_VARIABLE,
                *$2);
        }
        if($4->get_type()=="int" && $4->eval_int() <1) {
            if($4->get_type() == "int") {
                stringstream ss;
                ss<<$4->eval_int();
                Error::error(Error::INVALID_ARRAY_SIZE,*$2,ss.str());
            } else if($4->get_type() == "double") {
                stringstream ss;
                ss<<$4->eval_double();
                Error::error(Error::INVALID_ARRAY_SIZE,*$2,ss.str());
            } else if($4->get_type() == "string") {
                Error::error(Error::INVALID_ARRAY_SIZE,*$2,$4->eval_string());
            }
        }
        if($4->get_type() != "int") {
            Error::error(Error::INVALID_ARRAY_SIZE,*$2,$4->eval_string());
        }
        for (int x = 0; x<$4->eval_int(); x++) {
            string name = *$2;
            std::stringstream out;
            out<<x;
            name = name + '['+out.str()+']';
            if($1 == INT)
                symbol_table->add(name, new Symbol(*$2,new int(0),"int"));
            else if($1 == DOUBLE)
                symbol_table->add(name, new Symbol(*$2,new double(0.0),
                "double"));
            else if($1 == STRING)
                symbol_table->add(name, new Symbol(*$2,
                new string(""),
                "string"));
    }
    }
    ;

//---------------------------------------------------------------------
simple_type:
    T_INT{$$=INT;}
    | T_DOUBLE {$$=DOUBLE;}
    | T_STRING {$$=STRING;}
    ;

//---------------------------------------------------------------------
optional_initializer:
    T_ASSIGN expression {
        $$=$2;
    }
    | empty{$$=NULL;}
    ;

//---------------------------------------------------------------------
object_declaration:
    object_type T_ID T_LPAREN parameter_list_or_empty T_RPAREN
    | object_type T_ID T_LBRACKET expression T_RBRACKET
    ;

//---------------------------------------------------------------------
object_type:
    T_TRIANGLE
    | T_PIXMAP
    | T_CIRCLE
    | T_RECTANGLE
    | T_TEXTBOX
    ;

//---------------------------------------------------------------------
parameter_list_or_empty :
    parameter_list
    | empty
    ;

//---------------------------------------------------------------------
parameter_list :
    parameter_list T_COMMA parameter
    | parameter
    ;

//---------------------------------------------------------------------
parameter:
    T_ID T_ASSIGN expression
    ;

//---------------------------------------------------------------------
forward_declaration:
    T_FORWARD T_ANIMATION T_ID T_LPAREN animation_parameter T_RPAREN
    ;

//---------------------------------------------------------------------
block_list:
    block_list block
    | empty
    ;

//---------------------------------------------------------------------
block:
    initialization_block
    | animation_block
    | on_block
    ;

//---------------------------------------------------------------------
initialization_block:
    T_INITIALIZATION statement_block
    ;

//---------------------------------------------------------------------
animation_block:
    T_ANIMATION T_ID T_LPAREN check_animation_parameter T_RPAREN T_LBRACE { } statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
animation_parameter:
    object_type T_ID
    ;

//---------------------------------------------------------------------
check_animation_parameter:
    T_TRIANGLE T_ID
    | T_PIXMAP T_ID
    | T_CIRCLE T_ID
    | T_RECTANGLE T_ID
    | T_TEXTBOX T_ID
    ;

//---------------------------------------------------------------------
on_block:
    T_ON keystroke statement_block
    ;

//---------------------------------------------------------------------
keystroke:
    T_SPACE
    | T_UPARROW
    | T_DOWNARROW
    | T_LEFTARROW
    | T_RIGHTARROW
    | T_LEFTMOUSE_DOWN
    | T_MIDDLEMOUSE_DOWN
    | T_RIGHTMOUSE_DOWN
    | T_LEFTMOUSE_UP
    | T_MIDDLEMOUSE_UP
    | T_RIGHTMOUSE_UP
    | T_MOUSE_MOVE
    | T_MOUSE_DRAG
    | T_AKEY 
    | T_SKEY 
    | T_DKEY 
    | T_FKEY 
    | T_HKEY 
    | T_JKEY 
    | T_KKEY 
    | T_LKEY 
    | T_WKEY 
    | T_F1
    ;

//---------------------------------------------------------------------
if_block:
    statement_block_creator statement end_of_statement_block
    | statement_block
    ;

//---------------------------------------------------------------------
statement_block:
    T_LBRACE statement_block_creator statement_list T_RBRACE end_of_statement_block
    ;

//---------------------------------------------------------------------
statement_block_creator:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
end_of_statement_block:
    // this goes to nothing so that you can put an action here in p7
    ;

//---------------------------------------------------------------------
statement_list:
    statement_list statement
    | empty
    ;

//---------------------------------------------------------------------
statement:
    if_statement
    | for_statement
    | assign_statement T_SEMIC
    | print_statement T_SEMIC
    | exit_statement T_SEMIC
    ;

//---------------------------------------------------------------------
if_statement:
    T_IF T_LPAREN expression T_RPAREN if_block %prec IF_NO_ELSE
    | T_IF T_LPAREN expression T_RPAREN if_block T_ELSE if_block
    ;

//---------------------------------------------------------------------
for_statement:
    T_FOR T_LPAREN statement_block_creator assign_statement end_of_statement_block T_SEMIC expression T_SEMIC statement_block_creator assign_statement end_of_statement_block T_RPAREN statement_block
    ;

//---------------------------------------------------------------------
print_statement:
    T_PRINT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
exit_statement:
    T_EXIT T_LPAREN expression T_RPAREN
    ;

//---------------------------------------------------------------------
assign_statement:
    variable T_ASSIGN expression
    | variable T_PLUS_ASSIGN expression
    | variable T_MINUS_ASSIGN expression
    ;

//---------------------------------------------------------------------
variable:
    T_ID {
        Symbol* var = symbol_table->find(*$1);
        if(var) {
            if(var->m_type == "int")
                $$=new Variable(*$1,var,"int");
            else if(var->m_type == "double")
                $$=new Variable(*$1,var,"double");
            else if(var->m_type == "string")
                $$=new Variable(*$1,var,"string");
        } else {
            Error::error(Error::UNDECLARED_VARIABLE,*$1);
            $$=NULL;
        }
    }
    | T_ID T_LBRACKET expression T_RBRACKET {
        if($3->get_type() !=  "int") {
            string s2=$3->get_type();
            s2="A "+s2+" expression";
            Error::error(Error::ARRAY_INDEX_MUST_BE_AN_INTEGER,*$1,s2);
            $$=NULL;
        }
        string array = *$1;
        int index = $3->eval_int();
        stringstream ss;
        ss<<index;
        array = array + "[" + ss.str() + "]";
        Symbol* sym = symbol_table->find(array);
        if(sym) {
            if(sym->m_type == "int")
                $$=new Variable(*$1,sym,"int");
            else if(sym->m_type == "double")
                $$=new Variable(*$1,sym,"double");
            else if(sym->m_type == "string")
                $$=new Variable(*$1,sym,"string");
        } else {
            stringstream ss;
            ss<<$3->eval_int();
            Error::error(Error::ARRAY_INDEX_OUT_OF_BOUNDS,*$1,ss.str());
            $$=NULL;
        }
    }
    | T_ID T_PERIOD T_ID
    | T_ID T_LBRACKET expression T_RBRACKET T_PERIOD T_ID
    ;

//---------------------------------------------------------------------
expression:
    primary_expression {$$=$1;}
    | expression T_OR expression
    {
        if($1->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"||");
        else if($3->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"||");
        else
            $$=new Expr(OR, $1, $3);
    }
    | expression T_AND expression
    {
        if($1->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"&&");
        else if($3->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"&&");
        else
            $$=new Expr(AND, $1, $3);
    }
    | expression T_LESS_EQUAL expression {$$=new Expr(LESS_THAN_EQUAL,$1,$3);}
    | expression T_GREATER_EQUAL  expression {
        $$=new Expr(GREATER_THAN_EQUAL,$1,$3);
    }
    | expression T_LESS expression {$$=new Expr(LESS_THAN, $1, $3);}
    | expression T_GREATER  expression {$$=new Expr(GREATER_THAN,$1,$3);}
    | expression T_EQUAL expression {
        $$=new Expr(EQUAL, $1, $3);
    }
    | expression T_NOT_EQUAL expression {$$=new Expr(NOT_EQUAL,$1,$3);}
    | expression T_PLUS expression {
        $$=new Expr(PLUS, $1, $3);
    }
    | expression T_MINUS expression {
        if($1->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"-");
        else if($3->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"-");
        else
            $$=new Expr(MINUS, $1, $3);
    }
    | expression T_ASTERISK expression {
        if($1->get_type()=="string")
            Error::error(Error::INVALID_LEFT_OPERAND_TYPE,"*");
        else if($3->get_type()=="string")
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"*");
        else
            $$=new Expr(MULTIPLY, $1, $3);
    }
    | expression T_DIVIDE expression {
        if($1->get_type() == "string" || $3->get_type() == "string");
            //error
        else
            $$=new Expr(DIVIDE, $1, $3);
    }
    | expression T_MOD expression {$$=new Expr(MOD,$1,$3);}
    | T_MINUS  expression %prec UNARY_OPS {
        $$=new Expr(UNARY_MINUS, $2);
    }
    | T_NOT expression {
        $$=new Expr(NOT, $2);
    }
    | math_operator T_LPAREN expression T_RPAREN {
        if($1==SQRT && $3->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"sqrt");
            $$=new Expr(0);
        } else if($1==ABS && $3->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"abs");
            $$=new Expr(0);
        } else if($1==FLOOR && $3->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"floor");
            $$=new Expr(0);
        } else if($1==RANDOM && $3->get_type()=="string") {
            Error::error(Error::INVALID_RIGHT_OPERAND_TYPE,"random");
            $$=new Expr(0);
        }
        if($3->get_type()=="int" || $3->get_type()=="double")
            $$=new Expr($1,$3);
//        else
            //error
    }
    | variable geometric_operator variable
    ;

//---------------------------------------------------------------------
primary_expression:
    T_LPAREN  expression T_RPAREN {
        $$=$2;
    }
    | variable {
        if($1)
            $$ = new Expr($1);
        else
            $$=new Expr(0);
    }
    | T_INT_CONSTANT {
        $$=new Expr($1);
    }
    | T_TRUE {
        $$=new Expr(1);
    }
    | T_FALSE {
        $$=new Expr(0);
    }
    | T_DOUBLE_CONSTANT {
        $$=new Expr($1);
    }
    | T_STRING_CONSTANT {
        $$=new Expr(*$1);
    }
    ;

//---------------------------------------------------------------------
geometric_operator:
    T_TOUCHES
    | T_NEAR
    ;

//---------------------------------------------------------------------
math_operator:
    T_SIN{$$=SIN;}
    | T_COS{$$=COS;}
    | T_TAN{$$=TAN;}
    | T_ASIN{$$=ASIN;}
    | T_ACOS{$$=ACOS;}
    | T_ATAN{$$=ATAN;}
    | T_SQRT{$$=SQRT;}
    | T_ABS{$$=ABS;}
    | T_FLOOR{$$=FLOOR;}
    | T_RANDOM{$$=RANDOM;}
    ;

//---------------------------------------------------------------------
empty:
    // empty goes to nothing so that you can use empty in productions
    // when you want a production to go to nothing
    ;
