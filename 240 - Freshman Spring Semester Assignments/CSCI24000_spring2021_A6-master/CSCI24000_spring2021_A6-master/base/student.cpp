//student.cpp

#include <iostream>
#include "student.h"
#include "date.h"
#include "address.h"
#include <string>
#include <sstream>


Student::Student(){
	/*
	Student::surname = new std::string("John");
	Student::givenName = new std::string("Smith");
	Student::streetAddress = new Address();
	Student::address2 = new Address();
	Student::city = new std::string("Springfield");
	Student::state = new std::string("Whyoming");
	Student::zipCode = new int;
	Student::birthday = new Date();
	Student::graduation = new Date();
	Student::GPA = new float;
	Student::hoursCompleted = new int;
	*/
}

Student::Student(std::string info){
	std::stringstream ss;
	char c;
        ss << info;

	std::string surname;
	std::string givenName;
	std::string a;
	std::string a2;
	std::string city;
	std::string state;
	int zipCode;
	std::string d;
	std::string d2;	
	float GPA;
	int hoursCompleted;

        getline(ss, surname, ',');
        getline(ss, givenName, ',');
        getline(ss, a, ',');
        getline(ss, a2, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        ss >> zipCode >> c;
        getline(ss, d, ',');
        getline(ss, d2, ',');
        ss >> GPA >> c >> hoursCompleted;



	Student::surname = new std::string(surname);
        Student::givenName = new std::string(givenName);
        Student::streetAddress = new Address(a);
        Student::address2 = new Address(a2);
        Student::city = new std::string(city);
        Student::state = new std::string(state);
        Student::zipCode = new int;
	*Student::zipCode = zipCode;
	Student::birthday = new Date(d);
	Student::graduation = new Date(d2);
        Student::GPA = new float;
	*Student::GPA = GPA;
        Student::hoursCompleted = new int;
	*Student::hoursCompleted = hoursCompleted;	

}

void Student::setStudent(std::string info){
	std::stringstream ss;
        char c;
        ss << info;

        std::string surname;
        std::string givenName;
        std::string a;
        std::string a2;
        std::string city;
        std::string state;
        int zipCode;
        std::string d;
        std::string d2;
        float GPA;
        int hoursCompleted;

        getline(ss, surname, ',');
        getline(ss, givenName, ',');
        getline(ss, a, ',');
        getline(ss, a2, ',');
        getline(ss, city, ',');
        getline(ss, state, ',');
        ss >> zipCode >> c;
        getline(ss, d, ',');
        getline(ss, d2, ',');
        ss >> GPA >> c >> hoursCompleted;
	
	Student::surname = new std::string(surname);
        Student::givenName = new std::string(givenName);
        Student::streetAddress = new Address(a);
        Student::address2 = new Address(a2);
        Student::city = new std::string(city);
        Student::state = new std::string(state);
        Student::zipCode = new int;
        *Student::zipCode = zipCode;
        Student::birthday = new Date(d);
        Student::graduation = new Date(d2);
        Student::GPA = new float;
        *Student::GPA = GPA;
        Student::hoursCompleted = new int;
        *Student::hoursCompleted = hoursCompleted;

}

std::string Student::getName(){
	std::stringstream ss;
	ss << *Student::surname << " " << *Student::givenName;
	return ss.str();	
}

std::string Student::getReport(){
	std::stringstream ss;
	ss << "\nStudent " << *Student::givenName << " " << *Student::surname << ":\n";
	ss << streetAddress->getAddress() << "\n";
	if(address2->getAddress() != ""){
		ss << address2->getAddress() << "\n";
	} 
	ss << *city << ", " << *state << ". " << *zipCode << "\n";
	ss << "Born " << birthday->getDate() << "\nGraduation Date "<<graduation->getDate() << "\n";        ss << "GPA: " << *GPA << "   Credits: " <<*hoursCompleted<<"\n";
	return ss.str();
}

Student::~Student(){
	// std::cout << "Student " <<*surname<<" "<<*givenName<<" was deleted.\n";
	delete surname;
	delete givenName;
	delete streetAddress;
	delete address2;
	delete city;
	delete state;
	delete zipCode;
	delete birthday;
	delete graduation;
	delete GPA;
	delete hoursCompleted;
}
