src = $(wildcard src/*/*.cpp)
dir = $(wildcard src/*/)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

bin/cli: $(obj)
	$(CXX) -I $(dir) -o $@ $^ $(LDFLAGS)

.PHONY: clean test clear
clean:
	rm -f  $(obj) bin/cli

test:
	valgrind --tool=callgrind ./bin/cli ./test/bedlam.cube
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*
