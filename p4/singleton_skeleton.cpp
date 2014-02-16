// to make a singleton class
//
//   1) start with this file
//   2) replace all the Symbol_table with My_class and
//   3) break it into my_class.h and my_class.cpp at the -------------
//   4) add real code


// class Symbol_table is a singleton
class Symbol_table
{
  public:
    static Symbol_table *instance();
  private:
    static Symbol_table *m_instance;

    Symbol_table() {};

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Symbol_table(const Symbol_table &);
    const Symbol_table &operator=(const Symbol_table &);

};

---------------------------------------------


/* static */ Symbol_table *Symbol_table::m_instance = 0;

/* static */ Symbol_table * Symbol_table::instance()
{
  if (m_instance == 0)
    m_instance = new Symbol_table();
  return m_instance;
}

