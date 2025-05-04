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
	float anInt;
	float anInt2;
	float anInt3;
	float allInts;
	char someChar; // this is to weed out the commas
	
	inputFile.open("input.txt");
	std::string item;
	while (getline(inputFile, item)) {
		allInts = 0;
		anInt = 0;
		anInt2 = 0;
		anInt3 = 0;
		inputText.clear();
		inputText.str(""); // set to empty string after clear
		// std::cout << "Turning this: " << item<<"\n";
		inputText << item;
		// gets the line of 3 integers seperated by commas
		inputText >> anInt >> someChar >> anInt2 >> someChar >> anInt3;
		// for debugging
		// std::cout << anInt << " " << anInt2 << " " << anInt3 << " <- into this\n";
		std::string word;
		getline(inputFile, word); // this gets the next line after the integers, the word
		// std::cout << "I print this: "<<word<< " " << allInts << " times\n";
		if(word==""){
			outputText += "EMPTY LINE\n";
			continue;
		}
		allInts = anInt + anInt2 + anInt3;
		if(allInts == 0){
			outputText += "AMOUNT OF TIMES = 0\n";
			continue;
		}else if(allInts<0){
			outputText += "AMOUNT OF TIMES NEGATIVE\n";
			continue;
		}
		for(int i=0; i<allInts; i++){
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
