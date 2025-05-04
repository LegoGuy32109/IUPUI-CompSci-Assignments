// $Id: Fixed_Array.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//  Josh Hale
// I pledge that I have neither given nor received any help
// on this assignment.

#include "Fixed_Array.h"
//
// Fixed_Array default
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (void) 
// default constructer of a Base_Array of type T and of size N called
: Base_Array<T>(N)
{		
}

//
// Fixed_Array copy contstructor 
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, N> & arr) 
// default copy constructer of a Base_Array is called
: Base_Array<T>(arr)
{
}

//
// Fixed_Array
//
template <typename T, size_t N>
template <size_t M>
Fixed_Array <T, N>::Fixed_Array (const Fixed_Array <T, M> & arr)
// if the other array is a different size, the other array is recreated to be a copy of the given array up to the current array's size  
: Array<T>(N)
{	
	// write in new values of copied array up to current size
	for(int i =0; i<this->cur_size_; i++){
		this->data_[i] = arr.get(i);
	}
}

//
// Fixed_Array
//
template <typename T, size_t N>
Fixed_Array <T, N>::Fixed_Array (T fill)
// call the Array fill constructor with a given size N and fill element
: Array<T>(N, fill)
{
}

//
// ~Fixed_Array
//	runs default base class deconstructor
template <typename T, size_t N>
Fixed_Array <T, N>::~Fixed_Array (void)
{	
}

//
// operator =
//
template <typename T, size_t N>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, N> & rhs)
{
	// check if rhs is a reference to the current Fixed_Array, is so just return self reference
	if(this == &rhs){
		return * this;
	}	
	// if not above, called the = operator for the Array class
	Base_Array<T>::operator=(rhs);
	
	
}

//
// operator =
// this operator is for a different size M
template <typename T, size_t N>
template <size_t M>
const Fixed_Array <T, N> & Fixed_Array <T, N>::operator = (const Fixed_Array <T, M> & rhs)
{
	// check if rhs is a reference to the current Fixed_Array, is so just return self reference
	if(this == &rhs){
		return * this;
	}	
	// if not above, called the = operator for the Array class, does not matter if different size it will be recreated to be larger
	Base_Array<T>::operator=(rhs);
}

