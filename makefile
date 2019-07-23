src = $(wildcard src/*.cpp) $(wildcard src/*/*.cpp)
obj = $(src:.cpp=.o)

LDFLAGS = -std=c++17

polycube: $(obj)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) polycube
