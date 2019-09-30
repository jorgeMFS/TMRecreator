/**
    main.cpp
    Purpose: Run Program

    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

#include "parseArgs.h"
#include "recreator.h"
#include "readInput.h"
 
/*
  * It will iterate through all the lines in file and
  * put them in given vector
*/

int main (int argc, char **argv){
  bool printRM =parseArgs(argc,argv);
  TMInput tmInput = readinput();
  if(printRM){
    tm_print_state_matrix(tmInput);
  }
  else{
    recreate_tm(tmInput); //change main
  }
  

}
