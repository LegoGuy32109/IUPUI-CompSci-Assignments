// $Id: Array.cpp 820 2011-01-17 15:30:41Z hillj $

// Honor Pledge:
//		Josh Hale
// I pledge that I have neither given nor receieved any help
// on this assignment.

#include "Array.h"
#include <stdexcept> // for throwing exceptions
#include <iostream> // for std

Array::Array (void) :
cur_size_(10), 
max_size_(10),
data_(new char[10])
// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE member variables initalized on seperate lines, so errors can be more descriptive if initialized incorrectly 
{
}

Array::Array (size_t length) :
cur_size_(length),
max_size_(length),
data_(new char[length])

// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE member variables initalized on seperate lines, so errors can be more descriptive if initialized incorrectly 
{
}

Array::Array (size_t length, char fill) :
cur_size_(length),
max_size_(length),
data_(new char[length])

// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE member variables initalized on seperate lines, so errors can be more descriptive if initialized incorrectly 
{
	for(int i = 0; i<length; i++){
		data_[i] = fill;
	}
}

Array::Array (const Array & array) :
cur_size_(array.cur_size_),
max_size_(array.cur_size_),
data_(new char[array.cur_size_])

// COMMENT Initialize all member variables in the base member initialization section
// of the constructor on its own line. Otherwise, it is hard to know what initialization
// has an error since it will not have its own unique line number.

// RESPONSE I am looking at my initalizaition for member variables here, and each one appears to be on it's own line. Feel free to show me the flaw in my logic
{
	for(int i=0; i<cur_size_; i++){
        // COMMENT Use the index operator when accessing data (i.e., data_[i])
	
	// RESPONSE I now use the index operator rather than *(data_+i)
		data_[i] = array.get(i);
	}
}

// if it's created with the new keyword, delete it
Array::~Array (void)
{
  delete [] data_;
}

// return a deep copy of itself if it's on right hand side, get overwritten by rhs if on left hand side
const Array & Array::operator = (const Array & rhs)
{
    // COMMENT Check for self assignment first.

    // RESPONSE I now check for self assignment first and prevent it
    
	// this object is on the right hand side, stop a self assignment
	if(this == &rhs){
		return * this;
	}

	// this object is being overwritten
	delete [] data_;
	data_ = new char [rhs.cur_size_];
	cur_size_ = rhs.cur_size_;
	max_size_ = rhs.cur_size_;		
	for(int i = 0; i<cur_size_; i++){
		data_[i] = rhs.get(i);
	}
		
	 
    // COMMENT The assignment operator needs to create a deep copy of the source
    // array. Otherwise, the copy will share a pointer with the original. When one goes out
    // of scope, the other will eventually crash.

    // RESPONSE The new array is being created by copying all the atributes from the right hand side
}

char & Array::operator [] (size_t index)
{
    // if the index is out of bounds, throw out_of_range exception, otherwise return data at that index
    if(index > cur_size_ - 1){
        throw std::out_of_range("You're out of range dude");
    }

    // COMMENT Use the index operator when accessing data (i.e., data_[i])

    // RESPONSE I now use the index operator rather than *(data_+i)
    return data_[index];
  
  
}

const char & Array::operator [] (size_t index) const
{
    // same as above
    if(index > cur_size_ - 1){
        throw std::out_of_range("You're out of range dude");
    }
    
    // COMMENT Use the index operator when accessing data (i.e., data_[i])
 
    // RESPONSE I now use the index operator rather than *(data_+i)
    return data_[index];
}

char Array::get (size_t index) const
{
    // same as above, using the .get() framework
    if(index > cur_size_ - 1){
        throw std::out_of_range("You're out of range dude");
    }
    
    // COMMENT Use the index operator when accessing data (i.e., data_[i])

    // RESPONSE I now use the index operator rather than *(data_+i)
    return data_[index];
}

// write the value at that specific index, if index isn't valid, throw out_of_range exception
void Array::set (size_t index, char value)
{
  if(index > cur_size_ - 1){
    throw std::out_of_range("You're out of range dude");
  }
    
    // COMMENT Use the index operator when accessing data (i.e., data_[i])

    // RESPONSE I now use the index operator rather than *(data_+i)
    data_[index] = value;
}

