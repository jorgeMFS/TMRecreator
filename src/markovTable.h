/**
    markovTable.h
    Purpose: Construct Markov Tables.
             Measure Statistical Complexity.

    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

#pragma once
#include <vector>
#include <iostream>

#include "turingMachine.h"

using Char = unsigned int;

/**
 *  Table of repetitions a given contex has for a given alphabet.
 *  Example:
 *  k/context=2, alphabet size=2,  string = -010110011-
 *
 *  __|_0_|_1_
 *  00| 0 | 1
 *  01| 1 | 2
 *  10| 1 | 1
 *  11| 1 | 0
 *
 *  Note: All this is mapped into a vector of integers.
 */
struct MarkovTable{
  std::vector<unsigned int> markovVector;
  unsigned int alphSz;
  unsigned int k;

  /**
   * @param k. Size of context to consider on the MarkovTable.
   * @param alphabet_size. Size of the alphabet being considered by the tm.
   */
  MarkovTable(unsigned int k, unsigned int alphabet_size);
  
  /**
   * Accesses position on Markov Table, by providing a pointer to a position on array of TM characters.
   */
  unsigned int& at(const Char* characters);

  /**
   *  Provides line of of Markov Table, by providing a pointer to a position on array of unsigned ints.
   */
  std::vector <unsigned int> getLine(const Char* characters) const;

  /// Resets Markov Table.
  void reset();

  /// Prints Markov Table.
  void print() const;

  /// Returns context k used on table.
  unsigned int get_context() const;
  
  private:

  /**
   * Takes in pointer to char array and returns the context number on the Markov Table.
   *
   * @param const Char*. Pointer to char array.
   * @return size_t. Returns context number on the Markov Table.
   */
  size_t str_to_index(const Char* x) const;
};
