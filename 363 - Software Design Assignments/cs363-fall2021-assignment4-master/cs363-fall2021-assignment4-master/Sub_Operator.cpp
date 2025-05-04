// Sub_Operator.cpp extedned from Operator Abstract to do Subtraction commands

#include "Sub_Operator.h"

Sub_Operator::Sub_Operator(void) {
	priority = 1;
}

void Sub_Operator::accept(Node_Visitor & v) {
	v.visitSub(this);
}


