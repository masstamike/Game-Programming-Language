#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>
#include "game_object.h"

class Symbol {
    public:
        Symbol (std::string, void*, std::string);
        std::string m_name, m_type;
        void* m_value;
        Game_object* get_game_object_value();
};

#endif
