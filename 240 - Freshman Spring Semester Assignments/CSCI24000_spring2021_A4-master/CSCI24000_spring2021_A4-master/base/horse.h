#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS	

#include <string>

class Horse {
	private:
		int position;
	public:
		Horse();
		void advance();
		int getPosition();
		void setPosition(int newPos);
};

#endif
