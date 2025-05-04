// Div_Operator.h extedned from Operator Abstract to do Division commands
#ifndef DIV_OPERATOR_EXISTS
#define DIV_OPERATOR_EXISTS

#include "Operator.h"

class Div_Operator : public Operator {
public:
    void execute(Stack<int> * s);
};

#endif