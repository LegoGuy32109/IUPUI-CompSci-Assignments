// Stack_Factory.h to inheirt abstract factory into a concrete factory
#ifndef STACK_FACTORY_EXISTS
#define STACK_FACTORY_EXISTS

#include "Abstract_Operator_Factory.h"
#include "Add_Operator.h"
#include "Sub_Operator.h"
#include "Mul_Operator.h"
#include "Div_Operator.h"
#include "Mod_Operator.h"

class Stack_Factory : public Abstract_Operator_Factory {
public:

    // implementing the virtual functions abstract factory set up for this class
    Add_Operator *makeAddOperator(void) const override;
    Sub_Operator *makeSubOperator(void) const override;
    Mul_Operator *makeMulOperator(void) const;
    Div_Operator *makeDivOperator(void) const;
    Mod_Operator *makeModOperator(void) const;
    
};

#endif // !defined STACK_FACTORY_EXISTS
