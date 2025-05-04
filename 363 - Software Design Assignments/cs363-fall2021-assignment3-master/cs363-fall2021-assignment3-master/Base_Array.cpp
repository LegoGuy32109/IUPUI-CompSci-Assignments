// Base_Array.cpp
// Written by Josh Hale to be extended into Array and Fixed_Array

#include "Base_Array.h"
#include <stdexcept>	// for std::out_of_bounds exception

const size_t DEFAULTSIZE = 10; // for deafault size of Array

// Base_Array
//
template <typename T>
Base_Array <T>::Base_Array (void) :
cur_size_(DEFAULTSIZE),
max_size_(DEFAULTSIZE),
data_(new T [DEFAULTSIZE])
{
	// handeled by initiallizers
}

// Base_Array (size_t)
//
template <typename T>
Base_Array <T>::Base_Array (size_t length) :
cur_size_(length),
max_size_(length),
data_(new T [length])
{
	// handeled by initiallizers
}

// Base_Array (size_t, T)
//  
template <typename T>
Base_Array <T>::Base_Array (size_t length, T fill) :
cur_size_(length),
max_size_(length),
data_(new T [length])
{
	for(int i =0; i<length; i++){
		data_[i] = fill;
	}
}

// Base_Array (const Base_Array &)
//
template <typename T>
Base_Array <T>::Base_Array (const Base_Array & bArray) :
cur_size_(bArray.cur_size_),
max_size_(bArray.cur_size_),
data_(new T [bArray.cur_size_])
{
	for(int i = 0; i<cur_size_; i++){
		data_[i] = bArray.data_[i];
	}
}

// ~Base_Array
//
template <typename T>
Base_Array <T>::~Base_Array (void)
{
	delete [] data_;
}

// operator =
//
template <typename T>
const Base_Array <T> & Base_Array <T>::operator = (const Base_Array & rhs)
{
	if(this == &rhs){
		return *this;
	}

	delete [] data_;
	data_ = new T [rhs.cur_size_];
	cur_size_ = rhs.cur_size_;
	max_size_ = rhs.cur_size_;
	for(int i = 0; i<cur_size_; i++){
		data_[i] = rhs[i];
	}
}

// operator []
//
template <typename T>
T & Base_Array <T>::operator [] (size_t index)
{
	if(index > cur_size_ -1){
		throw std::out_of_range("You're out of range dude");
	}
	return data_[index];
}

// operator []... but const!
//
template <typename T>
const T & Base_Array <T>::operator [] (size_t index) const
{
	if(index > cur_size_ -1){
		throw std::out_of_range("You're out of range dude");
	}
	return data_[index];
}

// get
//
template <typename T>
T Base_Array <T>::get (size_t index) const
{
	if(index > cur_size_ -1) {
		throw std::out_of_range("You're out of range dude");
	}

	return data_[index];
}

// set
// 
template <typename T>
void Base_Array <T>::set (size_t index, T value)
{
	if(index > cur_size_ -1) {
		throw std::out_of_range("You're out of range dude");
	}
	data_[index] = value;
}

// find (T, size_t)
//
template <typename T>
int Base_Array <T>::find (T value, size_t start) const
{
	if(start>cur_size_ -1){
		throw std::out_of_range("You're out of range dude");
	}
	for(int i =start; i<cur_size_; i++){
		if(data_[i]==value){
			return i;
		}
	}
	return -1;
}

// find (T)
//
template <typename T>
int Base_Array <T>::find (T value) const
{
	// trying to use the more complicated find method for simpler find method functionality
	return this->find(value, 0);
}

// operator ==
//
template <typename T>
bool Base_Array <T>::operator == (const Base_Array & rhs) const
{
	if(this == &rhs){
		return true;
	}

	if(cur_size_ == rhs.cur_size_){
		for(int i = 0; i<cur_size_; i++){
			if(rhs.get(i) != data_[i]){
				// mismatched data found, not equivalent
				return false;
			}
		}
		// all data is mirrored, they are equivalent
		return true;
	}
	// both sizes are inequal, not equivalent
	return false;
}

// operator !=
//
template <typename T>
bool Base_Array <T>::operator != (const Base_Array & rhs) const
{
	// return oppositre of == operator 
	return !(*this == rhs);
}

// fill
//
template <typename T>
void Base_Array <T>::fill (T value)
{
	for(int i = 0; i< cur_size_; i++){
		data_[i] = value;
	}
}

// end of given methods
