// Add_Operator.cpp extedned from Operator Abstract to do Add commands

#include "Add_Operator.h"

Add_Operator::Add_Operator(void) {
	priority = 1;
}

void Add_Operator::accept(Node_Visitor & v) {
	v.visitAdd(this);
}
