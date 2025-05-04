// Calculator.h to calculate given expressions

#ifndef CALC_H_EXISTS
#define CALC_H_EXISTS

#include <iostream>
#include "Queue.h"
#include "Stack.h"

#include <string> // for stoi
#include "Tree_Builder.h" // for creating Tree
#include "Component.h"
#include "Concrete_Node_Visitor.h" // for traversing Tree

class Calculator {
public:
    Calculator(void);

    // evaluates the input string of an expression
    int evaluate(std::string input);

    // converts infix to postfix of Component Queues
    Queue<Component*> inToPost(Queue<Component*> pre);

    // converts a input string into a Queue of Operators
    Tree_Builder parseInput(const std::string infix);

    // creates a tree by linking a postfix of Components to each other, returns head node of the tree
    Component * createTree(Queue<Component*> expression);
};

#endif // !CALC_H_EXISTS
