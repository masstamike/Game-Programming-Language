#include <ostream>
#include <map>
#include "symbol.h"
#include "string"

// class Symbol_table is a singleton
class Symbol_table
{
  public:
    static Symbol_table *instance();
    void print(std::ostream& stream);
    std::map<std::string, Symbol*> sym_table;
  private:
    static Symbol_table *m_instance;

    Symbol_table();

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};
