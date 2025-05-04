// Tree_Builder.cpp
#include "Tree_Builder.h"

Tree_Builder::Tree_Builder(void){
}

Tree_Builder::~Tree_Builder(void){
	clearExpression();
}
// to give the calculator a Queue of expressions to convert to a tree
Queue<Component*> Tree_Builder::getExpression(void){
    return expression;
}

void Tree_Builder::clearExpression(void){
    	while(!expression.is_empty()){
		delete expression.dequeue();
	}    
}

void Tree_Builder::makeNumber(int n){
    expression.enqueue(new Number(n));
}

void Tree_Builder::makeAdd(void){
    expression.enqueue(new Add_Operator());
}

void Tree_Builder::makeSub(void){
    expression.enqueue(new Sub_Operator());
}

void Tree_Builder::makeMul(void){
    expression.enqueue(new Mul_Operator());
}

void Tree_Builder::makeDiv(void){
    expression.enqueue(new Div_Operator());
}

void Tree_Builder::makeMod(void){
    expression.enqueue(new Mod_Operator());
}

