// Div_Operator.h extedned from Operator Abstract to do Division commands
#ifndef DIV_OPERATOR_EXISTS
#define DIV_OPERATOR_EXISTS

#include "Operator.h"

class Div_Operator : public Operator {
public:
    Div_Operator(void);
    void accept(Node_Visitor & v);
};

#endif
