src = $(wildcard src/*/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

bin/cli: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean test clear
clean:
	rm -f $(obj) bin/cli

test:
	valgrind --tool=callgrind ./bin/cli ./test/puzzle.cubes
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*
