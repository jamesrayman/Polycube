src = $(wildcard src/*/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

bin/cli: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) bin/cli
