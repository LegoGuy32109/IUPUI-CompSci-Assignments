// Sub_Operator.h extedned from Operator Abstract to do Subtraction commands
#ifndef SUB_OPERATOR_EXISTS
#define SUB_OPERATOR_EXISTS

#include "Operator.h"

class Sub_Operator : public Operator {
public:
    void execute(Stack<int> * s);
};

#endif