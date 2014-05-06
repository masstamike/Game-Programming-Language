#include "assign_stmt.h"
#include "symbol_table.h"
#include "gpl_type.h"
#include "error.h"
using namespace std;

Assign_stmt::Assign_stmt(Variable* var, Expr* expr, int type) {
    m_var = var;
    m_expr = expr;
    game_flag=false;
    assign_type = type;
}

Assign_stmt::Assign_stmt(std::string object, std::string member, Expr* expr,
    int type) {
    game_flag=true;
    m_var = NULL;
    m_object = object;
    m_member = member;
    m_expr = expr;
    assign_type = type;
}

void Assign_stmt::execute() {
if(game_flag) {
    Game_object* obj = Symbol_table::instance()->find(m_object)->
        get_game_object_value();
    Gpl_type type;
    obj->get_member_variable_type(m_member, type);
    switch(type){
        case INT: {
            int previous;
            obj->get_member_variable(m_member, previous);
            switch(assign_type) {
                case 0:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        m_expr->eval_int());
                    break;
                case 1:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        m_expr->eval_int()+previous);
                    break;
                case 2:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        previous-m_expr->eval_int());
                    break;
            }
            break;
        }
        case DOUBLE: {
            double previous;
            obj->get_member_variable(m_member, previous);
            switch(assign_type) {
                case 0:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        m_expr->eval_double());
                    break;
                case 1:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        m_expr->eval_double()+previous);
                    break;
                case 2:
                    Symbol_table::instance()->find(m_object)->
                        get_game_object_value()->set_member_variable(m_member,
                        previous-m_expr->eval_double());
                    break;
            }
            break;
        }
        case STRING:
            Symbol_table::instance()->find(m_object)->get_game_object_value()->
                set_member_variable(m_member, m_expr->eval_string());
            break;
        default:break;
    }
} else {
    if(m_var->m_type == "int") {
        int previous;
        previous = *(int*) m_var->m_sym->m_value;
        switch(assign_type) {
            case 0:
                m_var->m_sym->m_value=new int(m_expr->eval_int());
                break;
            case 1:
                m_var->m_sym->m_value=new int(previous+m_expr->eval_int());
                break;
            case 2:
                m_var->m_sym->m_value=new int(previous-m_expr->eval_int());
                break;
        }
    }
    else if (m_var->m_type == "double") {
        m_var->m_sym->m_value=new double(m_expr->eval_double());
    }
    else if (m_var->m_type == "string")
        m_var->m_sym->m_value=new string(m_expr->eval_string());
}
}
