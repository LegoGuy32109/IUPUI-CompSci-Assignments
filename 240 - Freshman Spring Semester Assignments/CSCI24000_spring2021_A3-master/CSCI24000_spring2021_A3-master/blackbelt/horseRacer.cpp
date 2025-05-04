#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int lanes[] = {0,0,0,0,0};
int winner[] = {0, 0, 0, 0, 0};
const int laneLength = 15;
int lsLength = sizeof(lanes)/sizeof(lanes[0]);


std::string horse = "🐎";
std::string avacado = "🥑";
std::string meat = "🍖";
std::string hamburger = "🍔";
std::string taco = "🌮";
std::string pancakes = "🥞";
std::string hotdog = "🌭";
std::string fries = "🍟";
std::string cake = "🎂";


int playerWallet = 100;
std::string playerName = "PLAYER";
std::string playerHorse = "pHorse";
int playerStats[] = {0,0};

void setup(); 
int* setHorseStats();
void newRace();
void setHorseName();
std::string makeHorse();
void printLanes();
void horseMove(int, int, int);
void wait();
bool checkWinner();
int getWinners();

void sellResource();
void menu();
void shopMenu();


int main() {
	srand(time(NULL));
	setup();
	newRace();
	std::cout << "In main, new race over\n";
	menu();
}
/*
 *I am in bathroom
 *ping me on Disc if you need help
 *  Josh_da_guy#4961
 *This is for a blackbelt don't worry
 */


void menu(){
	std::cout << "\nWould you like to...\n";
	std::cout << "[1] - Enter another race\n";
	std::cout << "[2] - Buy some food for your horse\n";
	std::cout << "[3] - This game sucks, I'd like to leave\n";
	std::cout << "[4] - I need more money, could I sell something?\n";
	
	std::cout << "Enter number of your choice :";
	std::string input;
	getline(std::cin, input);
	if(input =="1"){
		newRace();
	}else if(input=="2"){
		shopMenu();
	} else if(input=="3"){
		std::cout << "Sorry to see you go, bye!\n";
		exit(EXIT_FAILURE);
	} else if(input =="4"){
		std::cout << "Well, your horse does produce a certain, uh, resource...\n";
		sellResource();
	} else {
		std::cout << "\nSorry, I didn't understand that, could you try again?\n";
		wait();
		menu();
	}
}

void sellResource(){
	std::string input;
	std::cout << "Are you sure you want to sell your horses'.. genetics... to the highest bidder?\n[1] - Yes, [2] - No\n: ";
	getline(std::cin, input);
	if(input=="1"){
		int price = rand()%11*3+10;
		std::cout << "You sold some of your horses' 'stuff' for $" << price << ".\n";
		playerWallet+=price;
		std::cout << "You now have $" << playerWallet <<". Nice.\n"; 
	}else if(input=="2"){	
		std::cout << "Understandable.\n";
	} else {
		std::cout << "I didn't understand what you said, could we try that again?\n";
		sellResource();
	}
	menu();	
}

void shopMenu(){
	std::string input;
	std::cout << "\nWelcome to the horse food shop! What'll it be?\n";
	std::cout << "[1] "<<avacado<<" avacado: $5,\n";	
	std::cout << "[2] "<<meat<<" cooked meat: $20,\n";	
	std::cout << "[3] "<<hamburger<<" hamburger: $4,\n";	
	std::cout << "[4] "<<taco<<" beef crunchy taco: $3,\n";	
	std::cout << "[5] "<<pancakes<<" pancakes: $11,\n";	
	std::cout << "[6] "<<hotdog<<" hotdog with musturd: $4,\n";	
	std::cout << "[7] "<<fries<<" large McDonalds fries: $3,\n";	
	std::cout << "[8] "<<cake<<" birthday cake: $30,\n";	
	std::cout << "[9] "<<hamburger<<" cheeseburger: $5,\n";
	std::cout << "[10] I'd like to leave please\n";
	std::cout << "\nYou have $" << playerWallet << " to spend\n";
	std::cout << "Type the number of the item you want to buy: ";
	getline(std::cin, input);
	if(input=="1"&&playerWallet>=5){
		std::cout << "Ok! You fed it to your horse\n";
		playerWallet-=5;
		playerStats[0]+= 3;
		playerStats[1]+= 1;
	}else if(input=="2"&&playerWallet>=20){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=20;
                playerStats[0]+= 10;
                playerStats[1]+= 2;

	}else if(input=="3"&&playerWallet>=4){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=4;
                playerStats[0]+= 1;
                playerStats[1]+= 0;

	}else if(input=="4"&&playerWallet>=3){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=3;
                playerStats[0]+= 1;
                playerStats[1]+= 0;

        }else if(input=="5"&&playerWallet>=11){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=11;
                playerStats[0]+= 3;
                playerStats[1]+= 1;

	}else if(input=="6"&&playerWallet>=4){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=4;
                playerStats[0]+= 1;
                playerStats[1]+= 0;

        }else if(input=="7"&&playerWallet>=3){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=3;
                playerStats[0]+= 0;
                playerStats[1]+= 0;

	}else if(input=="8"&&playerWallet>=30){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=30;
                playerStats[0]+= 15;
                playerStats[1]+= 3;

        }else if(input=="9"&&playerWallet>=5){
                std::cout << "Ok! You fed it to your horse\n";
                playerWallet-=5;
                playerStats[0]+= 2;
                playerStats[1]+= 1;

	}else if(input=="10"){
		std::cout << "Ok, thank you for coming in!\n";
		menu();
	}else {
		std::cout << "I didn't understand that, "<<input<<"? Try again.\n";
	}
	shopMenu();	
}

