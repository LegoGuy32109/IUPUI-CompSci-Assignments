// Component.h written by JOsh Hale
#ifndef COMPONENT_H_EXISTS
#define COMPONENT_H_EXISTS
#include "Node_Visitor.h"
/**
 * @class Component
 * 
 * Abstract class for traversal of tree of operations
 */

class Component
{
public:
    virtual ~Component (void) = default;
    // I want the abstract class to have a virtual destructor

    // pure virtual functions forcing child classes to implement them
    virtual void accept(Node_Visitor &) = 0;
    
    // priority is for order of operations
    int priority;
    // left and right children of the composite tree
    Component * A;
    Component * B;
};

#endif // !defined ABSTRACT_OPERATOR_H_EXISTS
