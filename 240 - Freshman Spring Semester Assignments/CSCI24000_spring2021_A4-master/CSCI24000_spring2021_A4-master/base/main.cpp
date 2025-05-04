//main.cpp
#include <iostream>
#include <stdlib.h>
#include "horse.h"
#include "race.h"


int main() {
	int seed;
	std::cout << "Please enter a random seed: ";
	std::cin >> seed;
	srand(seed);

	Race *r = new Race();
	r->start();
}

