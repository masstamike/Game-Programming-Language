#ifndef IF_STMT_H
#define IF_STMT_H

#include "statement.h"
#include "expression.h"
#include "statement_block.h"
#include <iostream>

class If_stmt : public Statement{
    public:
        If_stmt(Expr*, Statement_block*);
        If_stmt(Expr*, Statement_block*, Statement_block*);
        virtual void execute();

    private:
        Expr* m_expr;
        Statement_block* m_if_blk;
        Statement_block* m_else_blk;
};

#endif
