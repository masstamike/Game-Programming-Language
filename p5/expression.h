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
        int eval_int();
        Expr *m_left, *m_right;
        std::string type;
        
    private:
        int m_int;
        double m_double;
        std::string m_str;
};

#endif
