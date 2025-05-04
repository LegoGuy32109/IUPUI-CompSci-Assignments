//shop.h

#ifndef SHOP_H_EXISTS
#define SHOP_H_EXISTS

#include <string>

class Shop {
	private:
		std::string foodImages[];
		std::string foodNames[];
		int prices[];
		int inventory[];
	public:
		Shop();
		int display(int playerWallet);
};

#endif
		
