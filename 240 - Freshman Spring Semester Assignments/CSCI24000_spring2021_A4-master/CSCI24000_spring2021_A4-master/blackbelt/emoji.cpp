//emoji.cpp
#include <string>
#include <iostream>

#include "emoji.h"

Emoji::Emoji(){
	Emoji::index = 0;
}

std::string Emoji::horse(){
	return "🐎";
}

std::string Emoji::avacado(){
        return "🥑";
}

std::string Emoji::meat(){
        return "🍖";
}

std::string Emoji::hamburger(){
        return "🍔";
}

std::string Emoji::taco(){
        return "🌮";
}

std::string Emoji::pancakes(){
        return "🥞";
}

std::string Emoji::hotdog(){
        return "🌭";
}

std::string Emoji::fries(){
        return "🍟";
}

std::string Emoji::cake(){
        return "🎂";
}
