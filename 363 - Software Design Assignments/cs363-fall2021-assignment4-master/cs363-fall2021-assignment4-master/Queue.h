// Queue.h written by Josh Hale

#ifndef QUEUE_H_EXISTS
#define QUEUE_H_EXISTS

#include <exception>
#include "Array.h" // for array

/**
 * @class Queue
 * 
 * Basic queue for arbitrary elements.
 */
template <typename T>
class Queue
{
    public:
    // Type definition of the type.
    typedef T type;

    /**
     * @class empty_exception
     * 
     * Exception thrown to indicate the queue is empty.
     */
    class empty_exception : public std::exception
    {
        public:
        // Default constructor.
        empty_exception (void)
        : std::exception () {}

        /**
         * Initializing constructor.
         * 
         * @param[in]       msg         Error message.
         */
        empty_exception (const char * msg)
        : std::exception (msg) {}
    };

    // Default constructor.
    Queue (void);

    // Copy constructor.
    Queue (const Queue & q);

    // Destructor.
    ~Queue (void);

    /**
     * Assignment operator
     * 
     * @param[in]       rhs         Right-hand side of operator
     * @return          Reference to self
     */
    const Queue & operator = (const Queue & rhs);

    /**
     * Adds the element to the end of the list.
     * 
     * @param[in]       element         Element to add to the list
     */
    void enqueue (T element);

    /**
     * Removes the element at the front of the list. If there are not elements in the queue, this method throws empty_exception, similar to the stack
     * 
     * @exception       empty_exception     The queue is empty.
     * @return          Front element
     */
    T dequeue (void);

    /**
     * Test if the queue is empty. If the queue is empty, then this message returns true. Otherwise this message returns false.
     * 
     * @retval      true        The queue is empty
     * @retval      false       The queue is not empty
     */
    bool is_empty (void) const;

    /**
     * Returns the number of elements on the queue
     * 
     * @return          Size of queue.
     */
    size_t size (void) const;

    // Remove all elements in the queue
    void clear (void);

private:
    // added member variable here
    Array<T> array;

    // for keeping track of where data starts and ends in array
    size_t dataBegin;
    size_t dataEnd;
};

// include inline file
#include "Queue.inl"

// include source file at end since template class
#include "Queue.cpp"

#endif 
// !defined QUEUE_H_EXISTS