// Calculator.cpp to calculate given expressions
#include <sstream> // for parsing input
#include "Calculator.h"
Calculator::Calculator(void) {
};


// Converts input to a Tree_Builder containing the tree
Tree_Builder Calculator::parseInput(const std::string infix) {
	Tree_Builder b;
	std::istringstream input (infix);
	std::string token;
	while (!input.eof()) {
		input >> token;
		if(token == "+") b.makeAdd();
		else if(token == "-") b.makeSub();
		else if(token == "*") b.makeMul();
		else if(token == "/") b.makeDiv();
		else if(token == "%") b.makeMod();
		else if(token == "(") {
			// calculate subExpression inside parenthesses
			int firstFoundOpen = infix.find("(") + 2; // 2 removes ( and space
			int lastFoundClosed = infix.find_last_of(")") - 1; // -1 removes space
			std::cout << "FirstOpen: " << firstFoundOpen << " LastClosed: " << lastFoundClosed << "\n";
			std::string subExpression = infix.substr(firstFoundOpen, lastFoundClosed);
			b.makeNumber(evaluate(subExpression));
		} else b.makeNumber(std::stoi(token));
	}
	return b;
}

int Calculator::evaluate(std::string input) {
	Tree_Builder b = parseInput(input);
	Concrete_Node_Visitor v;
	// this chain takes the input:
	// parses input into components
	// creates a tree from those components
	// has the Node_Visitor traverse the tree to evaluate the expression
    
    // COMMENT: Do not go from infix to postfix then to tree. Instead,
    // go directly from infix to tree. The extra step is not necessary.
    
    // RESPONSE: I now do not go from infix to postfix and instead parse the input directly
    
	createTree(b.getExpression())->accept(v);
	b.clearExpression();
	return v.getResult();
}

// function to create a Tree out of a Queue of Component pointers 
Component * Calculator::createTree(Queue<Component*> input){
    Queue<Component*> expression = inToPost(input);    

    Stack<Component*> compStack;
    while(!expression.is_empty()){
        Component* c = expression.dequeue();
        // shouldn't worry about (), those were weeded out in the construction of infix to postfix in Calculator
        switch(c->priority) {
            // if +,-,*,/,% attach the last two components to the right spots in the tree           
            case 1:
            case 2:
                // make sure compStack is at least size 2!
                c->B = compStack.top();
                compStack.pop();
                c->A = compStack.top();
                compStack.pop();
            // no matter the Component add it to stack
            default:
                compStack.push(c);
                break;
        }
    }
    // return The Component at top of stack, every other component is a child from this node, could just be a number
    return compStack.top();
}

// converts infix to postfix
Queue<Component*> Calculator::inToPost(Queue<Component*> pre) {
	Stack<Component*> opStack;
	Queue<Component*> post;
	Component* curComponent;

	while(!pre.is_empty()){
		curComponent = pre.dequeue();
		// logic done using a switch statement of priority
		/* Priotity Table:
		0: Number, + or -
		1: +, -
		2: *, /, %
		-1: (
		-2: )
		*/		
		switch (curComponent->priority) {
			case 1:
			case 2:
				while(!opStack.is_empty() && curComponent->priority <= opStack.top()->priority){
					post.enqueue(opStack.top());
					opStack.pop();
				} 
				opStack.push(curComponent);
				break;
			case -1:
				opStack.push(curComponent);
				break;
			case -2:
				while(opStack.top()->priority != -1){
					post.enqueue(opStack.top());
					opStack.pop();
				}
				opStack.pop();
				break;
			default:
				post.enqueue(curComponent);
				break;
		}		
	}

	while(!opStack.is_empty()){
		post.enqueue(opStack.top());
		opStack.pop();
	}
	return post;
}


