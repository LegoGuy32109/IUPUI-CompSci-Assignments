// Number.cpp for numbers that the calculator computes
#include "Number.h"

Number::Number (int num) :
value(num)
{
	priority = 0;
}

void Number::accept(Node_Visitor & v){
    v.visitNum(this);
}
