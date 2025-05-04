// Mod_Operator.h extedned from Operator Abstract to do Modulus commands
#ifndef MOD_OPERATOR_EXISTS
#define MOD_OPERATOR_EXISTS

#include "Operator.h"

class Mod_Operator : public Operator {
public:
    void execute(Stack<int> * s);
};


#endif