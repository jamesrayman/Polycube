src = $(wildcard src/**/*.cpp)
dirs = $(wildcard src/**/)
obj = $(filter-out src/io/cli.o,$(filter-out src/io/adhoc.o,$(src:.cpp=.o)))

LDFLAGS = -std=c++17 -O3

bin/polycube: $(obj) src/io/cli.o
	$(CXX) -static $(foreach dir,$(dirs),-I $(dir)) -o $@ $^ $(LDFLAGS)

bin/adhoc: $(obj) src/io/adhoc.o
	$(CXX) -static $(foreach dir,$(dirs),-I $(dir)) -o $@ $^ $(LDFLAGS)

%.o : %.cpp
	$(CXX) -static $(foreach dir,$(dirs),-I $(dir)) -c -o $@ $^ $(LDFLAGS)

.PHONY: clean test clear
clean:
	rm -f $(obj) bin/*

test:
	valgrind --tool=callgrind ./bin/cli ./dat/bedlam.brick
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*
