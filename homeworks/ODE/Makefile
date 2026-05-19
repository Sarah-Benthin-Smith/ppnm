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
	plot "out.data" using 1:2 with lines lw 3 lc rgb "#6A0DAD" title "numerical", \
	     "out.data" using 1:3 with lines lw 3 dt 2 lc rgb "#e67c22" title "eksakt"; \
	set output "example_pend.svg"; \
	set title "Solving example pendulum"; \
	set xlabel "x"; set ylabel "y"; \
	plot "pendulum.data" using 1:2 with lines lw 3 lc rgb "#6A0DAD" title "theta(t)", \
	     "pendulum.data" using 1:3 with lines lw 3 dt 2 lc rgb "#e67c22" title "omega(t)"; \
	' | gnuplot

























