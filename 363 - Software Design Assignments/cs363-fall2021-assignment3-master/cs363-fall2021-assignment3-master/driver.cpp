// driver.cpp main code to get input from user and display computer output
#include <iostream>
#include <sstream> // for input of expressions
#include "Stack.h"
#include "Queue.h"

#include "Add_Operator.cpp"
#include "Sub_Operator.cpp"
#include "Mul_Operator.cpp"
#include "Div_Operator.cpp"
#include "Mod_Operator.cpp"
#include "Number.cpp"
#include "Stack_Factory.cpp"
#include "Command.h"
#include "Operator.h"
#include "Calculator.cpp"

// exit phrase is by default QUIT, but it could be changed
const std::string exitPhrase = "QUIT";


// I wanted this to be in Calculator.cpp but this is really giving me a headache with 'Command' type errors
Queue<Command*> toCommand(Queue<std::string> strings) {
	// get commands from factory
	Stack_Factory sf = Stack_Factory();
	Queue<Command*> commands;
	while(!strings.is_empty()){
		std::string curChar = strings.dequeue();
		if(curChar == "+")
			commands.enqueue(sf.makeAddOperator());
		else if(curChar == "-")
			commands.enqueue(sf.makeSubOperator());
		else if(curChar == "*")
			commands.enqueue(sf.makeMulOperator());
		else if(curChar == "/")
			commands.enqueue(sf.makeDivOperator());
		else if(curChar == "%")
			commands.enqueue(sf.makeModOperator());
		else {
		//	commands.enqueue(new Number(std::stoi (curChar)));
			std::stringstream ss;
			ss << curChar;
			int x = 0;
			ss >> x;
			commands.enqueue(new Number(x));
		}
	}
	return commands;
}

int main() {
		

	
	Calculator calc = Calculator();
	Queue<std::string> infix = Queue<std::string>();
	
	// while loop taking user input
	bool stopProgram = false;
	while(!stopProgram){
		std::string input;
		std::cout << "Enter expression: ('" << exitPhrase << "' to quit)\n";
		std::getline(std::cin, input);
		if(input == exitPhrase){
			stopProgram = true;
			continue;
		}
		std::stringstream ss(input);
		std::string c;
		while(std::getline(ss, c, ' ')){
			infix.enqueue(c);
		}

		// this part will call the calculator's postfix converter i
		try {
			std::cout << calc.evaluate(toCommand(calc.inToPost(infix))) << "\n";
		} catch (char *c) {
			std::cout << c << "\n";
		}
		infix.clear();
		std::cout << "\n";
	}	

	return 0;
}
