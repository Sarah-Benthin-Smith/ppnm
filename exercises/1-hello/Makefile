Out.txt : main
	./main > Out.txt

main: main.o
	c++ main.o -o main

main.o : main.cc
	c++ -c main.cc -o main.o

.PHONY: clean
clean:
	rm -f main main.o Out.txt

test:
	echo CXX
	echo $(CXX)








