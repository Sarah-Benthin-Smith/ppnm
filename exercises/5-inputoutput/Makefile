CXXFLAGS = -Wall -Wextra -Werror -std=c++23 -O
LINK.0 = $(CXX) $(LDFLAGS)
LDLIBS += -lstdc++ -lm

Out.txt : main input.txt
	./$< > $@

main: main.o 

.PHONY: clean
clean:
	$(RM) main main.o Out.txt *.o

test:
	@echo CXX
	@echo $(CXX)
	@echo $(RM)
	@echo $(cc)


























