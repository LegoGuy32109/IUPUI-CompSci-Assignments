// $Id: Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//	Josh Hale
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
//#include <stdexcept>         // for std::out_of_bounds exception

//const size_t arrSIZE = 10; // default size for Array

//
// Array
//
template <typename T>
Array <T>::Array (void) : 
Base_Array<T>()
{

}

//
// Array (size_t)
//
template <typename T>
Array <T>::Array (size_t length) :
Base_Array<T>(length)
{
}

// 
// Array (size_t, T)
//
template <typename T>
Array <T>::Array (size_t length, T fill) :
Base_Array<T>(length, fill)
{
}

//
// Array (const Array &)
//
template <typename T>
Array <T>::Array (const Array & array) :
Base_Array<T>(array)
{
}

//
// ~Array
// runs default inherited class deconstructor
template <typename T>
Array <T>::~Array (void)
{
}

//
// operator =
//
template <typename T>
const Array <T> & Array <T>::operator = (const Array & rhs)
{
	// check if rhs is a reference to the current Array, if it is return self reference
	if(this == &rhs) {
		return * this;
	}
	// if not above, call the = operator for Base_Array
	Base_Array<T>::operator=(rhs);
}



//
// resize
//
template <typename T>
void Array <T>::resize (size_t new_size)
{
	if(new_size > this->max_size()){
		// create pointers to store new data and delete old data
		T * tempData = new T[new_size];
		T * oldData;
		for(int i = 0; i < this->size(); i++){
			tempData[i] = this->get(i);
		}
		// set oldData to current data, then change member vars, then set data_ to new tempData
		oldData = this->data_;
		this->max_size_ = new_size;
		this->cur_size_ = new_size;
		this->data_ = tempData;
		// delete old data by deleting pointer to it
		delete [] oldData;
	// if size is smaller then currently allocated, just lower cur_size_ or raise it to match
	}else if(new_size < this->max_size_){
		this->cur_size_ = new_size;
	}
}



// end of given file


