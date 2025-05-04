// Stack_Factory.cpp to inheirt abstract factory into a concrete factory
#include "Stack_Factory.h"


Add_Operator *Stack_Factory::makeAddOperator(void) const {
    return new Add_Operator();
};
Sub_Operator *Stack_Factory::makeSubOperator(void) const {
    return new Sub_Operator();
};
Mul_Operator *Stack_Factory::makeMulOperator(void) const {
    return new Mul_Operator();
};
Div_Operator *Stack_Factory::makeDivOperator(void) const {
    return new Div_Operator();
};
Mod_Operator *Stack_Factory::makeModOperator(void) const {
    return new Mod_Operator();
};
