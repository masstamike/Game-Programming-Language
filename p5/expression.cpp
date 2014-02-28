#include "expression.h"

Expr::Expr(int i) {
    m_int = i;
    type = "integer";
}

Expr::Expr(double d) {
    m_double = d;
    type = "double";
}

Expr::Expr(string s) {
    m_str = s;
    type = "string";
}
