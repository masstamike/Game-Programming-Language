#include <cassert>
#include <iostream>
#include <string>
#include "expression.h"
#include <sstream>
#include <cmath>

Expr::Expr(int i) {
    m_int = i;
    type = "int";
    m_kind = "constant";
}

Expr::Expr(double d) {
    m_double = d;
    type = "double";
    m_kind = "constant";
}

Expr::Expr(std::string s) {
    s.erase(0,1);
    s.erase(s.size()-1);
    m_str = s;
    type = "string";
    m_kind = "constant";
}

Expr::Expr(Operator_type op, Expr* ex) {
    m_op = op;
    m_kind = "expr";
    m_left = ex;
    m_right = NULL;
    if(operator_to_string(op)=="sin")
        type = "double";
//    else if ...
//    else ...
}

Expr::Expr(Operator_type op, Expr* left, Expr* right) {
    m_op = op;
    if(left && right){
    if(left->type == right->type)
        type = left->type;
    else if(left->type == "string" || left->type=="string")
        type = "string";
    else if(left->type == "double" || right->type=="double")
        type = "double";
    else if((left->type)=="int"&&(right->type)=="int")
        type = "int";}
    else {
        std::cout<<left<<operator_to_string(op)<<right<<"left or right not define\n";
        type == "int"; //just for now
    }
    m_kind = "expr";
    m_left = left;
    m_right = right;
}

Expr::Expr(Variable* var) {
    m_var = var;
    type = var->m_type;
    m_kind = "variable";
}

Expr::~Expr() {
    if(m_left) delete m_left;
    if(m_right) delete m_right;
}

int Expr::eval_int() {
//    assert(type == "int");
    if(m_kind == "constant")
        return m_int;
    else if (m_kind == "expr") {
        if(m_op==MULTIPLY) {
            return m_left->eval_int()*m_right->eval_int();
        }
    } else if (m_kind == "variable") {
        if(m_var->m_sym->m_type == "int")
            return *(int*) m_var->m_sym->m_value;
        //else
            //error
    }
    return m_int; //just for now
}

double Expr::eval_double() {
//    assert(type == "double");
    if(m_kind == "constant") {
        if(type=="double")
            return m_double;
        else {
            return (double) m_int;
        }
    }
    else if (m_kind == "expr") {
        if(m_op==MULTIPLY) {
            return m_left->eval_double()*m_right->eval_double();
        } else if (m_op==SIN) {
            return sin(m_left->eval_double()*3.141592653689/180);
        }
    } else if (m_kind == "variable") {
        if(m_var->m_sym->m_type == "double")
            return *(double*) m_var->m_sym->m_value;
        else if (m_var->m_sym->m_type == "int")
            return (double) *(int*) m_var->m_sym->m_value;
    }
    else {
        return m_double; //just for now
    }
}

std::string Expr::eval_string() {
//    assert(type == "string");
    std::stringstream ss;
    if(m_kind == "constant") {
        if(type=="int") {
            ss<<m_int;
            return ss.str();
        }
        else if(type=="double") {
            ss<<m_double;
            return ss.str();
        }
        return m_str;
    }
    else if (m_kind == "expr") {
        if(operator_to_string(m_op) == "+") {
//            int ileft, iright;
//            double dleft, dright;
            if(type == "double") {
                double d = (m_left->eval_double())+(m_right->eval_double());
                ss<<d;
                return ss.str();
            }
            else {
                ss<<(m_left->eval_string()+m_right->eval_string());
                return ss.str();
            }
        }
    } else if (m_kind=="variable") {
        if(m_var->m_sym->m_type == "string") {
            std::string s=*(std::string*) m_var->m_sym->m_value;
            return s;
        } else if (m_var->m_sym->m_type == "int") {
            int i = *(int*) m_var->m_sym->m_value;
            ss<<i;
            return ss.str();
        } else if (m_var->m_sym->m_type == "double") {
            double d = *(double*) m_var->m_sym->m_value;
            ss<<d;
            return ss.str();
        }
    } else {
        return m_str; //just for now
    }
}

std::string Expr::get_type() {
    return type;
}
