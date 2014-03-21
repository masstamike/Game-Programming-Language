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
    switch(op) {
        case UNARY_MINUS:
            type=ex->get_type();
            break;
        case RANDOM:
        case FLOOR:
        case NOT:
            type = "int";
            break;
        case SIN:
        case COS:
        case TAN:
        case ASIN:
        case ACOS:
        case ATAN:
        case SQRT:
            type = "double";
            break;
        default:
            type = ex->get_type();
            break;
    }
}

Expr::Expr(Operator_type op, Expr* left, Expr* right) {
    m_op = op;
    if(left && right){
    switch(op) {
        case PLUS:
            if(left->get_type() == right->get_type())
                type = left->get_type();
            else if(left->get_type() == "string" || right->get_type()=="string")
                type = "string";
            else if(left->get_type() == "double" || right->get_type()=="double")
                type = "double";
            else if((left->get_type())=="int"&&(right->get_type())=="int")
                type = "int";
            break;
        case MINUS:
            if(left->get_type() == right->get_type() &&
                left->get_type()!="string")
                type = left->get_type();
            else if(left->get_type() == "double" || right->get_type()=="double")
                type = "double";
            else if((left->get_type())=="int"&&(right->get_type())=="int")
                type = "int";
            break;
            type = "int";
            break;
        case MULTIPLY:
            if(left->get_type() == right->get_type())
                type = left->get_type();
            else if(left->get_type() == "string" || left->get_type()=="string")
                type = "string";
            else if(left->get_type() == "double" || right->get_type()=="double")
                type = "double";
            else if((left->get_type())=="int"&&(right->get_type())=="int")
                type = "int";
            break;
        case DIVIDE:
            if(left->get_type() == right->get_type())
                type = left->get_type();
            else if(left->get_type() == "string" || left->get_type()=="string")
                type = "string";
            else if(left->get_type() == "double" || right->get_type()=="double")
                type = "double";
            else if((left->get_type())=="int"&&(right->get_type())=="int")
                type = "int";
            break;
        case MOD:
            type = "int";
            break;
        case UNARY_MINUS:
            type = "int";
            break;
        case NOT:
            type = "int";
            break;
        case AND:
            type = "int";
            break;
        case OR:
            type = "int";
            break;
        case EQUAL:
            type = "int";
            break;
        case NOT_EQUAL:
            type = "int";
            break;
        case LESS_THAN:
            type = "int";
            break;
        case LESS_THAN_EQUAL:
            type = "int";
            break;
        case GREATER_THAN:
            type = "int";
            break;
        case GREATER_THAN_EQUAL:
            type = "int";
            break;
    }
    }
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
        if(m_op==NOT) {
            return m_left->eval_int()?0:1;
        } else if(m_op==MULTIPLY) {
            return m_left->eval_int()*m_right->eval_int();
        } else if (m_op==UNARY_MINUS) {
            return -(m_left->eval_int());
        } else if (m_op==RANDOM) {
            return (rand() % m_left->eval_int());
        } else if(m_op==DIVIDE) {
            return m_left->eval_int()/m_right->eval_int();
        } else if(m_op==LESS_THAN_EQUAL && (m_left->get_type()=="string" ||
            m_right->get_type()=="string")) {
            return m_left->eval_string()<=m_right->eval_string()?1:0;
        } else if(m_op==GREATER_THAN_EQUAL && (m_left->get_type()=="string" ||
            m_right->get_type()=="string")) {
            return m_left->eval_string()>=m_right->eval_string()?1:0;
        } else if(m_op==GREATER_THAN && (m_left->get_type()=="string" ||
            m_right->get_type()=="string")) {
            return m_left->eval_string()>m_right->eval_string()?1:0;
        } else if(m_op==LESS_THAN && (m_left->get_type()=="string" ||
            m_right->get_type()=="string")) {
            return m_left->eval_string()<m_right->eval_string()?1:0;
        } else if(m_op==NOT_EQUAL && (m_left->get_type()=="string" ||
            m_right->get_type()=="string")) {
            return m_left->eval_string()!=m_right->eval_string()?1:0;
        }
        if(m_op == EQUAL && (m_left->get_type() == "string" ||
            m_right->get_type() == "string"))
            return m_left->eval_string()==m_right->eval_string();
        if(m_left->get_type()==m_right->get_type()) {
            if(m_left->get_type()=="int") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_int()==m_right->eval_int())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_int()!=m_right->eval_int())?1:0;
                    case AND:
                        return (m_left->eval_int()&&m_right->eval_int())?1:0;
                    case OR:
                        return (m_left->eval_int()||m_right->eval_int())?1:0;
                    case LESS_THAN:
                        return (m_left->eval_int()<m_right->eval_int())?1:0;
                    case LESS_THAN_EQUAL:
                        return (m_left->eval_int()<=m_right->eval_int())?1:0;
                    case GREATER_THAN:
                        return (m_left->eval_int()>m_right->eval_int())?1:0;
                    case GREATER_THAN_EQUAL:
                        return (m_left->eval_int()>=m_right->eval_int())?1:0;
                    case PLUS:
                        return m_left->eval_int()+m_right->eval_int();
                }
            } else if(m_left->get_type() == "double") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_double()==m_right->eval_double())?
                            1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_double()!=m_right->eval_double())?
                            1:0;
                    case AND:
                        return (m_left->eval_double()&&m_right->eval_double())?
                            1:0;
                    case OR:
                        return (m_left->eval_double()||m_right->eval_double())?
                            1:0;
                    case LESS_THAN:
                        return (m_left->eval_double()<m_right->eval_double())?
                            1:0;
                    case LESS_THAN_EQUAL:
                        return (m_left->eval_double()<=m_right->eval_double())?
                            1:0;
                    case GREATER_THAN:
                        return (m_left->eval_double()>m_right->eval_double())?
                            1:0;
                    case GREATER_THAN_EQUAL:
                        return (m_left->eval_double()>=m_right->eval_double())?
                            1:0;
                }
            } else {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_string()==m_right->eval_string())?
                            1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_string()!=m_right->eval_string())?
                            1:0;
                    case LESS_THAN_EQUAL:
                        return (m_left->eval_string()<=m_right->eval_string())?
                            1:0;
                }
            }
        } else if(m_left->get_type() == "int") {
            if(m_right->get_type() == "double") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_int()==m_right->eval_double())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_int()!=m_right->eval_double())?1:0;
                    case AND:
                        return (m_left->eval_int()&&m_right->eval_double())?1:0;
                    case OR:
                        return (m_left->eval_int()||m_right->eval_double())?1:0;
                    case LESS_THAN:
                        return (m_left->eval_int()<m_right->eval_double())?1:0;
                    case LESS_THAN_EQUAL:
                        return (m_left->eval_int()<=m_right->eval_double())?1:0;
                    case GREATER_THAN:
                        return (m_left->eval_int()>m_right->eval_double())?1:0;
                    case GREATER_THAN_EQUAL:
                        return (m_left->eval_int()>=m_right->eval_double())?1:0;
                }
            }
        } else if(m_left->get_type() == "double") {
            if(m_right->get_type() == "int") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_double()==m_right->eval_int())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_double()!=m_right->eval_int())?1:0;
                    case AND:
                        return (m_left->eval_double()&&m_right->eval_int())?1:0;
                    case OR:
                        return (m_left->eval_double()||m_right->eval_int())?1:0;
                    case LESS_THAN:
                        return (m_left->eval_double()<m_right->eval_int())?1:0;
                    case LESS_THAN_EQUAL:
                        return (m_left->eval_double()<=m_right->eval_int())?1:0;
                    case GREATER_THAN:
                        return (m_left->eval_double()>m_right->eval_int())?1:0;
                    case GREATER_THAN_EQUAL:
                        return (m_left->eval_double()>=m_right->eval_int())?1:0;
                }
            }
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
        else if (type == "int") {
            return (double) m_int;
        }
