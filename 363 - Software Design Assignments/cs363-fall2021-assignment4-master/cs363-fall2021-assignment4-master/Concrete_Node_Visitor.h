// Concrete_Node_Visitor.h Concretion to actually evaluate tree
#ifndef CONCRETE_NODE_EXISTS
#define CONCRETE_NODE_EXISTS

#include "Eval_Node_Tree.h"
#include "Stack.h"

/**
 * @class Concrete_Node_Visitor
 * 
 * Concrete Class for actual evaluation of tree operations, inherits from Node_Visitor
 */
class Concrete_Node_Visitor : public Eval_Node_Tree
{
public:
    Concrete_Node_Visitor (void);

    // methods for visiting concrete nodes
    void visitAdd (const class Add_Operator * node) override;
    void visitSub (const class Sub_Operator * node) override;
    void visitMul (const class Mul_Operator * node) override;
    void visitDiv (const class Div_Operator * node) override;
    void visitMod (const class Mod_Operator * node) override;
    void visitNum (const class Number * node) override;
    // return internal state
    int getResult (void) const;

private:
    // state to accumulate results
    int result;
    // stack to add values to
    Stack<int> s;
};

#endif
