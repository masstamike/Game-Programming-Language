#include <string>
#include "symbol.h"

#ifndef VARIABLE_H
#define VARIABLE_H

class Variable {
    public:
        Variable(std::string, Symbol*, std::string);

        std::string m_id, m_type;
        Symbol* m_sym;
    private:
};

#endif
