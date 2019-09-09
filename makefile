src = $(wildcard src/**/*.cpp)
dirs = $(wildcard src/**/)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17 -O3

bin/cli: $(obj)
	$(CXX) $(foreach dir,$(dirs),-I $(dir)) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) $(foreach dir,$(dirs),-I $(dir)) -c -o $@ $^ $(LDFLAGS)

.PHONY: clean test clear
clean:
	rm -f $(obj) bin/cli

test:
	valgrind --tool=callgrind ./bin/cli ./dat/bedlam.brick
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*
