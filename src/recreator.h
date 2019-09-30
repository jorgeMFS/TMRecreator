#pragma once
#include "turingMachine.h"
#include "readInput.h"
/** Prints a specific Turing machine tape after a given number of iterations.
 *
 * @param states
 * @param alphabet_size
 * @param num_iterations
 * @param tm_number
 */
void recreate_tm(const TMInput& readInput);

/**Print State matrix of a Turing machine
 * 
 * @param states
 * @param alphabet_size
 * @param tm_number
 */

void tm_print_state_matrix(const TMInput& readInput);