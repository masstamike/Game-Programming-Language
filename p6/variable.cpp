#include "variable.h"

Variable::Variable (std::string id, Symbol* sym, std::string type) {
    m_id = id;
    m_sym = sym;
    m_type = type;
}
