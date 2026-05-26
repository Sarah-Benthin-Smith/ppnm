CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -O2

OBJS = main.o matrix.o qr.o

main: $(OBJS)
	$(CXX) $(OBJS) -o main

main.o: main.cc
matrix.o: matrix.cc
qr.o: qr.cc

clean:
	rm -f *.o main

# plot: main
# 	./main
# 	gnuplot plot_wf.gp
























