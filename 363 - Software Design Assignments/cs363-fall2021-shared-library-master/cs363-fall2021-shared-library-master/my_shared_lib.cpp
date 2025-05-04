// my_shared_lib.cpp, see header for source

#include "my_shared_lib.h"
#include <iostream>

void print_message (const std::string & msg)
{
	std::cout << msg << "\n";
}

Greeting::Greeting (void) {}
Greeting::~Greeting (void) {}

void Greeting::say_message (const std::string & msg)
{
	std::cerr << msg << "\n";
}
