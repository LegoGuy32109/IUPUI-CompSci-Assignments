//address.h
#ifndef ADDRESS_H_EXISTS
#define ADDRESS_H_EXISTS

#include <string>

class Address {
	private:
		std::string* street;
	public:
		Address();
		Address(std::string info);
		std::string getAddress();
		~Address();

};

#endif
