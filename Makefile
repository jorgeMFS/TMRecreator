.PHONY: all clean

CXX = g++ -std=c++14
CXXFLAGS = -Wall -Wextra -O3 -m64 -g -I./include
LFLAGS = -pthread

objects = src/turingMachine.o \
		  src/markovTable.o \
		  src/parseArgs.o \
		  src/util.o \
		  src/readInput.o \
		  src/recreator.o \
		  src/main.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

rtm: $(objects)
	$(CXX) $(LFLAGS) $^ -o $@

all: rtm

clean:
	rm -f src/*.o rtm

# Dependencies

main.o: src/main.cpp src/recreator.h src/parseArgs.h src/readInput.h

src/recreator.o: src/recreator.cpp src/recreator.h

src/tm.o: src/tm.cpp src/tm.h src/turingMachine.h src/markovTable.h src/util.h 

src/markovTable.o: src/markovTable.cpp src/markovTable.h src/turingMachine.h src/util.h

src/parseArgs.o: src/parseArgs.cpp src/parseArgs.h src/util.h

src/turingMachine.o: src/turingMachine.cpp src/turingMachine.h

src/util.o: src/util.cpp src/util.h

src/readInput.o: src/readInput.cpp src/readInput.h