// Sub_Operator.h extedned from Operator Abstract to do Add commands
#ifndef ADD_OPERATOR_EXISTS
#define ADD_OPERATOR_EXISTS

#include "Operator.h"

class Add_Operator : public Operator {
public:
	
	void execute(Stack<int> * s);
};

#endif
