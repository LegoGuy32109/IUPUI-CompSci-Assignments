// Mul_Operator.cpp extedned from Operator Abstract to do Multiplication commands

#include "Mul_Operator.h"

Mul_Operator::Mul_Operator(void) {	
	priority = 2;
}
void Mul_Operator::accept(Node_Visitor & v) {
	v.visitMul(this);
}
