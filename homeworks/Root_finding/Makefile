CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -O2

OBJS = main.o ode.o matrix.o jacobian.o newton.o qr.o rkstep.o

main: $(OBJS)
	$(CXX) $(OBJS) -o main

main.o: main.cc
ode.o: ode.cpp
# vec.o: vec.cc
matrix.o: matrix.cc
jacobian.o: jacobian.cpp
newton.o: newton.cpp
qr.o: qr.cc
rkstep.o: rkstep.cpp

clean:
	rm -f *.o main

# plot: main
# 	./main
# 	gnuplot orbit.gp threebody.gp 
























