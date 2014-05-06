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
    std::string object_name = id + "[0]";
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

void Variable::set(int i) {
    std::stringstream ss;
    if(m_sym) {
        if(m_member == "")
            *(int*) m_sym->m_value = i;
        else
            m_sym->get_game_object_value()->set_member_variable(m_member, i);
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_int();
            std::string name = m_id + "[" + ss.str() + "]";
            *(int*) Symbol_table::instance()->find(name)->m_value = i;
        } else {
            ss<<m_expr->eval_int();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                set_member_variable(m_member, i);
        }
    }
}

void Variable::set(double d) {
    std::stringstream ss;
    if(m_sym) {
        if(m_member == "")
            *(double*) m_sym->m_value = d;
        else
            m_sym->get_game_object_value()->set_member_variable(m_member, d);
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_double();
            std::string name = m_id + "[" + ss.str() + "]";
            *(double*) Symbol_table::instance()->find(name)->m_value = d;
        } else {
            ss<<m_expr->eval_double();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                set_member_variable(m_member, d);
        }
    }
}

void Variable::set(std::string s) {
    std::stringstream ss;
    if(m_sym) {
        if(m_member == "")
            *(std::string*) m_sym->m_value = s;
        else
            m_sym->get_game_object_value()->set_member_variable(m_member, s);
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_string();
            std::string name = m_id + "[" + ss.str() + "]";
            *(std::string*) Symbol_table::instance()->find(name)->m_value = s;
        } else {
            ss<<m_expr->eval_string();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                set_member_variable(m_member, s);
        }
    }
}

int Variable::get_int() {
    std::stringstream ss;
    if(m_sym) {
        int i;
        if(m_member == "")
            return *(int*) m_sym->m_value;
        else {
            m_sym->get_game_object_value()->get_member_variable(m_member, i);
            return i;
        }
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_int();
            std::string name = m_id + "[" + ss.str() + "]";
            return *(int*) Symbol_table::instance()->find(name)->m_value;
        } else {
            int i;
            ss<<m_expr->eval_int();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                get_member_variable(m_member, i);
            return i;
        }
    }
}

double Variable::get_double() {
    std::stringstream ss;
    if(m_sym) {
        double d;
        if(m_member == "")
            return *(double*) m_sym->m_value;
        else {
            m_sym->get_game_object_value()->get_member_variable(m_member, d);
            return d;
        }
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_double();
            std::string name = m_id + "[" + ss.str() + "]";
            return *(double*) Symbol_table::instance()->find(name)->m_value;
        } else {
            double d;
            ss<<m_expr->eval_double();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                get_member_variable(m_member, d);
        }
    }
}

std::string Variable::get_string() {
    std::stringstream ss;
    if(m_sym) {
        std::string s;
        if(m_member == "")
            return *(std::string*) m_sym->m_value;
        else {
            m_sym->get_game_object_value()->get_member_variable(m_member, s);
            return s;
        }
    } else if (m_expr) {
        if (m_member == "") {
            ss<<m_expr->eval_string();
            std::string name = m_id + "[" + ss.str() + "]";
            return *(std::string*) Symbol_table::instance()->find(name)->m_value;
        } else {
            std::string s;
            ss<<m_expr->eval_string();
            std::string name = m_id + "[" + ss.str() + "]";
            Symbol_table::instance()->find(name)->get_game_object_value()->
                get_member_variable(m_member, s);
        }
    }
}
