//race.cpp
#include <iostream>
#include <string>
#include <time.h>
#include "race.h"
#include "horse.h"
std::string horseEmoji = "🐎";
Race::Race(){
	Race::length = 15;
	Horse h[5];	
}

Race::Race(int length){
	Race::length = length;
	Horse h[5];
}

void Race::printLane(int horseNum){
	for(int j = 0; j<15; j++){
		if(j==14-Race::h[horseNum].getPosition()){
			std::cout << horseEmoji;
		} else {
			std::cout << "_";
		}
	}
	std::cout <<"\n";
}

void Race::start(){		
	// I added a function to horse to set it's position, for some weird reason whenever I got to start()
	// the first horse (0) had it's position set to 15. I don't know why, so in start I set the horse positions
	// to 0 before I print anything. I even checked in the contructors for race what the pos were for each
	// horse and they were all 0, for some reason start() has this stupid h[0].getPosition() = 15 everytime.
	
	for(int i = 0; i<5; i++){
		h[i].setPosition(0);
	}
	
	// for the last assignment I used a ss ostringstrem but I did something I thought was smarter here,
	// I have an integer that gets added the index multiplied by ten, even for 0 the logic still works,
	// and a few elif statements outside of the while the correct win statement is displayed
	int winner = -1;
	std::string lane = "=================\n";
	while(winner==-1){
		std::cout << lane;
		for(int i=0; i<5; i++){
			h[i].advance();
			printLane(i);
			if(h[i].getPosition()>=15){
				if(winner<0){
					winner = i;
				} else if(winner<9){
					winner+= i*10;
				} else if(winner<99){
					winner+= i*100;
				} else if(winner<999){
					winner+= i*1000;
				} else if(winner<9999){
					winner+= i*10000;
				}
			}			
		}
		std::cout << lane;
		nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
	}
	if(winner<9){
		std::cout << "Horse "<<winner%10<<" wins!\n";
	}else if(winner<99){
		std::cout << "Horse "<<winner%10<<" and Horse "<<winner/10%10<<" tie!\n";
	}else if(winner<999){
		std::cout << "Horse "<<winner%10<<", Horse "<<winner/10%10<<", and Horse "<<winner/100%10<<" have a three way tie!!\n";
	}else if(winner<9999){
		std::cout << "Wha- I- I- don't believe it.... there is a 4 way tie between Horses "<<winner%10<<", "<<winner/10%10<<", "<<winner/100%10<<", and "<<winner/1000%10<<"!! THIS HAS NEVER HAPPENED EVER!!!!\n"; 
	}else{
		std::cout<<"Either something went terribly wrong, or they all tied? Every horse crossed the finish line at the same time? All of them??? I need to lay down...\n";
	}
}

