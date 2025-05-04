// Expression_Builder.h template to create Builder classes that can construct the expressions
#ifndef EXPRESSION_BUILDER_EXISTS
#define EXPRESSION_BUILDER_EXISTS
class Expression_Builder {
public:
    // virtual void start_expression(void);
    virtual void makeNumber(int n) = 0;
    virtual void makeAdd(void) = 0;
    virtual void makeSub(void) = 0;
    virtual void makeMul(void) = 0;
    virtual void makeDiv(void) = 0;
    virtual void makeMod(void) = 0;
    // virtual Math_Expr * get_expression(void) = 0;
};

#endif 