#ifndef PRINT_STMT_H
#define PRINT_STMT_H

#include "statement.h"
#include "expression.h"
#include <iostream>

class Print_stmt : public Statement{
    public:
        Print_stmt(int, Expr*);
        virtual void execute();

    private:
        Expr* m_expr;
};

#endif
