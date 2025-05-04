// Calculator.h to calculate given expressions

#ifndef CALC_H_EXISTS
#define CALC_H_EXISTS

#include <iostream>
#include <string> // for stoi
#include "Queue.h"
#include "Stack.h"

#include "Command.h"
#include "Operator.h"
#include "Stack_Factory.h" // for creating executeable commands
#include "Number.h" // for creating numbers

class Calculator {
public:
	/*
    // constructor and destructor
    Calculator (void);
    ~Calculator (void);
	*/
    // evaluates postfix expression form a queue
    int evaluate(Queue<Command*> infix);

    // converts infix to postfix string queues
    Queue<std::string> inToPost(Queue<std::string> pre);

    // converts a string queue into a command queue for evaluation
    // Queue<Command*> toCommand(Queue<std::string>);

private:
    // internal function to find precedence of operator
    int precedence(std::string input);
    
};

#endif // !CALC_H_EXISTS
