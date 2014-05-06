#include "assign_stmt.h"
#include "symbol_table.h"
#include "gpl_type.h"
#include "error.h"
using namespace std;

Assign_stmt::Assign_stmt(Variable* var, Expr* expr, int type) {
    m_var = var;
    m_expr = expr;
    assign_type = type;
}

void Assign_stmt::execute() {
    if(m_var->m_type == "int") {
        int previous;
        if(assign_type) {
            previous = m_var->get_int();
        }
        switch(assign_type) {
            case 0:
                m_var->set(m_expr->eval_int());
                break;
            case 1:
                m_var->set(previous+m_expr->eval_int());
                break;
            case 2:
                m_var->set(previous-m_expr->eval_int());
                break;
        }
    }
    else if (m_var->m_type == "double") {
        double previous;
        if(assign_type) {
            previous = m_var->get_double();
        }
        switch(assign_type) {
            case 0:
                m_var->set(m_expr->eval_double());
                break;
            case 1:
                m_var->set(previous+m_expr->eval_double());
                break;
            case 2:
                m_var->set(previous-m_expr->eval_double());
                break;
        }
    }
    else if (m_var->m_type == "string") {
        std::string previous;
        if(assign_type) {
            previous = m_var->get_string();
        }
        switch(assign_type) {
            case 0:
                m_var->set(m_expr->eval_string());
                break;
            case 1:
                m_var->set(previous+m_expr->eval_string());
                break;
        }
    }
}
