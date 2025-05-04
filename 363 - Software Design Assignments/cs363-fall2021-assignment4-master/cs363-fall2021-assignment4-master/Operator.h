// Operator.h abstract object for Operator nodes
#ifndef OPERATOR_EXISTS
#define OPERATOR_EXISTS

#include "Component.h"

class Operator : public Component {
    // Operator serves as a group of commands for specific execution

public:
    // Continue inheirtance of execute method
    virtual void accept(Node_Visitor & v) = 0;
};


#endif
