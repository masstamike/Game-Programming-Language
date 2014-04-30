#ifndef ASSIGN_STMT_H
#define ASSIGN_STMT_H

#include "statement.h"
#include "expression.h"
#include "variable.h"
#include <string>

class Assign_stmt : public Statement{
    public:
        Assign_stmt(Variable*, Expr*);
        Assign_stmt(std::string, std::string, Expr*);
        virtual void execute();

    private:
        Expr* m_expr;
        Variable* m_var;
        std::string m_object, m_member;
        bool game_flag;
};

#endif
