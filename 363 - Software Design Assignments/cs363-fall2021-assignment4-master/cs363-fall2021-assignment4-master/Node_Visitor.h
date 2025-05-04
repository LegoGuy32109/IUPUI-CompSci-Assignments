// Component.h written by JOsh Hale
#ifndef VISITOR_H_EXISTS
#define VISITOR_H_EXISTS

// COMMENT The visitor pattern should have a base visitor class that
// contain empty methods. You then have different concrete visitors.
// Combining them means that all visitors will share the same default
// implementation/logic.

// RESPONSE This file is now the abstract base for the visitor class, and contains empty methods

/**
 * @class Node_Visitor
 * 
 * Abstract Class for traversal of tree of operations
 */
class Node_Visitor
{
public:
    // I don't know why there is a virtual deconstructor but no constructor
    virtual ~Node_Visitor (void) = default;
    
    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitAdd (const class Add_Operator * node) = 0;

    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitSub (const class Sub_Operator * node) = 0;

    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitMul (const class Mul_Operator * node) = 0;

    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitDiv (const class Div_Operator * node) = 0;

    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitMod (const class Mod_Operator * node) = 0;

    // COMMENT: Do not return a value from the accept () of visit () methods
    // in the Visitor pattern. This approach implies that all visit and accept
    // methods must return a value, which may not always be the case. Instead,
    // accumulate state in the visitor object, and access the state as needed.
    virtual void visitNum (const class Number * node) = 0;

    // RESPONSE TO ALL ABOVE these methods now do not return int, rather they accumulate state in the visitor object

};
#endif
