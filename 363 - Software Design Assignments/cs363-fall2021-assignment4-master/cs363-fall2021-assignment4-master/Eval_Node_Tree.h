// Eval_Node_Tree.h Template for evaluating the tree
#ifndef EVAL_NODE_EXISTS
#define EVAL_NODE_EXISTS

#include "Node_Visitor.h"


/**
 * @class Eval_Node_Tree
 * 
 * Abstract Class for evaluation of tree operations, inherits from Node_Visitor
 */
class Eval_Node_Tree : public Node_Visitor
{
public:
    virtual ~Eval_Node_Tree (void) = default;
    // methods for visiting concrete nodes
    virtual void visitAdd (const class Add_Operator * node) = 0;
    virtual void visitSub (const class Sub_Operator * node) = 0;
    virtual void visitMul (const class Mul_Operator * node) = 0;
    virtual void visitDiv (const class Div_Operator * node) = 0;
    virtual void visitMod (const class Mod_Operator * node) = 0;
    virtual void visitNum (const class Number * node) = 0;
};
#endif
