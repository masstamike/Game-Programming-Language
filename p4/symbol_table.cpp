#include "symbol_table.h"

/* static */ Symbol_table *Symbol_table::m_instance = 0;

/* static */ Symbol_table * Symbol_table::instance()
{
  if (m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}

Symbol_table::Symbol_table() {
//    sym_table["test"] = new Symbol("test", new int(42), "int");
}

//void Symbol_table::add(string name, void* value, string type) {}

void Symbol_table::print(std::ostream& stream) {
    for (std::map<std::string, Symbol*>::iterator it = sym_table.begin();
        it!=sym_table.end(); it++) {

//        stream<<it->second->m_name<<" "<<*(int*)it->second->m_value<<"\n";
        stream<<it->second->m_type<<' '<<it->first<<' ';
        if(it->second->m_type == "int")
            stream<<*(int*)it->second->m_value<<'\n';
        else if(it->second->m_type == "double")
            stream<<*(double*)it->second->m_value<<'\n';
        else if(it->second->m_type == "string")
            stream<<*(std::string*)it->second->m_value<<'\n';

    }
}

void Symbol_table::add(std::string name, Symbol* sym) {
    sym_table[name] = sym;
}
