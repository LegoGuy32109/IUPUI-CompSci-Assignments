#include <iostream>
#include "Array.h"
#include "Fixed_Array.h"
#include "Stack.h"
#include "Queue.h"
//#include "Base_Array.h"
class TestObj {
	private:
	std::string value;
	int coolNum;

	public:
	TestObj(){
		value = "nah";
		coolNum = 69;
	}
	TestObj(std::string newVal, int num){
		value = newVal;
		coolNum = num;
	}
	std::string getString(){
		return value;
	}	
	int getNum(){
		return coolNum;
	}
};

int main() {
	

	// Array testing
	Array<char> cool = Array<char>(20, 'f');
	Array<char> cool2 = cool;
	std::cout << cool[2] << "\n";
	cool[2] = 'r';
	std::cout << cool[2] << "\n";
	std::cout << cool2.get(2) << "\n";
	cool2[1] = 'w';
	std::cout << cool2[1] << "\n";
	cool.resize(5);
	
	Array<int> huh = Array<int>(3);
	huh.set(1, 43);
	std::cout << " " << huh[1] << "\n";
	Array<int> huh2 = Array<int>(huh);
	std::cout << "Size: " << huh2.size() << "\n"; 

	// Fixed_Array testing	
	Fixed_Array<std::string, 3> justCheese;
	justCheese.fill("Cheese");
	for(int i = 0; i<3; i++){
		std::cout << justCheese[i] << " ";
	}
	std::cout << "\n";
	Fixed_Array<std::string, 6> words = Fixed_Array<std::string, 6>();
	words[0] = "cool!";
	Fixed_Array<std::string, 6> words2 = words;
	std::cout << words[0] << " " << words2[0] << "\n";
	words2[4] = "yooO";
	words[5] = "Neat!";
	std::cout << words[5] << "\n";
	std::cout << "'Neat!' is here: " << words.find("Neat!") << "\n";
	words = words2;	
	std::cout << words[4] << " " << words[5] << " " << words[0] << "\n";
	std::cout << "'Neat!' is (after being overwritten) here: " << words.find("Neat!") << "\n";
	
	// stack testing	
	Stack<int> s = Stack<int>();
	s.push(9);
	s.push(20);
	s.push(3);
	std::cout << s.top() << "\n";
	s.pop();
	std::cout << s.top() << "\n";
	std::cout << "Is stack empty? (NO) " << s.is_empty() << "	size: " << s.size() << "\n";
	s.clear();
	std::cout << "Is stack empty? (YES) " << s.is_empty() << "	size: " << s.size() << "\n";

	Stack<std::string> stringStack = Stack<std::string>();
	stringStack.push("stack ;)");
	stringStack.push("a");
	stringStack.push("I am");
	stringStack.push("Hey");
	Stack<std::string> otherStringStack(stringStack);
	otherStringStack.push("Hey");
	Stack<std::string> otherOtherStringStack = stringStack;
	while(!stringStack.is_empty()){
		std::cout << stringStack.top() << " ";
		stringStack.pop();
	}
	std::cout << "\n";
	while(!otherStringStack.is_empty()){
		std::cout << otherStringStack.top() << " ";
		otherStringStack.pop();
	}
	std::cout << "\n";
	while(!otherOtherStringStack.is_empty()){
		std::cout << otherOtherStringStack.top() << " ";
		otherOtherStringStack.pop();
	}
	std::cout << "\nThese statements should have an extra hey in the middle\n";
	try {
		s.top();
	} catch(std::exception e){
		std::cout << "The array was empty when trying to grab top element\n";
		std::cout << e.what() << "\n";
	}
	try {
		s.pop();
	} catch(...){
		std::cout << "The array was empty when trying to pop()\n\n";
	}
	// custom ADT stack testing
	TestObj t = TestObj("Hey", 3);
	Stack<TestObj> to = Stack<TestObj>();
	to.push(t);
	std::cout << to.top().getString() << "\n";
	for(int i = 200; i>0; i--){
		to.push(TestObj("wah", i));
		if(i%5 == 0){
			to.pop();
		}
		std::cout << to.top().getNum() << " ";
	}
	std::cout << "\n";

	// queue testing
	Queue<char> q = Queue<char>();		
	q.enqueue('H');
	q.enqueue('A');
	q.enqueue('!');
	Queue<char> q2(q);
	Queue<char> q3 = q;
	std::cout << "is queue empty? (NO) " << q.is_empty() << "	size: " << q.size() << "\n";
	q.clear();	
	std::cout << "is queue empty? (YES) " << q.is_empty() << "	size: " << q.size() << "\n";	
	while(!q2.is_empty()){
		std::cout << q2.dequeue() << " ";
	}
	std::cout << "\n";
	for(int i = 0; i< 30; i++){
		q3.enqueue('*');
	}
	q3.enqueue('!');
	while(!q3.is_empty()){
		std::cout << q3.dequeue() << " ";
	}
	std::cout << "\n";
	// enqueue and dequeue after each other
	Queue<float> numQueue = Queue<float>();
	for(int i = 0; i<100; i++){
		numQueue.enqueue(i+0.5);
		if(i%3==0){
			numQueue.dequeue();
		}
	}
	while(!numQueue.is_empty()){
		std::cout << numQueue.dequeue() << " ";
	}
	std::cout << "\n";
	try{
		q.dequeue();
	}catch (std::exception e){
		std::cout << "The queue was empty when trying to dequeue\n\n";
	}

}

