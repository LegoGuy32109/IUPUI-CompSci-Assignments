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
	if (*month == 1){
		ss << "January ";
	} else if (*month == 2){
		ss << "February ";
	} else if (*month == 3){
                ss << "March ";
        }
 	else if (*month == 4){
                ss << "April ";
        }
 	else if (*month == 5){
                ss << "May ";
        }
 	else if (*month == 6){
                ss << "June ";
        }
 	else if (*month == 7){
                ss << "July ";
        }
 	else if (*month == 8){
                ss << "August ";
        }
 	else if (*month == 9){
                ss << "September ";
        }
 	else if (*month == 10){
                ss << "October ";
        }
 	else if (*month == 11){
                ss << "November ";
        }
	 else if (*month == 12){
                ss << "December ";
        } else{
		ss << "unknown ";
	}

	ss << *day << ", " << *year;
	return ss.str();
}

Date::~Date(){
	// std::cout << "The date " << *month << "/" << *day << "/" << *year << " was deleted\n";	
	delete month;
	delete day;
	delete year;
	
}
