CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.o = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm 
Out.txt : main
	./main > Out.txt

main : main.o assignment2.o assignment3.o
#	$(CXX) $(LDFLAGS) main.o hello.o $(LDLIBS) -o main

main.o : assignment2.h assignment3.h main.cc
#	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

assignment2.o: assignment2.cc assignment2.h
#	$(CXX) $(CXXFLAGS) -c hello.cc -o hello.o
assignment3.o: assignment3.cc assignment3.h

.PHONY:clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)


























