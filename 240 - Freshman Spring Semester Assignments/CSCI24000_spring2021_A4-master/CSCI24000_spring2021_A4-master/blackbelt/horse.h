#ifndef HORSE_H_EXISTS
#define HORSE_H_EXISTS	

#include <string>

class Horse {
	private:
		int position;
		int percentChance;
		int superChance;
	public:
		Horse();
		void advance();
		int getPosition();
		void setPosition(int newPos);
		int getPercentChance();
		void setPercentChance(int newPercent);
		int getSuperChance();
		void setSuperChance(int newPercent);
};

#endif
