// Number.cpp for numbers that the calculator computes
#include "Number.h"

Number::Number (int num) {
    value = num;
}

void Number::execute(Stack<int>* s){
    s->push(value);
}