//student.h
#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "date.h"
#include "address.h"
#include <string>

class Student {
	private:
		std::string* surname;
		std::string* givenName;
		Address* streetAddress;
		Address* address2;
		std::string* city;
		std::string* state;
		int* zipCode;
		Date* birthday;
		Date* graduation;
		float* GPA;
		int* hoursCompleted;
	public:
		Student();
		Student(std::string info);
		void setStudent(std::string info);
		std::string getReport();
		std::string getName();
		~Student();
};

#endif
