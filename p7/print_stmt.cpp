#include "print_stmt.h"
using namespace std;

Print_stmt::Print_stmt(int line, Expr* expr) {
    m_line = line;
    m_expr = expr;
}

void Print_stmt::execute() {
    cout<<"gpl["<<m_line<<"]: "<<m_expr->eval_string()<<endl;
}
