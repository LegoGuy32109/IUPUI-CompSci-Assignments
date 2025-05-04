// address.cpp

#include <iostream>
#include "address.h"
#include <string>

Address::Address(){
	Address::street = new std::string("10 Main street");
}

Address::Address(std::string info){
	Address::street = new std::string(info);
}

std::string Address::getAddress(){
	return *Address::street;
}

Address::~Address(){
	// std::cout << "The address "<<*street<<" was deleted.\n";
	delete Address::street;
}
