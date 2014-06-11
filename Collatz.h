// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2014
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream
#include <utility>  // pair

// ------------
// collatz_read
// ------------

/**
 * read two ints
 * @param  r a  std::istream
 * @return a pair of the two ints, otherwise a pair of zeros
 */
std::pair<int, int> collatz_read (std::istream&);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

// -------------
// collatz_print
// -------------

/**
 * print three ints
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

#endif // Collatz_h
