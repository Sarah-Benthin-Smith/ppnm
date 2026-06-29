CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LDLIBS += -lm

OBJS = main.o matrix.o lsfit.o qr.o minimizers.o

all: main

main: main.o lsfit.o qr.o matrix.o minimizers.o
	g++ -o main main.o lsfit.o qr.o matrix.o minimizers.o

main.o: main.cc matrix.h lsfit.h
matrix.o: matrix.cc matrix.h 
lsfit.o: lsfit.cpp lsfit.h matrix.h
qr.o: qr.cc qr.h matrix.h
minimizers.o: minimizers.cc minimizers.h

clean:
	rm -f *.o main README.txt

test:
	./main
	README.txt























