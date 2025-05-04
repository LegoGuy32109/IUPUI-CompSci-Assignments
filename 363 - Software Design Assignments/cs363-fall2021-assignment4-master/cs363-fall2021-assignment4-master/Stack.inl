// -*- C++ -*-
// $Id: Stack.inl 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//  	Josh Hale
// I pledge that I have neither given nor received any help on
// this assignment.

//
// size
//
template <typename T>
inline
size_t Stack <T>::size (void) const
{
	// return size of array, which indicates number of elements
	return dataEnd;
}

//
// top
//
template <typename T>
inline
T Stack <T>::top (void) const
{
	// check if stack is empty, in that case throw empty_exception
	if(this->is_empty()){
		throw Stack::empty_exception();
	}
	// if not, return first element (top)
	return array.get(dataEnd-1);
}

//
// is_empty
//
template <typename T>
inline
bool Stack <T>::is_empty (void) const
{
	// check if array size is 0, if it is it's empty
	if(dataEnd==0){
		return true;
	}
	return false;
}
