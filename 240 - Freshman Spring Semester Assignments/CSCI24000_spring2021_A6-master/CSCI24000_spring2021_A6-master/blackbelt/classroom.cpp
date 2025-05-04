//classroom.cpp

#include <iostream>
#include "classroom.h"
#include "student.h"
#include <string>
#include <sstream>
#include <fstream>

Classroom::Classroom(){
	
}

Classroom::Classroom(int classSize){
	Student *sA = new Student[classSize];
	
	std::cout << "Herm\n";
}

void Classroom::setStudent(int index, std::string info){
	std::cout << "Going to make student " <<index <<"with \n"<<info<<"\n";
	sA[index].setStudent(info); 
}

void Classroom::getReport(std::string fileName){
	std::ofstream outFile;
        fileName += ".txt";
	std::cout << "About to open " << fileName << "\n";
	outFile.open(fileName.c_str());
	std::cout << sizeof(sA)/sizeof(sA[0]) << "\n";
	for(int i =0; i< sizeof(sA)/sizeof(sA[0]); i++){
		outFile << sA[i].getReport();
	}
	outFile.close();	
}

void Classroom::getNames(std::string fileName){
	std::ofstream outFile;
        fileName += ".txt";
	outFile.open(fileName.c_str());
        for(int i =0; i< sizeof(sA)/sizeof(sA[0]); i++){
                outFile << sA[i].getName();
        }
        outFile.close();

}

Classroom::~Classroom(){
	delete[] sA;
}
