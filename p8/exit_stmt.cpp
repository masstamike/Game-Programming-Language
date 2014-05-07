#include "exit_stmt.h"
using namespace std;

Exit_stmt::Exit_stmt(int line, Expr* expr) {
    m_line = line;
    m_expr = expr;
}

void Exit_stmt::execute() {
    cout<<"gpl["<<m_line<<"]: exit("<<m_expr->eval_int()<<")"<<endl;
    exit(m_expr->eval_int());
}
