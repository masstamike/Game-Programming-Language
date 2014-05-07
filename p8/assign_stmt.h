#ifndef ASSIGN_STMT_H
#define ASSIGN_STMT_H

#include "statement.h"
#include "expression.h"
#include "variable.h"
#include <string>

class Assign_stmt : public Statement{
    public:
        Assign_stmt(Variable*, Expr*, int);
        virtual void execute();

    private:
        Expr* m_expr;
        Variable* m_var;
        int assign_type;
};

#endif
