#include "print_stmt.h"
using namespace std;

Print_stmt::Print_stmt(int line, Expr* expr) {
    m_line = line;
    m_expr = expr;
}

void Print_stmt::execute() {
    if(m_expr->get_type() == "int") {
        int i = m_expr->eval_int();
        cout<<"gpl["<<m_line<<"]: "<<i<<endl;
    } else if(m_expr->get_type() == "double") {
        double d = m_expr->eval_double();
        cout<<"gpl["<<m_line<<"]: "<<d<<endl;
    } else if(m_expr->get_type() == "string") {
        std::string s = m_expr->eval_string();
        cout<<"gpl["<<m_line<<"]: "<<s<<endl;
    }
}
