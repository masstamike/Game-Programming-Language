#include "assign_stmt.h"
#include "symbol_table.h"
#include "gpl_type.h"
using namespace std;

Assign_stmt::Assign_stmt(Variable* var, Expr* expr) {
    m_var = var;
    m_expr = expr;
}

Assign_stmt::Assign_stmt(std::string object, std::string member, Expr* expr) {
    game_flag=true;
    m_object = object;
    m_member = member;
    m_expr = expr;
}

void Assign_stmt::execute() {
if(game_flag) {
    Game_object* obj = Symbol_table::instance()->find(m_object)->
        get_game_object_value();
    Gpl_type type;
    obj->get_member_variable_type(m_member, type);
    switch(type){
        case INT:
            Symbol_table::instance()->find(m_object)->get_game_object_value()->
                set_member_variable(m_member, m_expr->eval_int());
            break;
        case DOUBLE:
            Symbol_table::instance()->find(m_object)->get_game_object_value()->
                set_member_variable(m_member, m_expr->eval_double());
            break;
        case STRING:
            Symbol_table::instance()->find(m_object)->get_game_object_value()->
                set_member_variable(m_member, m_expr->eval_string());
            break;
        default:break;
    }
} else {
    if(m_var->m_type == "int")
        m_var->m_sym->m_value=new int(m_expr->eval_int());
    else if (m_var->m_type == "double")
        m_var->m_sym->m_value=new double(m_expr->eval_double());
    else if (m_var->m_type == "string")
        m_var->m_sym->m_value=new string(m_expr->eval_string());
}
}
