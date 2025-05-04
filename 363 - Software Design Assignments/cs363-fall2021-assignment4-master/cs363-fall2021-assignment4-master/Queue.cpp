//  Queue.cpp written by Josh Hale

// Default Queue Constructor
template <typename T>
Queue <T>::Queue (void) :
// initalize array as an Array<T>() with default size, as no elemnts are in there but needs space for new elements. Set tracking size_t coords both as 0.
array(Array<T>()),
dataBegin(0),
dataEnd(0)
{
}

// Queue copy constructor
template <typename T>
Queue <T>::Queue (const Queue & q) :
// initialize array as an Array object with ref queue copied into it
array(Array<T>(q.size())),
dataBegin(0),
dataEnd(q.size())
{
	// need to copy data over
	for(int i = 0; i<dataEnd; i++){
		array.set(i, q.array.get(q.dataBegin+i));
	}
}

// ~Queue deconstructor
template <typename T>
Queue <T>::~Queue (void)
{
    // not sure if I need this or default deconstructors will work, hopefully doing this is fine.
    // delete array;
}

// Queue enqueue()
template <typename T>
void Queue <T>::enqueue (T element)
{
	// reached end of alloted space, find ways to free up
	if(dataEnd == array.size()){
		// if there is empty space at the beginning shift all elements up
		if(dataBegin != 0){
			for(int i = 0; i<this->size(); i++){
				array.set(i, array.get(dataBegin+i));
			}
			// I FEEL SO SMART FOR FIGURING OUT THESE INDEX REASSIGNMENTS!!!!!!
			dataEnd = this->size();
			dataBegin = 0;
		// if not double array size	
		}else{
			array.resize(array.size()*2);
		}
	}
	// set new data to dataEnd +1, then incrementing dataEnd to show new data exists
	array.set(dataEnd, element);
	dataEnd++;
}

// Queue dequeue()
template <typename T>
T Queue <T>::dequeue (void)
{
    	// if the queue is empty nothing can be removed, throw exception
    	if(this->is_empty()){
        	throw empty_exception();
    	}
    	// save first element to return
    	T output = array.get(dataBegin);
    
    // COMMENT This design is OK, but it is not the best design. This will be
    // a very expensive array to use if you are dequeing a lot of elements. This
    // is because you are copying N elements each time you dequeue 1 element.
    // Instead, you only want to copy element when necessary. Come up with a better
    // design that is not as expensive for the client to use.
	
    // RESPONSE I now have placeholder indexes of where the queue data begins and ends in the array, i modify them when I dequeue and shift when around when I need more space when enqueuing

	// increment dataBegin as the output has been returned
	dataBegin++;
    	
    	return output;
}

// Queue assignment operator =
template <typename T>
const Queue <T> & Queue <T>::operator = (const Queue & rhs)
{
    // if rhs is a reference of current stack, return self reference
    if(this == &rhs){
        return * this;
    }
    // set array to be equal to the ref stack array
    array = rhs.array;
}

// Queue clear
template <typename T>
void Queue <T>::clear (void)
{
	// set indexes both to 0, virtually erasing all space
	dataBegin = 0;
	dataEnd = 0;
}