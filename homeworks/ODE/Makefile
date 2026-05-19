CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -O2

OBJS = main.o rkstep.o ode.o vec.o

main: $(OBJS)
	$(CXX) $(OBJS) -o main

main.o: main.cc
rkstep.o: rkstep.cpp
ode.o: ode.cpp
vec.o: vec.cc

clean:
	rm -f *.o main out.data

plot: main
	./main
	echo '\
	set terminal svg size 800,600 background "white"; \
	set output "dif_eq.svg"; \
	set title "Solving differential equation"; \
	set xlabel "x"; set ylabel "y"; \
	plot "out.data" using 1:2 with lines title "numerical", \
	     "out.data" using 1:3 with lines title "eksakt"; \
	' | gnuplot

























