// Mul_Operator.h extedned from Operator Abstract to do Multiplication commands
#ifndef MUL_OPERATOR_EXISTS
#define MUL_OPERATOR_EXISTS

#include "Operator.h"

class Mul_Operator : public Operator {
public:
    Mul_Operator(void);
    void accept(Node_Visitor & v);
};


#endif
