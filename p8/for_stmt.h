#ifndef FOR_STMT_H
#define FOR_STMT_H

#include "statement.h"
#include "expression.h"
#include "statement_block.h"
#include <iostream>

class For_stmt : public Statement{
    public:
        For_stmt(Statement_block*, Expr*, Statement_block*, Statement_block*);
        virtual void execute();

    private:
        Statement_block* m_assign_blk;
        Expr* m_test_ex;
        Statement_block* m_update_blk;
        Statement_block* m_execute;
};

#endif
