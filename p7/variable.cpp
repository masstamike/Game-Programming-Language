#include "variable.h"
#include <sstream>
#include "symbol_table.h"

Variable::Variable (std::string id, Symbol* sym) {
    m_id = id;
    m_sym = sym;
    m_type = sym->m_type;
    m_expr = NULL;
}

Variable::Variable(std::string id, Expr* expr) {    // array types
    std::stringstream ss;
    m_id = id;
    m_sym = NULL;
    ss<<expr->eval_int();
    std::string object_name = id + "[" + ss.str() + "]";
    m_type = Symbol_table::instance()->find(object_name)->m_type;
    m_expr = expr;
}

Variable::Variable(std::string id, Symbol* sym, std::string member) {
    // member variables
    Gpl_type type;
    m_id = id;
    m_sym = sym;
    m_member = member;
    sym->get_game_object_value()->get_member_variable_type(member, type);
    m_type = gpl_type_to_string(type);
    m_expr = NULL;
}

Variable::Variable(std::string id, Expr* expr, std::string member) {
    // array[expr].member
    Gpl_type type;
    m_id = id;
    m_expr = expr;
    m_member = member;
    m_sym = NULL;
    std::stringstream ss;
    ss<<expr->eval_int();
    std::string object_name = id + "[" + ss.str() + "]";
    Symbol_table::instance()->find(object_name)->
        get_game_object_value()->get_member_variable_type(member, type);
    m_type = gpl_type_to_string(type);
}
