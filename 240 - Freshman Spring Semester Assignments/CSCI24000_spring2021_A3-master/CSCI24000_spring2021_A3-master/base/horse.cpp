#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
// here for to_string() on i later

void printLanes();
void round();
bool checkWinner();
void whosWinner();

int lanes[] = {0,0,0,0,0};

int main() {
	int seed;
	std::cout << "Give me the seed...: ";
	std::cin >> seed;
	srand(seed);
	while(checkWinner()){
		std::cout << "\nPress enter to continue: \n";
		std::string noNeed;
		getline(std::cin, noNeed);
		round();
	}
	whosWinner();	
}

void printLanes(){
	for(int i = 0; i<5; i++){
		for(int j = 0; j<15; j++){
			if (lanes[i]==j){
				std::cout << i;
			} else {
				std::cout << ".";
			}
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void round(){
	for (int i=0; i<5; i++){
		if(rand()%2==1){
			lanes[i]++;
		}
	}
	printLanes();
}

bool checkWinner(){
	for (int i =0; i < 5; i++){
		if(lanes[i] >= 15){
			return false;
		}
	}
	return true;
}

void whosWinner(){
	int winners[] = {0,0,0,0,0};
	int wins = 0;
	std::string winText = "";
	
	
	for(int i = 0; i<5; i++){
		if(lanes[i]>=15){
			winText+="Horse ";
			std::ostringstream ss;
			ss << i;
			winText+= ss.str();
			winText+=" and ";
			wins++;
		}
	}
	// to remove the last "and ", leaving a space after the number
	winText = winText.substr(0,winText.length()-4);
	
	if(wins >1){
		winText+="tie";
	} else {
		winText+="wins";
	}
	std::cout << winText << "!\n";  
}
