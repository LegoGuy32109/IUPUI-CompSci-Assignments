//main.cpp
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

#include "horse.h"
#include "race.h"
#include "shop.h"

std::string foodImages[] = {"🥑","🍖","🍔","🌮","🥞","🌭","🍟","🎂"};
std::string foodNames[] = {"avocado","meat","hamburger","taco","pancakes","hotdog","fries","cake"};
std::string horses[] = {"Buttstallion", "Batman: the horse", "Juan", "Rodreigo", "Fluttershy", "E", "Papa's Delicate Condition", "Krystallnacht", "Mr. Fasthorse", "Nice N' Sticky", "Stinkfinger", "If Mandy Patankin Was A Horse", "Ol' Felcher", "Lopez", "Benis", "Poopstain", "Hiroto II", "Honda Hatchback", "Jukeb0x", "Boopis", "Mark Cuban", "Markiplier", "buttHat", "Andy Harris' Fursona", "Aquaphor", "BLUE", "Dasani", "Diamond Ore Block", "Fishy Food", "Bi🅾rn", "Morg Pallagius the Wise", "My cat is licking the door", "https://reddit.com", "Elongated Musket", "TeTrIs?", "Garfield", "Lasaga", "Mfw 😜", "Dogg", "''", "S aduko", "6oX433321"};
int prices[] = {5,20,4,3,11,4,3,30};
int inventory[] = {15,10,12,20,10,30,40,3};
int playerWallet = 100;
std::string playerName = "";
std::string playerHorse = "";

void shop();
void setup();
void setHorseName();
void showHorses();
void menu();

Race*r = new Race();
int main() {
	srand(time(NULL));
	setup();
	showHorses();
	r->start();
        menu();
}

void menu(){
	std::cout << "\nWould you like to...\n";
	std::cout << "[1] - Enter another race\n";
	std::cout << "[2] - Buy some food for your horse\n";
	std::cout << "[3] - This game sucks, I'd like to leave\n";
	
	std::cout << "Enter number of your choice :";
	std::string input;
	getline(std::cin, input);
	if(input =="1"){
		r->start();
		menu();
	}else if(input=="2"){
		shop();
	} else if(input=="3"){
		std::cout << "Sorry to see you go, bye!\n";
		exit(EXIT_FAILURE);
	} else {
		std::cout << "\nSorry, I didn't understand that, could you try again?\n";
		menu();
	}
}

void showHorses(){
	std::cout<<"\nThe race is about to start, here are our challengers!!\n";
	std::string curRace[5];
	curRace[0]=playerHorse;
	for(int i = 1; i<5; i++){
		curRace[i]=horses[rand()% (sizeof(horses)/sizeof(horses[0])) ];
	}
	for(int i = 0; i<5; i++){
		std::cout << "\nHorse " << i << ": " << curRace[i] << "  ";
		if (i == 0) {
			std::cout <<"(that's you!)   ";
		}
		std::cout <<"Determination: "<< rand()%40+20 << ", Speed: " << rand()%30+2;
		std::cout << "\n";
	}
	std::cout << "\n";
	nanosleep((const struct timespec[]){{0, 6000000000L}}, NULL);
}
void setup(){
	std::cout << "\n\nWelcome to HorseRacer! What is your name?\n: ";
	getline(std::cin, playerName);
	std::cout << "\n" << playerName << ", are you sure? (1-yes 2-no)\n: ";
	std::string input;
	getline(std::cin, input);
	if(input=="1"){
		std::cout << "Splendid! Now let's name your horse!\n";
		setHorseName();	
	} else if(input=="2"){
		std::cout << "I see, well let's start over...\n";
		setup();
	} else {
		std::cout << "I didn't understand that, let's try again...\n";
		setup();
	}
}

void setHorseName(){
	std::cout <<"What would you like to name the little guy? 🐴 " << "\n: "; 
	getline(std::cin, playerHorse);
	std::cout << "\n" << playerHorse << ", are you sure? (1-yes 2-no)\n: ";
	std::string input;
	getline(std::cin, input);
	if(input=="1"){
		std::cout << "Wonderful! Now let's see how he does in a race!\n";
	} else if(input=="2"){
		std::cout << "Oh thank goodness, ok let's start over...\n";
		setHorseName();
	} else {
		std::cout << "I didn't see that as a 1 or 2, so let's do this over...\n";
		setHorseName();
	}
}

void shop(){
	int length = 8;
        std::cout<<"\nWelcome to the Horse Food shoppe! What can I get you today? What'll it be?\n";
        for(int i =0; i< 8; i++){
                if(inventory[i]<=0){
			std::cout<<i+1<<") Sorry out of stock :( "<<foodImages[i]<<"\n";
		} else{
			std::cout<<i+1<<") "<<foodNames[i]<<" "<<foodImages[i]<< " [x"<<inventory[i]<<"]\n";
		}
        }
        std::cout << "9) I'd like to leave please\n";
        std::cout << "You have $"<<playerWallet<<" in your wallet\n";
        std::cout << "Type the number of the item you want to buy: ";
        int input;
        std::cin >> input;
        if(input>=1&&input<=9){
                if(input==9){
                        std::cout << "Sorry to see you go, come again soon!\n";
                        menu();
                }else if(playerWallet<prices[input-1]){
                        std::cout << "Um, come back when you're a little, ah, richer!\n";
                        shop();
                }else if(playerWallet>=prices[input-1]&&inventory[input-1]>0){
                        std::cout << "You purchased 1 "<<foodNames[input-1]<<foodImages[input-1]<<"!\n";
			inventory[input-1]--;
                        playerWallet -= prices[input-1];
                        shop();
                }else {
			std::cout << "That item is out of stock, apologies!!\n";
			shop();
		}
        }else{
                std::cout << "\nHuh?\nSorry, I didn't understand that, could you try again?\n";
                shop();
        }
}

