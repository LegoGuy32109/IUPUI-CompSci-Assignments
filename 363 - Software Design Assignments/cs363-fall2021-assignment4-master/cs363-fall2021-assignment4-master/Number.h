// Number.h for numbers that the calculator computes
#ifndef NUMBER_EXISTS
#define NUMBER_EXISTS

#include "Component.h"

class Number : public Component {
    public:
    // constructor to store number value
    Number(int num);
    // don't need deconstructor because it has one from Component
    void accept(Node_Visitor & v);
    int value;
};

#endif
