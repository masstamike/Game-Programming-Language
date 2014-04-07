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
        stream<<it->second->m_type<<' '<<it->first;
        if(it->second->m_type == "int")
            stream<<' '<<*(int*)it->second->m_value<<'\n';
        else if(it->second->m_type == "double")
            stream<<' '<<*(double*)it->second->m_value<<'\n';
        else if(it->second->m_type == "string")
            stream<<' '<<"\""<<*(std::string*)it->second->m_value<<"\"\n";
        else {
            stream<<'\n';
            stream<<it->second->get_game_object_value();
            stream<<"\n";
        }
        

    }
}

void Symbol_table::add(std::string name, Symbol* sym) {
    sym_table[name] = sym;
}

Symbol* Symbol_table::find(std::string s) {
    std::map<std::string, Symbol*>::iterator it = sym_table.find(s);
    if(it == sym_table.end())
        return NULL;
    return it->second;
}

void Symbol_table::set(std::string s, int x) {
    Symbol* sym = find(s);
    if(sym)
        sym->m_value = &x;
}

bool Symbol_table::get_type(std::string s, Gpl_type& type) {
    Symbol* sym = find(s);
    if (sym) {
       std::string s_type = sym->m_type;
        if (s_type == "int")
            type = INT;
        else if (s_type == "double")
            type = DOUBLE;
        else if (s_type == "string")
            type = STRING;
        else if (s_type == "game_object")
            type = GAME_OBJECT;
        else if (s_type == "animation_block")
            type = ANIMATION_BLOCK;
        return true;
    }
    else
        return false;
}

void Symbol_table::get(std::string s, int& i) {
    Symbol* sym = find(s);
    if (sym->m_type == "int") {
        i = *((int*) sym->m_value);
    }
}

void Symbol_table::get(std::string s, double& d) {
    Symbol* sym = find(s);
    if (sym->m_type == "double") {
        d = *((double*) sym->m_value);
    }
}

void Symbol_table::get(std::string s, std::string& ret) {
    Symbol* sym = find(s);
    if (sym->m_type == "string") {
        ret = *((std::string*) sym->m_value);
    }
}
