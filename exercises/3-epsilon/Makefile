CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.o = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm 
Out.txt : main
	./main > Out.txt

main : main.o assignment2.o
#	$(CXX) $(LDFLAGS) main.o hello.o $(LDLIBS) -o main

main.o : assignment2.h main.cc
#	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

hello.o: assignment2.h assignment2.cc
#	$(CXX) $(CXXFLAGS) -c hello.cc -o hello.o

.PHONY:clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)


























