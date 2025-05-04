// date.cpp

#include <iostream>
#include "date.h"
#include <string>
#include <sstream>

Date::Date(){
	Date::month = new int;
	*Date::month = 1;
	Date::day = new int;
	*Date::day = 1;
	Date::year = new int;
	*Date::year = 1000;
}

Date::Date(std::string info){
	std::stringstream ss;
	int tempMonth;
	int tempDay;
	int tempYear;
	char someChar;
	ss << info;
	ss >> tempMonth >> someChar >> tempDay >> someChar >> tempYear;
	Date::month = new int(tempMonth);
	Date::day = new int(tempDay);
	Date::year = new int(tempYear);
}

std::string Date::getDate(){
	std::stringstream ss;
	ss << *month << "/" << *day << "/" << *year;
	return ss.str();
}

Date::~Date(){
	// std::cout << "The date " << *month << "/" << *day << "/" << *year << " was deleted\n";	
	delete month;
	delete day;
	delete year;
	
}
