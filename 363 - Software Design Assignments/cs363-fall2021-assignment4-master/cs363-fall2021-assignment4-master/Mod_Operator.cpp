// Mod_Operator.h extedned from Operator Abstract to do Modulus commands

#include "Mod_Operator.h"

Mod_Operator::Mod_Operator(void) {
	priority = 2;
}
void Mod_Operator::accept(Node_Visitor & v) {
	v.visitMod(this);
}

