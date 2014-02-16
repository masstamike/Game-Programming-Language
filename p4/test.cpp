#include "symbol_table.h"
#include "symbol.h"
#include "string"
#include <iostream>
using namespace std;

int main() {
    Symbol_table* symbol_table = Symbol_table::instance();
    cout<<"Adding symbols to symbol_table\n";
    symbol_table->sym_table["i"] = new Symbol("i",new int(42),"int");
    symbol_table->sym_table["dub"] = new Symbol("dub",new double(2.2),"double");
    symbol_table->sym_table["str"] = 
        new Symbol("str",new string("Hello"),"string");
    
    cout<<"Before print\n";
    symbol_table->print(std::cout);
    cout<<"After print\n";
}
