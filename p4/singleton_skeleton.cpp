// to make a singleton class
//
//   1) start with this file
//   2) replace all the Foo with My_class and
//   3) break it into my_class.h and my_class.cpp at the -------------
//   4) add real code


// class Foo is a singleton
class Foo
{
  public:
    static Foo *instance();
  private:
    static Foo *m_instance;

    Foo() {};

    // disable default copy constructor and default assignment
    // done as a precaution, they should never be called
    Foo(const Foo &);
    const Foo &operator=(const Foo &);

};

---------------------------------------------


/* static */ Foo *Foo::m_instance = 0;

/* static */ Foo * Foo::instance()
{
  if (m_instance == 0)
    m_instance = new Foo();
  return m_instance;
}

