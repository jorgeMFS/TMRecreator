#include <sstream>      // std::stringstream
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <initializer_list>



#include "readInput.h"


template<typename T>
void print(std::vector<T> const &v){
    for (auto i: v) {
        std::cout << i << ' ';
    }
    std::cout << '\n';
}



template <typename T>
bool is_in(const T& v, std::initializer_list<T> lst)
{
    return std::find(std::begin(lst), std::end(lst), v) != std::end(lst);
}

TMInput readinput(){
  std::string line;

  while (std::getline(std::cin,line))
  {
    std::string delimiter = " ";
    std::istringstream iss(line);
    std::vector<std::string> parameters(std::istream_iterator<std::string>{iss},
                                 std::istream_iterator<std::string>());
    int number_parameters = parameters.size();

    if ( is_in(number_parameters, {4}) ){
      std::string string_state_matrix = parameters[0];
      unsigned int number_of_states = parse_input_parameters(parameters[1]);
      unsigned int alphabet_size = parse_input_parameters(parameters[2]);
      unsigned int number_of_iterations = parse_input_parameters(parameters[3]);    
      StateMatrix stM = string_to_state_matrix(string_state_matrix, number_of_states, alphabet_size);
      /*
      std::cout << "string state matrix : " << string_state_matrix << std::endl
                <<  "number of states : " << number_of_states << std::endl
                <<  "alphabet size : " << alphabet_size << std::endl
                <<  "number of iterations : " << number_of_iterations;
      */
      return TMInput{number_of_states,alphabet_size,number_of_iterations,stM};
    }
  }
    throw std::runtime_error("Wrong input passed by echo, try: echo \"RuleMatrix alphabet state number_iterations\" | ./rtm");
}

unsigned int parse_input_parameters(std::string optarg){
  if (! is_number(optarg)){
    fprintf (stderr, "input %s is not a number.\n",optarg.c_str()); 
    exit(0);

  }
  int correctInput = std::atoi (optarg.c_str());
  
  if (correctInput<=0){
    fprintf (stderr, "value was set to %i, must be an int larger than 0.\n",correctInput); 
    exit(0);
  }
  return static_cast<unsigned int>(correctInput);
}

bool is_number(const std::string& s){
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}


StateMatrix string_to_state_matrix(std::string string_state_matrix, unsigned int number_of_states, unsigned int alphabet_size){
    if(!(is_number(string_state_matrix) && (string_state_matrix.size()%(3*number_of_states*alphabet_size)==0) )){
      fprintf (stderr,"Invalid input string of TM State Matrix : %s\n ", string_state_matrix.c_str());
      exit(0);
    }
 
  //std::cout << "string state matrix : " << string_state_matrix << std::endl;
  return splitString(string_state_matrix,3, number_of_states, alphabet_size);
}

StateMatrix splitString(const std::string& str, int splitLength, unsigned int number_of_states, unsigned int alphabet_size){
   
   int NumSubstrings = str.length() / splitLength;
   std::vector<TuringRecord> ret;
   StateMatrix st(number_of_states, alphabet_size);


   for (auto i = 0; i < NumSubstrings; i++)
   {
        std::string tuple = str.substr(i * splitLength, splitLength);
        unsigned int w = tuple[0] - '0';
        unsigned int m = tuple[1] - '0';
        unsigned int s = tuple[2] - '0';
        bool test =w < alphabet_size && m<=2 && s<number_of_states;
        if (!test){
            fprintf (stderr,"Invalid input string of TM State Matrix in tuple : %s\n ", tuple.c_str());
            exit(0);
        }
        //std::cout << w << m << s << std::endl;
        ret.push_back(TuringRecord{w,m,s});
   }
    for (auto i=0u; i<st.v.size(); i++){
      st.v[i] = ret[i];
    }
    //print(ret);
   return st;
}