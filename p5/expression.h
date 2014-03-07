#include <string>
#ifndef EXPRESSION_H
#define EXPRESSION_H

class Expr {
    public:
        Expr(int i);//int constructor
        Expr(double d);//double constructor
        Expr(std::string s);//string constructor
//        Expr();
//        Expr();
//        Expr();
        ~Expr();
        int eval_int();
        double eval_double();
        std::string eval_string();
        std::string get_type();
        Expr *m_left, *m_right;
        
    private:
        int m_int;
        double m_double;
        std::string m_str;
        std::string type;
};

#endif
