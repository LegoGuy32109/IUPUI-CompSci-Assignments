//shop.cpp
#include "shop.h"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <unistd.h>
#include <initializer_list>

Shop::Shop(){
	Shop::foodImages[] = {"🥑","🍖","🍔","🌮","🥞","🌭","🍟","🎂"};
	Shop::foodNames[] = {"avocado","meat","hamburger","taco","pancakes","hotdog","fries","cake"};
	Shop::prices[] = {5,20,4,3,11,4,3,30};
	Shop::inventory[] = {15,10,12,20,10,30,40,3}; 
}
int Shop::display(int playerWallet){
	int length = 8;
	std::cout<<"\nWelcome to the Horse Food shoppe! What can I get you today? What'll it be?\n";
	for(int i =0; i< 8; i++){
		std::cout<<i+1<<") "<<foodNames[i]<<" "<<foodImages[i]<< " [x"<<inventory[i]<<"]\n";
	}
	std::cout << "9) I'd like to leave please\n";
	std::cout << "You have $"<<playerWallet<<" in your wallet\n";
	std::cout << "Type the number of the item you want to buy: ";
	int input;
	getline(std::cin, input);
	if(input>=1&&input<=9){
		if(input==9){
			std::cout << "Sorry to see you go, come again soon!\n";
			return playerWallet;
		}else if(playerWallet<prices[input-1]){
			std::cout << "Um, come back when you're a little, ah, richer!\n";
			Shop::display(playerWallet);
		}else if(playerWallet>=prices[input-1]){
			std::cout << "You purchased 1 "<<foodNames[input-1]<<foodImages[input-1]<<"!\n";
			playerWallet -= prices[input-1];
			Shop::display(playerWallet);
		}
	}else{
		std::cout << "Sorry, I didn't understand that, could you try again?\n";
		Shop::display(playerWallet);
	}
}

