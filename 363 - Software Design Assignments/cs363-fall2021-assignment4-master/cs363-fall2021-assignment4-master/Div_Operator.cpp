// Div_Operator.cpp extedned from Operator Abstract to do Division commands


#include "Div_Operator.h"

Div_Operator::Div_Operator(void) 
{
	priority = 2;
}

void Div_Operator::accept(Node_Visitor & v) {
	v.visitDiv(this);
}



