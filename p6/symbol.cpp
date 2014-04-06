#include "symbol.h"

Symbol::Symbol(std::string name, void* value, std::string type) {
    m_name = name;
    m_value = value;
    m_type = type;
}

Game_object* Symbol::get_game_object_value() {
    return (Game_object*) m_value;
}
