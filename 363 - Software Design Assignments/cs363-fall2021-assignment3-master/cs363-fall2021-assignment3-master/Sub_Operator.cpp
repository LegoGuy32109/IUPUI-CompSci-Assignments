// Sub_Operator.cpp extedned from Operator Abstract to do Subtraction commands

#include "Sub_Operator.h"

void Sub_Operator::execute(Stack<int> * s) {
	int x = s->top();
	s->pop();
	int y = s->top();
	s->pop();
	s->push(y-x);
}


