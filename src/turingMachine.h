/**
    turingMachine.h
    Purpose: Create and execute Turing Machines.

    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

#pragma once
#include <tuple>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using std::uniform_int_distribution;

using TmId = unsigned long long;
using RecordId = unsigned int;
using State = unsigned int;
using Char = unsigned int;
using Move = unsigned int;

struct TapeMoves{
  size_t previousValue;
  size_t previousPosition;
  bool moveRight;
  bool moveLeft;
  unsigned int indexRule;
  unsigned int writtenValue;
};

struct TuringRecord{
  Char write;
  Move move;
  State state;

  bool next(unsigned int number_of_states, unsigned int alphabet_size);

  static TuringRecord by_index(RecordId id, unsigned int number_of_states, unsigned int alphabet_size);
};

std::ostream& operator<<( std::ostream& o, const TuringRecord& r);

struct StateMatrix{
  std::vector<TuringRecord> v;
  unsigned int nbStates;
  unsigned int alphSz;
  StateMatrix();
  StateMatrix(unsigned int number_of_states, unsigned int alphabet_size);

  void set_by_index(TmId id);
  TmId calculate_index() const;
  std::vector<TuringRecord> get_state_matrix() const;
  std::vector<Char> get_state_matrix_alphabet() const;


  /// Reset the state matrix into a uniformly random position.
  template<typename R>
  void set_random(R& rng) {
    auto write_dist = uniform_int_distribution<Char>(0, this->alphSz - 1);
    auto state_dist = uniform_int_distribution<State>(0, this->nbStates - 1);
    auto move_dist = uniform_int_distribution<Move>{0, 2};
    for (auto& st: this->v) {
      st.write = write_dist(rng);
      st.move = move_dist(rng);
      st.state = state_dist(rng);
    }
  }

  TuringRecord& at(Char alph, State state);
  const TuringRecord& at(Char alph, State state) const;
  unsigned int get_index(Char alph, State state); // retrieve index of StateMatrix;
  bool next();
  void print() const;
  const TuringRecord* chr_line(Char c) const;
};

struct Tape {
  std::vector<Char> tape;
  size_t position;
  size_t max_size;
  size_t ind_left;
  size_t ind_right;

  Tape();

  Char getvalue();
  TapeMoves setandmove(Move relativePos, Char value);
  void resetTape();
  size_t getposition();
  void print() const;
  void print_written_tape() const;
  private:
    void reserve_right(size_t amount);
    void reserve_left(size_t amount);
};

std::ostream& operator<<( std::ostream& o, const Tape& t);

struct TuringMachine {
  State state;
  Tape turingTape;
  StateMatrix stMatrix;

  TuringMachine(unsigned int number_of_states, unsigned int alphabet_size);
  Tape get_tape();
  void set_state_matrix(const StateMatrix& ruleMatrix);
  void reset_tape_and_state();
  TapeMoves act(bool detectCycle=false);
  StateMatrix get_tm_state_matrix() const;
  unsigned int get_alphabet_size() const;
  unsigned int get_number_of_states() const;
  bool test_full_alphabet_in_state_matrix(double percentage) const;
  void print_written_tape()const; 
};