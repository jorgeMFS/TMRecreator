#include "recreator.h"

/**
    recreator.cpp
    Purpose:  given a Rule Matrix of the TM, TM state alphabet cardinality:
    - Execute TM and print Tape;
    - Print State Matix;
    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

/**Tape of a Turing machine after n iterations
 * 
 * @param states
 * @param alphabet_size
 * @param num_iterations
 */
void recreate_tm(const TMInput& readInput){

  TuringMachine machine(readInput.number_of_states, readInput.alphabet_size);    
  machine.set_state_matrix(readInput.state_matrix); 

  machine.reset_tape_and_state();

  //To delete --- For Test Purposes only
  tm_print_state_matrix(readInput);  
  
  for (auto i = 0u; i < readInput.number_of_iterations -1 ; ++i){
          machine.act(); //importante ser antes
  }
  machine.print_written_tape();

}

/**Print State matrix of a Turing machine
 * 
 * @param states
 * @param alphabet_size
 * @param tm_number
 */
void tm_print_state_matrix(const TMInput& readInput){

  TuringMachine machine(readInput.number_of_states, readInput.alphabet_size);    
  machine.set_state_matrix(readInput.state_matrix); //bug
  machine.stMatrix.print();
}

