#include "for_stmt.h"

For_stmt::For_stmt(Statement_block* assign_blk, Expr* test_ex,
    Statement_block* update_blk, Statement_block* execute) {
    m_assign_blk = assign_blk;
    m_test_ex = test_ex;
    m_update_blk = update_blk;
    m_execute = execute;
}

void For_stmt::execute() { //placeholder
    for(m_assign_blk->execute(); m_test_ex->eval_int();
        m_update_blk->execute()) {
        m_execute->execute();
    }
}
