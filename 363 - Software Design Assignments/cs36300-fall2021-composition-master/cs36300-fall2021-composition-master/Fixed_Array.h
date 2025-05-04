// -*- C++ -*-

// Honor Pledge:
//	Josh HALE
// I pledge that I have neither given nor received any help
// on this assignment.

#ifndef _CS507_FIXED_ARRAY_H_
#define _CS507_FIXED_ARRAY_H_

#include "Base_Array.h"

// COMMENT You are supposed to address the LSP violation between
// array and fixed array by adding the base array class.

// RESPONSE I addressed the LSP violation between array and fixed array adding a class called Base_Array that Array and Fixed_Array inherit from. I was gone the monday this was discussed and after asking classmates they said my method of Fixed_Array inheriting from Array was fine. Jokes on me for not asking you

/**
 * @class Fixed_Array
 *
 * Implementation of a fixed size array, i.e., one that is not
 * resizeable. It is derived from Array so it can inherit of 
 * the Array class's methods.
 */
template <typename T, size_t N>
class Fixed_Array : public Base_Array <T>
{
public:
  /// Default constructor.
  Fixed_Array (void);

	/**
	 * Copy constructor.
	 *
	 * @param[in]      arr        Source array
	 */
  Fixed_Array (const Fixed_Array <T, N> & arr);
	
  /**
   * Initializing constructor. The source array can be of any size
   * as long as they are of the same type.
   *
   * @param[in]      arr        Source array
   */
  template <size_t M>
  Fixed_Array (const Fixed_Array <T, M> & arr);

  /**
   * Initializing constructor. Fills the contents of the 
   * array with the specified \a fill value.
   *
   * @param[in]      fill       The file value.
   */
  Fixed_Array (T fill);

  /// Destructor.
  ~Fixed_Array (void);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  const Fixed_Array & operator = (const Fixed_Array <T, N> & rhs);

  /**
   * Assignment operator
   *
   * @param[in]      rhs        Right-hand side of operator.
   */
  template <size_t M>
  const Fixed_Array & operator = (const Fixed_Array <T, M> & rhs);
};

// include the inline files, unecessary there's nothing there
// #include "Fixed_Array.inl"

// include the source file since template class
#include "Fixed_Array.cpp"

#endif  // !defined _CS507_FIXED_ARRAY_H_
