// main.cpp
#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"
#include "classroom.h"
#include <string>
#include <fstream>
#include <sstream>

int main(){

	std::ifstream inFile;
	std::ifstream counterFile;
	std::string line;
	std::stringstream inText;

	counterFile.open("students.dat");
	int counter = 0;
	for (int i = 0; getline(counterFile, line); i++){
		counter++;
	}
	counterFile.close();
	std::cout << "making classroom with "<< counter << " students\n";
        //Classroom *classroom = new Classroom(counter);
	Student *sA = new Student[counter];	
	inFile.open("students.dat");
	counter = 0;
	while(getline(inFile, line)) {
		
		sA[counter].setStudent(line);
	 
		 
		counter++;	
	}	
	inFile.close();
	

	//classroom->getReport("fullReport");
	//classroom->getNames("shortReport");
	std::ofstream outFile;
	outFile.open("fullReport.txt");	
	for(int i =0; i < counter;  i++){
		outFile << sA[i].getReport();
	}
	outFile.close();
	outFile.open("shortReport.txt");
	for(int i =0; i< counter; i++){
		outFile << "Student " << i+1 <<") "<< sA[i].getName()<< "\n";
	}
	outFile.close();
	
//	delete classroom;

}
