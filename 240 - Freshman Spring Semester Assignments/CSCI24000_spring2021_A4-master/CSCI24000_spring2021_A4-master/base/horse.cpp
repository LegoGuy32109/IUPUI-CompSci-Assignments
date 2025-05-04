//horse.cpp
#include <iostream>
#include <string>
#include "horse.h"
#include <stdlib.h>

Horse::Horse(){
	Horse::position = 0;
}

void Horse::advance(){
	if(rand()%2==1){
		Horse::position++;
	}
}

int Horse::getPosition(){
	return position;
}

void Horse::setPosition(int newPos){
	Horse::position=newPos;
}
