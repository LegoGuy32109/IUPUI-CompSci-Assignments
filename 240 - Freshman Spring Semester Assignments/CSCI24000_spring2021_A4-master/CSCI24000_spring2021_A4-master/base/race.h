#ifndef RACE_H_EXISTS
#define RACE_H_EXISTS

#include <string>
#include "horse.h"

class Race {
	private:
		Horse h[];
		int length;
	public:
		Race();
		Race(int length);
		void printLane(int horseNum);
		void start();
};

#endif
