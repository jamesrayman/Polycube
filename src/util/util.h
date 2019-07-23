#pragma once

#include <vector>

#include "vector.h"

namespace util {
    int chi (int);
    int sgn (std::vector<int>&);
    
    template<std::size_t N>
    Vector<N+1> raise (int, const Vector<N>&);

    template<std::size_t N>
    Vector<N-1> flatten (const Vector<N>&);

    template<std::size_t N>
    std::vector<Vector<N>> allMinors (const Vector<N>&);
}

#include "util.tpp"