// Operator.h abstract object for Operator commands
#ifndef OPERATOR_EXISTS
#define OPERATOR_EXISTS

#include "Command.h"

// COMMENT You class definition belongs in the header file, and its implementation
// in the source file.

// RESPONSE I now have the class definition in the header file, leaving implementation in the inherited classes

class Operator : public Command{
    // Operator serves as a group of commands for specific execution

    public:
    // Deconstructer for inheirted classes to be deleted
    //virtual ~Operator();
    virtual void execute(Stack<int>*) = 0;
};

#endif
