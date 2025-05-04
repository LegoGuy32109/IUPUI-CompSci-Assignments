// shared_exe.cpp copied from bottom of tutorial https://cs.iupui.edu/~hilljh/faqs/shared-library.php

#include "my_shared_lib.h"

int main (int argc, char * argv [])
{
	// I had cool custom messages but I'll keep em hello world in case it's grade specific
	// print_message ("Hello, Shared Library!");
	print_message("Hello, World!");
	Greeting g;
	// g.say_message ("Why hello to you!");
	g.say_message("Hello, World!");
	return 0;
}
