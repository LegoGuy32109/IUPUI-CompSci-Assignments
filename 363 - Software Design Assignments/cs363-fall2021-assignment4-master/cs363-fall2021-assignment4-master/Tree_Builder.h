// Tree_Builder.h to create Builder for expression tree
#ifndef TREE_BUILDER_EXISTS
#define TREE_BUILDER_EXISTS
#include "Expression_Builder.h"
#include "Number.h"
#include "Add_Operator.h"
#include "Sub_Operator.h"
#include "Mul_Operator.h"
#include "Div_Operator.h"
#include "Mod_Operator.h"
#include "Queue.h" // for storing created Operators/Components
#include "Stack.h" // useful to help create the tree of composite nodes
class Tree_Builder : public Expression_Builder {
public:
    Tree_Builder(void);
    ~Tree_Builder(void);
    void makeNumber(int n);
    void makeAdd(void);
    void makeSub(void);
    void makeMul(void);
    void makeDiv(void);
    void makeMod(void);
    Queue<Component*> getExpression(void);
    void clearExpression(void);
private:
    Queue<Component*> expression;
};

#endif
