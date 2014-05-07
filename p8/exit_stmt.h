#ifndef EXIT_STMT_H
#define EXIT_STMT_H

#include "statement.h"
#include "expression.h"
#include <iostream>

class Exit_stmt : public Statement{
    public:
        Exit_stmt(int, Expr*);
        virtual void execute();

    private:
        Expr* m_expr;
};

#endif
