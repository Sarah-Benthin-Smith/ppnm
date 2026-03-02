CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.0 = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm

Out.txt : main
#	./main > Out.txt
	./$< > $@

main: main.o funcs.o
main.o: main.cc funcs.h
funcs.o: funcs.cc funcs.h

.PHONY: clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)
	@echo $(cc)


























