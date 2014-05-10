#ifndef EXPRESSION_H
#define EXPRESSION_H

#include <string>
#include "gpl_type.h"
#include "variable.h"
#include "animation_block.h"

class Variable;

class Expr {
    public:
        Expr(int i);//int constructor
        Expr(double d);//double constructor
        Expr(std::string s);//string constructor
        Expr(Operator_type, Expr*, Expr*);
        Expr(Operator_type, Expr*);
        Expr(Variable*, Variable*, std::string);
//        Expr(Variable*, bool);
        Expr(Variable*);
        Expr(Animation_block*);
        ~Expr();
        int eval_int();
        double eval_double();
        std::string eval_string();
        Animation_block* eval_animation_block();
        std::string get_type();
        std::string get_kind() {return m_kind;}
        Expr *m_left, *m_right;
        Operator_type m_op;
        
    private:
        bool m_game_object;
        int m_int;
        double m_double;
        Variable* m_var;
        Animation_block* m_animation;
        std::string m_str;
        std::string type;
        std::string m_kind;
};

#endif