std::string makeHorse(){
	std::string names[] = {"Buttstallion", "Batman: the horse", "Juan", "Rodreigo", "Fluttershy", "E", "Papa's Delicate Condition", "Krystallnacht", "Mr. Fasthorse", "Nice N' Sticky", "Stinkfinger", "If Mandy Patankin Was A Horse", "Ol' Felcher", "Lopez", "Benis", "Poopstain", "Hiroto II", "Honda Hatchback", "Jukeb0x", "Boopis", "Mark Cuban", "Markiplier", "buttHat", "Andy Harris' Fursona", "Aquaphor", "BLUE", "Dasani", "Diamond Ore Block", "Fishy Food", "Bi🅾rn", "Morg Pallagius the Wise", "My cat is licking the door", "https://reddit.com", "Elongated Musket", "TeTrIs?", "Garfield", "Lasaga", "Mfw 😜", "Dogg", "''", "S aduko", "6oX433321"};
	int namesLength = sizeof(names)/sizeof(names[0]);
	return names[rand()%namesLength];
}

void newRace(){
	std::string horses[] = {"", "", "", "", ""};
	int horseDet[] = {0, 0, 0, 0, 0};
	int horseSpd[] = {0, 0, 0, 0, 0};
	
	for (int i=0; i<5; i++){
		lanes[i]=0;
		horses[i] = makeHorse();
	}
	
	horses[0] = playerHorse;
	horseDet[0] = playerStats[0];
	horseSpd[0] = playerStats[1];	
	for(int i = 1; i<5; i++){
		int* stats = setHorseStats();
		horseDet[i] = stats[0];
		horseSpd[i] = stats[1];
	}

	
	// display horses names
	std::cout<<"\nThe race is about to start, here are our challengers!!\n";
	for(int i = 0; i<5; i++){
		std::cout << "\nHorse " << i << ": " << horses[i] << "  ";
		if (i == 0) {
			std::cout <<"(that's you!)   ";
		}
		std::cout <<"Determination: "<< horseDet[i] << ", Speed: " << horseSpd[i];
		std::cout << "\n";
	}
	std::cout << "\n";
	nanosleep((const struct timespec[]){{0, 2000000000L}}, NULL);
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	wait();
	//display starting line
	printLanes();
	std::cout << "The horses have lined up, and they're set to go in \n";
	wait();
	std::cout << "3.. \n";
	wait();
	std::cout << "2.. \n";
	wait();
	std::cout << "1.. \n";
	wait();
	/*           nanosleep not work in for loop.
        for(int i=3; i<0; i--){
	nanosleep((const struct timespec[]){{0, 1000000000L}}, NULL);
		std::cout << i << ".. ";
	} */
	std::cout << "GO!!!!";
	printLanes();
	
	// Race em
	while(checkWinner()){
		for(int i =0; i<5; i++){
 			horseMove(i, horseDet[i], horseSpd[i]);
		}
		printLanes();
		wait();
	}		

	std::cout << "\nRace over\n";
	std::cout <<"Horse " << horses[getWinners()] << " won!\n";
	wait();
	wait();

	if(getWinners()!=0){
		std::cout << "Aw, it looks like you didn't win, hey, buy some food to make your horse better!\n";
	}else{
		std::cout <<"Hey you won! Awesome! You won 300 bucks!\n";
		playerWallet+=300;
	}
}

// chance for horses to move
void horseMove(int i, int horseDet, int horseSpd){
	
	// Don't move if past the finish line
	if(lanes[i]<14 && lanes[i]!=-1){
		// if determination stat works, % chance they do move at all
		if(rand()%100<=horseDet){
			lanes[i]++;
			// get speed num from very low speed stat
			int speedNum = rand()%100;
			// if speed stat makes it, go another space
			if(speedNum<=horseSpd){
				lanes[i]++;
				// if horse has a speed stat over 30 and make that, move again
				if(speedNum<=horseSpd-30){
					lanes[i]++;
				}
			}
		}
	} else if (lanes[i] != -1){
		lanes[i]=-1; 
	}
}

void wait(){
	nanosleep((const struct timespec[]){{0, 500000000L}}, NULL);
}	
int* setHorseStats(){
	static int stats[2];
	stats[0] = rand()%20+30;
	stats[1] = 40;
	return stats;
}

bool checkWinner(){
	int winners = 0;
	for(int i =0; i<5; i++){
		if(lanes[i] == -1){
			return false;
		}
	}
	return true;
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
	std::cout <<"What would you like to name the little guy? " << horse << "\n: "; 
	getline(std::cin, playerHorse);
	std::cout << "\n" << playerHorse << ", are you sure? (1-yes 2-no)\n: ";
	std::string input;
	getline(std::cin, input);
	if(input=="1"){
		playerStats[0] = rand()%30+10;
		playerStats[1] = rand()%5;
		std::cout << "Wonderful! Now let's see how he does in a race!\n";
	} else if(input=="2"){
		std::cout << "Oh thank goodness, ok let's start over...\n";
		setHorseName();
	} else {
		std::cout << "I didn't see that as a 1 or 2, so let's do this over...\n";
		setHorseName();
	}
}

int getWinners(){
	for(int i =0; i<5; i++){
		if(lanes[i]==-1){
			return i;
		}
	}
}

void printLanes(){
	std::string sideLane = "\n==================\n";
	std::cout << sideLane;
	int placeNum = 0;
	int winNum = 0;
	for(int i = 0; i<lsLength; i++){
		if(lanes[i]==-1){
			std::cout << horse << "_|";
		} else {
			std::cout << "__|";
		}
		for(int j = 0; j<laneLength; j++){
			if(lanes[i] == laneLength-j-1){
				std::cout << horse;
			} else {
				std::cout << "_";
			}
		}
		std::cout << "\n";
	}
	std::cout << sideLane;
}
