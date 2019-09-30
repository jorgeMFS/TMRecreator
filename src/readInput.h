#pragma once
#include <string>
#include "turingMachine.h"

struct TMInput{
    unsigned int number_of_states;
    unsigned int alphabet_size;
    unsigned int number_of_iterations;
    StateMatrix state_matrix;
};

TMInput readinput();
unsigned int parse_input_parameters(std::string optarg);
bool is_number(const std::string& s);
StateMatrix string_to_state_matrix(std::string string_state_matrix, unsigned int number_of_states, unsigned int alphabet_size);
StateMatrix splitString(const std::string& str, int splitLength, unsigned int number_of_states, unsigned int alphabet_size);
