#pragma once

#include <vector>

#include "vector.h"

namespace util {
    inline int chi (int);
    inline int sgn (std::vector<int>&);
    
    template<std::size_t N>
    inline Vector<N+1> raise (int, const Vector<N>&);

    template<std::size_t N>
    inline Vector<N-1> flatten (const Vector<N>&);

    template<std::size_t N>
    inline std::vector<Vector<N>> allMinors (const Vector<N>&);
}

#include "util.tpp"
