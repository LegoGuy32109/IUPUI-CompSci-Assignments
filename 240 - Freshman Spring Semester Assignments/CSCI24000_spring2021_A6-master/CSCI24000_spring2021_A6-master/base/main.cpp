// main.cpp
#include <iostream>
#include "date.h"
#include "address.h"
#include "student.h"
#include <string>
#include <fstream>
#include <sstream>

int main(){
	/*
 *	Testing for date and address classes
	Date* d = new Date();
	std::cout << d->getDate() << "\n";
	
	Date* d2 = new Date(2,61,2020);
	std::cout << d2->getDate() << "\n";
	d2->setDate(6, 12, 2001);
	std::cout << d2->getDate() << "\n";

	
	Address* a2 = new Address(4, "hehe squee");
	std::cout << a2->getAddress() << "\n";
	a2->setAddress(41, "biggersqueeee", "num 312");
	std::cout << a2->getAddress() << "\n";
	
	
	delete(d);
	delete(d2);	
	delete(a2);	
	*/	


	std::ifstream inFile;
	std::ifstream counterFile;
	std::string line;
	std::stringstream inText;
	std::ofstream outFile;

	counterFile.open("students.dat");
	int counter = 0;
	for (int i = 0; getline(counterFile, line); i++){
		counter++;
	}
	counterFile.close();
	// std::cout << "making array of size " << counter << "\n";
	Student *sA = new Student[counter];
 
	inFile.open("students.dat");
	counter = 0;
	while(getline(inFile, line)) {
		//Student *s = new Student(line);		
		sA[counter].setStudent(line);  
		counter++;	
	}
	

	// std::cout << "Just finished adding Student " << counter << "\n";
	inFile.close();
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
	delete[] sA;
	// delete s;	

}
