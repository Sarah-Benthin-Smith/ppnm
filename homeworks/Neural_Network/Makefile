CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O2

all: main

main: main.o matrix.o ANN.o
	$(CXX) $(CXXFLAGS) -o main main.o matrix.o ANN.o

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

matrix.o: matrix.cc
	$(CXX) $(CXXFLAGS) -c matrix.cc

ANN.o: ANN.cpp ANN.h
	$(CXX) $(CXXFLAGS) -c ANN.cpp


clean:
	rm -f *.o main

