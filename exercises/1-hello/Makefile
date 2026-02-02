CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.o = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm 
Out.txt : main
	./main > Out.txt

main : main.o hello.o
#	$(CXX) $(LDFLAGS) main.o hello.o $(LDLIBS) -o main

main.o : hello.h main.cc
#	$(CXX) $(CXXFLAGS) -c main.cc -o main.o

hello.o: hello.h hello.cc
#	$(CXX) $(CXXFLAGS) -c hello.cc -o hello.o

.PHONY:clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)


























