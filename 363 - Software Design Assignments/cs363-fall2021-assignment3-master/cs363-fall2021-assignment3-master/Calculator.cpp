// Calculator.cpp to calculate given expressions
#include <iostream> // for exception throwing
#include "Calculator.h"
#include "Stack_Factory.h"
#include <sstream>

// COMMENT You class definition belongs in the header file, and its implementation
// in the source file.

// RESPONSE I now have the class definition in the header file, leaving implementation in .cpp file


// internal function to find precedence of the operator
int Calculator::precedence(std::string input){
	// in case of negative number, character count will be more than one
	if(input.length() > 1){
		return 0;
	}
	char c = input[0];
	switch (c) {
		case '+':
		case '-':
			return 1;
		case '/':
		case '%':
		case '*':
			return 2;
		// these () are special cases
		case '(':
			return -1;
		case ')':
			return -2;
		default:
			return 0;
	}
}

// evaluates postfix expression from a queue
int Calculator::evaluate(Queue<Command*> post) {
	Stack<int> values;
	while (!post.is_empty()){
		try { 
			post.dequeue()->execute(&values);
		} catch (char *c) {
			std::cout << c << "\n";
		}
	}
	return values.top();
}

// converts infix to postfix 
Queue<std::string> Calculator::inToPost(Queue<std::string> pre) {
	Stack<std::string> opStack;
	Queue<std::string> infix;
	std::string curChar;

	while(!pre.is_empty()){
		curChar = pre.dequeue();
		// logic done using a switch statement for parsing		
		switch (precedence(curChar)) {
			case 1:
			case 2:
				while(!opStack.is_empty() && precedence(curChar) <= precedence(opStack.top())){
					infix.enqueue(opStack.top());
					opStack.pop();
				} 
				opStack.push(curChar);
				break;
			case -1:
				opStack.push(curChar);
				break;
			case -2:
				while(precedence(opStack.top()) != -1){
					infix.enqueue(opStack.top());
					opStack.pop();
				}
				opStack.pop();
				break;
			default:
				infix.enqueue(curChar);
				break;
		}
		
	}

	while(!opStack.is_empty()){
		infix.enqueue(opStack.top());
		opStack.pop();
	}
	return infix;
}


