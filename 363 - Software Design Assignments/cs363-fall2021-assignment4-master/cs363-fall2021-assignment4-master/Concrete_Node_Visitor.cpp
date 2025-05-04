// Node_Visitor.cpp functionality to traverse a tree of Nodes of Components

#include "Concrete_Node_Visitor.h"
// I guess I include all the stupid files
#include "Add_Operator.h"
#include "Sub_Operator.h"
#include "Mod_Operator.h"
#include "Mul_Operator.h"
#include "Div_Operator.h"
#include "Number.h"

Concrete_Node_Visitor::Concrete_Node_Visitor(void) :
result(0)
{}

int Concrete_Node_Visitor::getResult(void) const {
	return result;
}

void Concrete_Node_Visitor::visitAdd(const Add_Operator * node){
    node->B->accept(*this); 
    node->A->accept(*this);
    int tempA = s.top();
    s.pop();
    int tempB = s.top();
    s.pop();
    s.push(tempA+tempB);
    result = s.top();
}

void Concrete_Node_Visitor::visitSub(const Sub_Operator * node){
    node->B->accept(*this); 
    node->A->accept(*this);
    int tempA = s.top();
    s.pop();
    int tempB = s.top();
    s.pop();
    s.push(tempA-tempB);
    result = s.top();

}

void Concrete_Node_Visitor::visitMul(const Mul_Operator * node){
    node->B->accept(*this); 
    node->A->accept(*this);
    int tempA = s.top();
    s.pop();
    int tempB = s.top();
    s.pop();
    s.push(tempA*tempB);
    result = s.top();

}

void Concrete_Node_Visitor::visitDiv(const Div_Operator * node){
    // add error if A got a 0
    node->B->accept(*this); 
    node->A->accept(*this);
    int tempA = s.top();
    s.pop();
    int tempB = s.top();
    s.pop();
    s.push(tempA/tempB);
    result = s.top();

}

void Concrete_Node_Visitor::visitMod(const Mod_Operator * node){
    node->B->accept(*this); 
    node->A->accept(*this);
    int tempA = s.top();
    s.pop();
    int tempB = s.top();
    s.pop();
    s.push(tempA%tempB);
    result = s.top();

}

void Concrete_Node_Visitor::visitNum(const Number * node){
    s.push(node->value);
    result = s.top();

}
