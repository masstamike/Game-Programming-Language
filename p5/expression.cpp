#include <cassert>
#include <iostream>
#include <string>
#include "expression.h"

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
        else
            return (double) m_int;
    }
    else if (m_kind == "expr") {
        if(m_op==MULTIPLY) {
            return m_left->eval_double()*m_right->eval_double();
        }
    } else if (m_kind == "variable") {
        if(m_var->m_sym->m_type == "double")
            return *(double*) m_var->m_sym->m_value;
        //else
            //error
    }
    else {
        return m_double; //just for now
    }
}

std::string Expr::eval_string() {
//    assert(type == "string");
    std::cout<<"evaluating a string\n";
    if(m_kind == "constant") {
        if(type=="int") {
            return std::to_string(m_int);
        }
        else if(type=="double") {
            return std::to_string(m_double);
        }
        return m_str;
    }
    else if (m_kind == "expr") {
        if(operator_to_string(m_op) == "+") {
            int ileft, iright;
            double dleft, dright;
/*            if(m_left->type == "int") {
                ileft = m_left->eval_int();
                if(m_right->type == "int") {
                    iright = m_right->eval_int();
                    return std::to_string(ileft+iright);
                } else if(m_right->type == "double") {
                    dright = m_right->m_double;
                    dright = iright+dright;
                    return std::to_string(dright);
                }
            }*/
            if(type == "double") {
                double d = m_left->eval_double()+m_right->eval_double();
                return std::to_string(d);
            }
            else
                return m_left->eval_string()+m_right->eval_string();
        }
    } else if (m_kind=="variable") {
        if(m_var->m_sym->m_type == "string")
            return *(std::string*) m_var->m_sym->m_value;
        else if(m_var->m_sym->m_type == "int")
            return std::to_string(*(int*) m_var->m_sym->m_value);
        else if(m_var->m_sym->m_type == "double")
            return std::to_string(*(double*) m_var->m_sym->m_value);
    } else {
        return m_str; //just for now
    }
}

std::string Expr::get_type() {
    return type;
}
