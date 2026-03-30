CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LDLIBS += -lm

OBJS = main.o matrix.o vec.o qr.o

all: main

main: $(OBJS)
	$(CXX) $(OBJS) -o main $(LDLIBS)

main.o: main.cc matrix.h vec.h qr.h
matrix.o: matrix.cc matrix.h vec.h
vec.o: vec.cc vec.h
qr.o: qr.cc qr.h matrix.h vec.h

clean:
	rm -f *.o main


























