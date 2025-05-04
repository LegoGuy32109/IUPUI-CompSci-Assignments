// driver.cpp main code to get input from user and display computer output
#include <iostream>
#include <sstream> // for input of expressions
#include "Stack.h"
#include "Queue.h"

#include "Component.h"
#include "Calculator.h"


// exit phrase is by default QUIT, but it could be changed
const std::string exitPhrase = "QUIT";

int main() {
	Calculator calc = Calculator();

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

		// this chain will take a string and return an int of the correct evaluation
		std::cout << calc.evaluate(input);

		std::cout << "\n";
	}	

	return 0;
}
