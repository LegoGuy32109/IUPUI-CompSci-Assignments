// Command.h abstract object for commands in calulator
#ifndef COMMAND_EXISTS
#define COMMAND_EXISTS

#include "Stack.h"

class Command {
    public:

    // Deconstructer for inheirted classes to be deleted
    virtual ~Command(void) {};
    virtual void execute(Stack<int>*) = 0;
};

#endif
