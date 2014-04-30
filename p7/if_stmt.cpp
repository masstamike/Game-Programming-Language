#include "if_stmt.h"

If_stmt::If_stmt(Expr* expr, Statement_block* if_blk) {
    m_expr = expr;
    m_if_blk = if_blk;
    m_else_blk = NULL;
}

If_stmt::If_stmt(Expr* expr, Statement_block* if_blk,
    Statement_block* else_blk) {
    m_expr = expr;
    m_if_blk = if_blk;
    m_else_blk = else_blk;
}

void If_stmt::execute() {
    if(m_expr->eval_int())
        m_if_blk->execute();
    else if(m_else_blk)
        m_else_blk->execute();
        
}
