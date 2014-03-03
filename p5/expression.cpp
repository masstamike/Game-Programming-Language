#include "expression.h"

Expr::Expr(int i) {
    m_int = i;
    type = "integer";
}

Expr::Expr(double d) {
    m_double = d;
    type = "double";
}

Expr::Expr(std::string s) {
    m_str = s;
    type = "string";
}

int Expr::eval_int() {
    return m_int;
}

double Expr::eval_double() {
    return m_double;
}

std::string Expr::eval_string() {
    return m_str;
}

std::string Expr::get_type() {
    return type;
}
