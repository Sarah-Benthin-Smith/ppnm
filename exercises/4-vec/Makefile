CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.o = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm 
Out.txt : main
	./main > Out.txt

main : main.o vec.o
#	$(CXX) $(LDFLAGS) main.o tasks.o $(LDLIBS) -o main

main.o : vec.h main.cc
#	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

vec.o: vec.h vec.cc
#	$(CXX) $(CXXFLAGS) -c hello.cc -o hello.o

.PHONY:clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)


























