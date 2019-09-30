/**
    markovTable.cpp
    Purpose: Construct Markov Tables.
             Measure Statistical Complexity.

    @author Jorge Miguel Ferreira da Silva
    @version 0.1
*/

#include <math.h>

#include "markovTable.h"
#include "util.h"


MarkovTable::MarkovTable(unsigned int k, unsigned int alphabet_size):
  markovVector(alphabet_size* ipow(alphabet_size,k),0), alphSz(alphabet_size), k(k){}


unsigned int MarkovTable::get_context() const{
    return this->k;
}


unsigned int& MarkovTable::at(const Char* characters) {
    return this->markovVector.at(( (str_to_index(characters) +1) * alphSz ) - (alphSz - characters[k]) ); 
}

std::vector<unsigned int> MarkovTable::getLine(const Char* characters) const{
    auto it_begin = this->markovVector.begin() + (  (   (str_to_index(characters) + 1) * this->alphSz   ) - this->alphSz    );
    auto it_end = this->markovVector.begin() + (    (str_to_index(characters) + 1) * this->alphSz   );
    std::vector <unsigned int> newVec(it_begin,it_end);
    return newVec;
}

void MarkovTable::reset() {
    std::fill(this->markovVector.begin(), this->markovVector.end(), 0);
}

size_t MarkovTable::str_to_index(const Char* x)  const{
    size_t o = 0;
    for (auto i = 0u; i < this->k; ++i) { //-1
        o = (o * this->alphSz) + x[i];
    }
    return o;
}

void MarkovTable::print() const{
    unsigned int counter = 0;
    std::cout << std::endl;
    std::cout << "Markov Table" << std::endl;
    for(auto&& x: this->markovVector){
        std::cout << x  << "\t";
        if(++counter == this->alphSz){
            std::cout << std::endl;
            counter = 0;
        }
    }
    std::cout << std::endl;
}
