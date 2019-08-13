src = $(wildcard src/**/*.cpp)
dirs = $(wildcard src/**/)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

bin/cli: $(obj)
	$(CXX) $(foreach dir,$(dirs),-I $(dir)) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) $(foreach dir,$(dirs),-I $(dir)) -c -o $@ $^

.PHONY: clean test clear
clean:
	rm -f $(obj) bin/cli

test:
	valgrind --tool=callgrind ./bin/cli ./test/bedlam.cube
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*