//        else
            //error
    }
    else if (m_kind == "expr") {
        switch(m_op) {
            case NOT:
                return m_left->eval_double()?0:1;
            case PLUS:
                return (m_left->eval_double())+(m_right->eval_double());
            case MINUS:
                return (m_left->eval_double())-(m_right->eval_double());
            case MULTIPLY:
                return (m_left->eval_double())*(m_right->eval_double());
            case SIN: 
                return sin(m_left->eval_double()*3.141592653589/180);
            case COS:
                return cos(m_left->eval_double()*3.141592653589/180);
            case TAN:
                return tan(m_left->eval_double()*3.141592653589/180);
            case ASIN:
                return asin(m_left->eval_double())*180/3.141592653589;
            case ACOS:
                return acos(m_left->eval_double())*180/3.141592653589;
            case ATAN:
                return atan(m_left->eval_double())*180/3.141592653589;
            case SQRT:
                return sqrt(m_left->eval_double());
            case ABS:
                return fabs(m_left->eval_double());
            case FLOOR:
                return floor(m_left->eval_double());
            case UNARY_MINUS:
                return -(m_left->eval_double());
            case RANDOM:
                return (rand() % m_left->eval_int());
/*            case DIVIDE:
                return m_left->eval_double()/m_right->eval_double();

    ---Moving to down below---

*/
        }
        if(m_left->get_type()==m_right->get_type()) {
            if(m_left->get_type()=="int") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_int()==m_right->eval_int())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_int()!=m_right->eval_int())?1:0;
                    case AND:
                        return (m_left->eval_int()&&m_right->eval_int())?1:0;
                    case OR:
                        return (m_left->eval_int()||m_right->eval_int())?1:0;
                    case DIVIDE:
                        return (double)(m_left->eval_int()/m_right->eval_int());
                }
            }
            else if(m_left->get_type() == "double")
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_double()==m_right->eval_double())?
                            1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_double()!=m_right->eval_double())?
                            1:0;
                    case AND:
                        return (m_left->eval_double()&&m_right->eval_double())?
                            1:0;
                    case OR:
                        return (m_left->eval_double()||m_right->eval_double())?
                            1:0;
                    case DIVIDE:
                        return m_left->eval_double()/m_right->eval_double();
                }
            else {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_string()==m_right->eval_string())?
                            1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_string()!=m_right->eval_string())?
                            1:0;
                }
            }
        } else if (m_left->get_type() == "int") {
            if(m_right->get_type() == "double") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_int()==m_right->eval_double())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_int()!=m_right->eval_double())?1:0;
                    case AND:
                        return (m_left->eval_int()&&m_right->eval_double())?1:0;
                    case OR:
                        return (m_left->eval_int()||m_right->eval_double())?1:0;
                    case DIVIDE:
                        return (m_left->eval_double()/m_left->eval_double());
                }
            }
        } else if(m_left->get_type() == "double") {
            if(m_right->get_type() == "int") {
                switch (m_op) {
                    case EQUAL:
                        return (m_left->eval_double()==m_right->eval_int())?1:0;
                    case NOT_EQUAL:
                        return (m_left->eval_double()!=m_right->eval_int())?1:0;
                    case AND:
                        return (m_left->eval_double()&&m_right->eval_int())?1:0;
                    case OR:
                        return (m_left->eval_double()||m_right->eval_int())?1:0;
                    case DIVIDE:
                        return (m_left->eval_double()/m_left->eval_double());
                }
            }
        }
    } else if (m_kind == "variable") {
        if(m_var->m_type == "double") {
            double d = *(double*) m_var->m_sym->m_value;
            return d;
        }
        else if (m_var->m_type == "int") {
            double d = (double) *(int*) m_var->m_sym->m_value;
            return d;
        }
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
        switch(m_op) {
            case PLUS:
                if(type == "double") {
                    double d = (m_left->eval_double())+(m_right->eval_double());
                    ss<<d;
                    return ss.str();
                } else if (type=="string") {
                    return m_left->eval_string()+m_right->eval_string();
                } else {
                    ss<<(m_left->eval_string()+m_right->eval_string());
                    return ss.str();
                }
            case LESS_THAN_EQUAL:
                return m_left->eval_string()<=m_right->eval_string()?"1":"0";
        }
/*        switch (m_op) {
            case EQUAL:
                return eval_int()?"1":"0";
        }*/
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
