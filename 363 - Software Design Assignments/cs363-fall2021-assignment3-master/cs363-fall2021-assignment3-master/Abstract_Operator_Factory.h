// Abstract_Operator_Factory.h written by JOsh Hale
#ifndef ABSTRACT_OPERATOR_H_EXISTS
#define ABSTRACT_OPERATOR_H_EXISTS

#include "Add_Operator.h"
#include "Sub_Operator.h"
#include "Mul_Operator.h"
#include "Div_Operator.h"
#include "Mod_Operator.h"

// COMMENT You class definition belongs in the header file, and its implementation
// in the source file.

// RESPONSE I now have the class definition in the header file, leaving implementation in the inherited classes


// COMMENT You are not implementing the abstract factory pattern.

// RESPONSE I now understand that the factory produces all the different Operators, rather than making a factory for each one. This abstract factory can be extended into a flyweight factory to save code

/**
 * @class Abstract_Operator_Factory
 * 
 * Factory to be implemented in concrete operator factories
 */

class Abstract_Operator_Factory 
{
public:
    virtual ~Abstract_Operator_Factory(void) {};
    // I want the abstract class to have a virtual destructor

    // these are pure virtual functions forcing child classes to implement them
    virtual Add_Operator *makeAddOperator(void) const = 0;
    virtual Sub_Operator *makeSubOperator(void) const = 0;
    virtual Mul_Operator *makeMulOperator(void) const = 0;
    virtual Div_Operator *makeDivOperator(void) const = 0;
    virtual Mod_Operator *makeModOperator(void) const = 0;
};

#endif // !defined ABSTRACT_OPERATOR_H_EXISTS
