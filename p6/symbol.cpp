#include "symbol.h"

Symbol::Symbol(std::string name, void* value, std::string type) {
    m_name = name;
    m_value = value;
    m_type = type;
}
