#ifndef EXPRESSION_H
#define EXPRESSION_H
#include <string>

class Expr {
    public:
        Expr(int i);//int constructor
        Expr(double d);//double constructor
        Expr(string s);//string constructor
        Expr();
        Expr();
        Expr();
        Expr* m_left, m_right;
        string type;
        
    private:
        int m_int;
        double m_double;
        string m_str;
};

#endif
