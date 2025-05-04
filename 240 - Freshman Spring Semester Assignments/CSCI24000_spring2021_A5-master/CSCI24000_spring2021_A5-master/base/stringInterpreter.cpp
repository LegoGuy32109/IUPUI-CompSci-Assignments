//stringInterpreter.cpp
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

int main(){
	
	std::ifstream inputFile;
	std::ofstream outputFile;
	std::stringstream inputText;
	std::string outputText;
	int anInt;
	int anInt2;
	int anInt3;
	char someChar; // this is to weed out the commas
	
	inputFile.open("input.txt");
	std::string item;
	while (getline(inputFile, item)) {
		
		inputText.clear();
		inputText.str(""); // set to empty string after clear

		inputText << item;
		// gets the line of 3 integers seperated by commas
		inputText >> anInt >> someChar >> anInt2 >> someChar >> anInt3;
		// for debugging
		//std::cout << anInt << " " << anInt2 << " " << anInt3 << " <- into this\n";
		std::string word;
		getline(inputFile, word); // this gets the next line after the integers, the word
		for(int i=0; i<anInt+anInt2+anInt3; i++){
			outputText+=word;
			outputText+=",";
		}
		outputText = outputText.substr(0,outputText.length()-1);
		// get rid of last comma	
		outputText += "\n";
	}
	inputFile.close();
	
	outputFile.open("output.txt");
        // for depugging, this prints everything in output.txt
	// std::cout << "I am outputting this:\n" << outputText << "\n";
	outputFile << outputText;
        outputFile.close();
	
}
