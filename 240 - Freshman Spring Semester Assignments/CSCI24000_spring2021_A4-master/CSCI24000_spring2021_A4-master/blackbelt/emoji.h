// emoji.h
#ifdef EMOJI_H_EXISTS
#define EMOJI_H_EXISTS
#include <iostream>
#include <string>

class Emoji {
	private:
		int index;
	public:
		Emoji();
		std::string horse();
		std::string avacado();
		std::string meat();
		std::string hamburger();
		std::string taco();
		std::string pancakes();
		std::string hotdog();
		std::string fries();
		std::string cake();
};

#endif

