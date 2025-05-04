// my_shared_lib.h from tutorial here: https://cs.iupui.edu/~hilljh/faqs/shared-library.php

#include <string>
#include "my_shared_lib_export.h" // export header generated

MY_SHARED_LIB_Export
void print_message (const std::string & msg);

class MY_SHARED_LIB_Export Greeting
{
public:
	Greeting (void);
	~Greeting (void);

	void say_message (const std::string & msg);
};
