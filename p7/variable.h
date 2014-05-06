#ifndef VARIABLE_H
#define VARIABLE_H

#include <string>
#include "symbol.h"
#include "expression.h"

class Expr;

class Variable {
    public:
        Variable(std::string, Symbol*);          // this is the old constructor
        Variable(std::string, Expr*);                // array types
        Variable(std::string, Symbol*, std::string); // member variables
        Variable(std::string, Expr*, std::string);   // array[expr].member
        std::string m_id, m_type, m_member; 
        Symbol* m_sym;
        Expr* m_expr;
    private:
};

#endif
