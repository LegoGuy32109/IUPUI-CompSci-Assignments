#ifndef DATE_H_EXISTS
#define DATE_H_EXISTS

#include <string>

class Date {
	private:
		int* month;
		int* day;
		int* year;

	public:
		Date();
		Date(std::string info);
		~Date();
		std::string getDate();
	
};

#endif
