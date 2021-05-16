#include "util.h"
#include <random>

namespace util {
    int rand_int (int n) {
        static std::random_device rd;        
        static std::mt19937 generator(rd());

        return std::uniform_int_distribution<int>(0, n-1)(generator);
    }
}
