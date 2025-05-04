// $Id: Stack.cpp 827 2011-02-07 14:20:53Z hillj $

// Honor Pledge:
//     Josh Hale
// I pledge that I have neither given nor received any help
// on this assignment.

//
// Stack
//
template <typename T>
Stack <T>::Stack (void) :
// initalize array as a default size Array<T>(), indicate stack size 0 with data indexes
array(Array<T>()),
dataEnd(0)
{
}

//
// Stack
//
template <typename T>
Stack <T>::Stack (const Stack & stack) 
// initalize array as an Array object full with given data in stack parameter
: array(Array<T>(stack.size())),
dataEnd(stack.size())
{
	// loop through actual stack data by their indexes
	for(int i = 0; i<dataEnd; i++){
		array.set(i, stack.array.get(i));
	}
}

//
// ~Stack
// 
template <typename T>
Stack <T>::~Stack (void)
{
}

//
// push
//
template <typename T>
void Stack <T>::push (T element)
{	
    // COMMENT You current design of the stack is copying each element
    // over on location each time your push a new element onto the stack.
    // Unfortunately, this is an expensive operation—--especially if you
    // have a large number of elements on the stack. Improve your design
    // so that you are not copying each element every time you push a new
    // element onto the stack.
    
    // RESPONSE I now use an index to keep track of acutal data in the stack, and shift it around when I pop or push

	// is there space to add another element?
	if(dataEnd == array.size()){
		array.resize(array.size()*2);
	}

	array.set(dataEnd, element);
	dataEnd++;
}

//
// pop
//
template <typename T>
void Stack <T>::pop (void)
{
	// if the array is empty nothing can be removed, throw exception
	if(this->is_empty()){
		throw Stack::empty_exception();
	}
    
    // COMMENT You current design of the stack is copying each element
    // over on location each time your pop a new element from the stack.
    // Unfortunately, this is an expensive operation—--especially if you
    // have a large number of elements on the stack. Improve your design
    // so that you are not copying each element every time you pop a new
    // element from the stack.
    
    // RESPONSE I now use an index to keep track of acutal data in the stack, and shift it around when I pop or push

	// decrease dataEnd
	dataEnd--;    
}

// 
// operator =
//
template <typename T>
const Stack <T> & Stack <T>::operator = (const Stack & rhs)
{
	// if rhs is a reference of the current stack, return self reference
	if(this == &rhs){
		return * this;
	}
	// set array to be equal to the ref stack array
	array = rhs.array;
}

//
// clear
//
template <typename T>
void Stack <T>::clear (void)
{
	// make the dataEnd 0, nothing is in the stack
	dataEnd = 0;	
}


