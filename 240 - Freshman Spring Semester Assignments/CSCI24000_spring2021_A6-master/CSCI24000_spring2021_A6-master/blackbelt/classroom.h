//classroom.h
#ifndef CLASSROOM_H_EXISTS
#define CLASSROOM_H_EXISTS

#include "student.h"
#include <string>


class Classroom {
	private:
		Student *sA;
	public:		
		Classroom();
		Classroom(int classSize);
		void setStudent(int index, std::string info);
		void getReport(std::string fileName);
		void getNames(std::string fileName);
		// void getGPAs(std::string fileName);
		~Classroom();
};

#endif
