// Mod_Operator.h extedned from Operator Abstract to do Modulus commands

#include "Mod_Operator.h"

// COMMENT You class definition belongs in the header file, and its implementation
// in the source file.

// RESPONSE I now have the class definition in the header file, leaving implementation in .cpp file

void Mod_Operator::execute(Stack<int> * s) {
	int x = s->top();
	s->pop();
	int y = s->top();
	s->pop();
	s->push(y%x);
}

