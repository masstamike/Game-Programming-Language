#include <ostream>
#include <map>
#include "symbol.h"
#include "string"
#include "game_object.h"
//using namespace std;

// class Symbol_table is a singleton
class Symbol_table
{
  public:
    static Symbol_table *instance();
    void print(std::ostream& stream);
    void add(std::string, Symbol*);
    Symbol* find(std::string);
    void set(std::string, int);
  private:
    std::map<std::string, Symbol*> sym_table;
    static Symbol_table *m_instance;

    Symbol_table();

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};
