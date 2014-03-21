#include <string>
#include "gpl_type.h"
#include "variable.h"
#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expr {
    public:
        Expr(int i);//int constructor
        Expr(double d);//double constructor
        Expr(std::string s);//string constructor
        Expr(Operator_type, Expr*, Expr*);
        Expr(Operator_type, Expr*);
        Expr(Variable*);
//        Expr();
        ~Expr();
        int eval_int();
        double eval_double();
        std::string eval_string();
        std::string get_type();
        std::string get_kind() {return m_kind;}
        Expr *m_left, *m_right;
        Operator_type m_op;
        
    private:
        int m_int;
        double m_double;
        Variable* m_var;
        std::string m_str;
        std::string type;
        std::string m_kind;
};

#endif
