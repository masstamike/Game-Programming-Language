#include "animation_block.h"
#include "indent.h"
#include "gpl_assert.h"
#include "symbol.h"
using namespace std;

Animation_block::Animation_block(int forward_line, 
                                 Symbol *parameter, string name) 
                                 : Statement_block(-1)
{
    // m_forward_line is only used for debuggin
    m_forward_line = forward_line;
    m_name = name;
    tagged = false;

    // should do some error checking on parameter
    m_parameter_symbol = parameter;

}

void 
Animation_block::execute(Game_object *argument)
{
    Symbol* old_parameter_symbol = m_parameter_symbol;
    m_parameter_symbol->m_value = argument;
    Statement_block::execute();
    m_parameter_symbol = old_parameter_symbol;
}

void Animation_block::tag() {
    tagged = true;
}

bool Animation_block::is_tagged() {
    return tagged;
}

ostream &
Animation_block::print(ostream &os) const
{
    os << indent << "Animation_block[" << m_line;
    
    os << "]" << endl
       << indent << "{" << endl;
    indent++;
    os << indent << "animation block not implemented yet" << endl;
    indent--;
    os << indent << "}";
    return os;
}

ostream &
operator<<(ostream &os, const Animation_block &animation_block)
{
    return animation_block.print(os);
}

ostream &
operator<<(ostream &os, const Animation_block *animation_block)
{
    if (!animation_block)
    {
        os << indent << "NULL";
        return os;
    }

    return animation_block->print(os);
}
