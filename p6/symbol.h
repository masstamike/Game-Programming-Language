#ifndef SYMBOL_H
#define SYMBOL_H
#include <string>

class Symbol {
    public:
        Symbol (std::string, void*, std::string);
        std::string m_name, m_type;
        void* m_value;
};

#endif
