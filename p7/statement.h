#ifndef STATEMENT_H
#define STATEMENT_H

/*
 * Base class for all Statements, has pure virtual function void execute()
 */

class Statement
{
    public:
        Statement();
        ~Statement();
        virtual void execute()=0;
    protected:
        int m_line;
};

#endif
