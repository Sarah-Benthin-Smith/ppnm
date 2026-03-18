CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.0 = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm

Out.txt : main
#	./main > Out.txt
	./$< > $@

main: main.o vec.o matrix.o qr.o
main.o: vec.h
vec.o: vec.h
matrix.o: matrix.h
qr.o: qr.h

.PHONY: clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)
	@echo $(cc)


























