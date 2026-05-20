CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17

main: main.o ROQAI.o
	$(CXX) $(CXXFLAGS) -o main main.o ROQAI.o

main.o: main.cc ROQAI.h
	$(CXX) $(CXXFLAGS) -c main.cc

ROQAI.o: ROQAI.cpp ROQAI.h
	$(CXX) $(CXXFLAGS) -c ROQAI.cpp

clean:
	rm -f *.o main
























