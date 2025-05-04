// Queue.inl written by Josh HAle

// Queue size
template <typename T>
inline
size_t Queue <T>::size (void) const
{
    // return number of elements in queue, difference of indexes
	return dataEnd - dataBegin;
}

// Queue is_empty
template <typename T>
inline
bool Queue <T>::is_empty (void) const
{
    // if size is 0, no elements, it's empty
    if(this->size()==0){
        return true;
    }
    return false;
}
