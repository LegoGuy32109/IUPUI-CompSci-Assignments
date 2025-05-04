// Number.h for numbers that the calculator computes
#ifndef NUMBER_EXISTS
#define NUMBER_EXISTS

#include "Command.h"

class Number : public Command {
    public:
    // constructor to store number value
    Number(int num);
    // don't need deconstructor because it has one from command
    void execute(Stack<int>*);

    private:
    int value;
};

#endif