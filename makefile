src = $(wildcard src/**/*.cpp)
tpp = $(wildcard src/**/*.tpp)
dirs = $(wildcard src/**/)
obj = $(filter-out src/io/cli.o,$(filter-out src/io/adhoc.o,$(src:.cpp=.o)))

includes = $(foreach dir,$(dirs),-I $(dir))
LDFLAGS = -l:libz3.so -std=c++17 -O3

bin/polycube: $(obj) src/io/cli.o $(tpp)
	$(CXX) $(includes) -o $@ $(obj) src/io/cli.o $(LDFLAGS)

bin/adhoc: $(obj) src/io/adhoc.o $(tpp)
	$(CXX) $(includes) -o $@ $(obj) src/io/adhoc.o $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(includes) -c -o $@ $^ $(LDFLAGS)


.PHONY: clean test clear polycube adhoc

polycube: bin/polycube

adhoc: bin/adhoc

clean:
	rm -f $(obj) bin/* src/io/cli.o src/io/adhoc.o

test:
	valgrind --tool=callgrind ./bin/polycube ./dat/violet.brick
	kcachegrind callgrind.out.*
	rm -f *.out.*

clear:
	rm -f *.out.*