void Array::resize (size_t new_size)
{
	// create new char array of defined size if new_size is bigger then currently allocated in max_size_
	if(new_size > max_size_){
		// create pointers to store new data and delete old data	
		char * tempData = new char[new_size];
		char * oldData;
		for(int i =0; i<cur_size_; i++){

            // COMMENT Use the index operator when accessing data (i.e., data_[i])

	    // RESPONSE I now use the index operator rather than *(data_+i)
			tempData[i] = data_[i];
		}
		// set the oldData pointer to current data, then change member vars, then set data_ to new tempData
		oldData = data_;
		cur_size_ = new_size;
		max_size_ = new_size;
		data_ = tempData;
		// delete pointer to clean up old data
		delete [] oldData;
	// if size is smaller then current allocated, just lower cur_size_ preserving original contents
	}else if (new_size < max_size_){
		cur_size_ = new_size;
	}
	
}

// search for first occurance of ch in array, if not in there return -1
int Array::find (char ch) const
{
	for(int i=0; i<cur_size_; i++){
        // COMMENT Use the index operator when accessing data (i.e., data_[i])

	// RESPONSE I now use the index operator rather than *(data_+i)
		if(data_[i]==ch){
			return i;
		}
	}
	return -1;
}

// same as above, but this time start searching from a specified index. If index not valid throw out_of_bounds exception
int Array::find (char ch, size_t start) const
{
	if(start > cur_size_ - 1){
                throw std::out_of_range("You're out of range dude");
        }

	for(int i=start; i<cur_size_; i++){
        // COMMENT Use the index operator when accessing data (i.e., data_[i])

	// RESPONSE I now use the index operator rather than *(data_+i)
		if(data_[i]==ch){
			return i;
		}
	}
	return -1;
}

// if the contents of the array are equivilant to each other
bool Array::operator == (const Array & rhs) const
{
    // COMMENT Check for self comparison first.

    // RESPONSE I now check for self comparison, and if it is then they are the same Arrays and return true
	if(this == &rhs){
		return true;
	}
	// if the sizes aren't the same, then they must be different
	if(cur_size_ == rhs.cur_size_){
		for(int i = 0; i< cur_size_; i++){
            // COMMENT Use the index operator when accessing data (i.e., data_[i])

	    // RESPONSE I now use the index operator rather than *(data_+i)
			// if the elements at the same spot ever differ, then they must be different
			if(rhs.get(i) != data_[i]){
				return false;
			}
		}
		// for every element index checked and not false yet then it must be true
		return true;
	}
	return false;
}

// just return opposite of the == operator
bool Array::operator != (const Array & rhs) const
{
	return !(* this == rhs);
}

// go through every element and fill it with ch
void Array::fill (char ch)
{
  for(int i = 0; i < cur_size_; i++){
      // COMMENT Use the index operator when accessing data (i.e., data_[i])

      // REPONSE yeah I get it, I fixed it
    data_[i] = ch;
  }
}

void Array::shrink (void)
{
	// similar to resize(), but this time I'm saving space my making data_ a tinier char array
	if(cur_size_ < max_size_){
		char * tempData = new char[cur_size_];
		char * oldData;
		for(int i = 0; i<cur_size_; i++){
			tempData[i] = data_[i];	
		}
		
		oldData = data_;
		data_ = tempData;
		max_size_ = cur_size_;
		delete [] oldData;		
	} 
}

// set the Array to be the reverse of itself, first element is last, 2nd is 2nd last, so on.
void Array::reverse (void)
{
    // COMMENT There is no need to create a copy of the array to reverse its contents

    // RESPONSE So that's why you've got the PHD, I now swap the beginning and ending parts of the Array
	for(int i = 0; i<cur_size_/2; i++){
		char tempChar = data_[i];
		data_[i] = data_[cur_size_-1-i];
		data_[cur_size_-1-i] = tempChar;
	} 
}

// return a shallow copy of an Array with the index starting at begin if the slice isn't feasible throw out_of_range exception 
Array Array::slice (size_t begin) const
{
	if(begin > cur_size_ - 1){
    		throw std::out_of_range("You're out of range dude");
  	}

	Array output(cur_size_ - begin);
	for(int i = begin; i<cur_size_; i++){
		output[i] = data_[i];
	}

	return output;
}

Array Array::slice (size_t begin, size_t end) const
{
	// making sure the slice can return a feasible Array
	if(begin > cur_size_ - 1 || begin > end || end > cur_size_ -1){
                throw std::out_of_range("Your range is messed up man");
        }
	Array output(end - begin);
        for(int i = begin; i<end; i++){
                output[i] = data_[i];
        }

        return output;
	
}
