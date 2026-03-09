CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O -pthread
LINK.0 = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm

Out.txt : main
#	./main > Out.txt
	./$< > $@

main: main.o harm.o
main.o: main.cc harm.h
harm.o: harm.cc harm.h

.PHONY: clean
clean:
	$(RM) main log.main

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)
	@echo $(cc)


























