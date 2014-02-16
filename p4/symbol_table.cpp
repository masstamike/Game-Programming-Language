#include "symbol_table.h"

/* static */ Symbol_table *Symbol_table::m_instance = 0;

/* static */ Symbol_table * Symbol_table::instance()
{
  if (m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}

Symbol_table::Symbol_table() {
}

void Symbol_table::print(std::ostream& cout) {
    for (std::map<std::string, Symbol*>::iterator it = sym_table.begin();
        it!=sym_table.end(); it++) {
        cout<<it->second->m_name<<"\n";
    }
}

