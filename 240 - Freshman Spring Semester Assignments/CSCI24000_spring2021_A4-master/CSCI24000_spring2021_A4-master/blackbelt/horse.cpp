//horse.cpp
#include <iostream>
#include <string>
#include "horse.h"
#include <stdlib.h>

Horse::Horse(){
	Horse::position = 0;
	Horse::percentChance = 45;
	Horse::superChance = 4;
}

void Horse::advance(){
	int theNum = rand()%100;
	// The percentChance and superChance are always 0 for some reason
	// std::cout << "theNum "<<theNum<<" percentChance "<<percentChance;
	if(rand()%2==1){
		Horse::position++;
		//std::cout<<"Move one";
		if(theNum<=superChance){
			std::cout<<"SUPER JUMP";
			Horse::position++;
		}
	}
	// std::cout<<"the num "<<theNum<<" horse pos "<<position;
}

int Horse::getPosition(){
	return position;
}

void Horse::setPosition(int newPos){
	Horse::position=newPos;
}

int Horse::getPercentChance(){
	return percentChance;
}

void Horse::setPercentChance(int newPercent){
	percentChance = newPercent;
}

int Horse::getSuperChance(){
	return superChance;
}

void Horse::setSuperChance(int newPercent){
	superChance = newPercent;
}
