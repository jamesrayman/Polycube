#include "util.h"

#include <vector>

#include "vector.h"

namespace util {
    inline int chi (int n) {
        if (n < 0) return -chi(-n);
        if (n % 2 == 0) return 0;
        if (n % 4 == 1) return 1;
        return -1;
    }

    inline int sgn (std::vector<int>& v) {
        int transpositions = 0;

        for (int i = 0; i < v.size(); i++) {
            if (v[i] > i && v[v[i]] == i) {
                transpositions++;
            }
        }

        if (transpositions % 2 == 0) return 1;
        else return -1;
    }

    template<std::size_t N>
    inline Vector<N+1> raise (int x, const Vector<N>& v) {
        Vector<N+1> res;
        res[0] = x;

        for (int i = 0; i < N; i++) {
            res[i+1] = v[i];
        }

        return res;
    }
    
    template<>
    inline Vector<1> raise<0> (int x, const Vector<0>& v) {
        return Vector<1> { x };
    }

    template<std::size_t N>
    inline Vector<N-1> flatten (const Vector<N>& v) {
        Vector<N-1> res;

        for (int i = 0; i < N-1; i++) {
            res[i] = v[i+1]; 
        }

        return res;
    }
    
    template<>
    inline Vector<0> flatten<1> (const Vector<1>&) {
        return Vector<0>();
    }

    template<std::size_t N>
    inline std::vector<Vector<N>> allMinors (const Vector<N>& shape) {
        auto subMinors = allMinors(flatten(shape));
        std::vector<Vector<N>> res;

        for (int x = 0; x < shape[0]; x++) {
            for (const auto& subMinor : subMinors) {
                res.push_back(raise(x, subMinor));
            }
        }

        return res;
    }

    template<>
    inline std::vector<Vector<0>> allMinors<0> (const Vector<0>&) {
        return std::vector<Vector<0>>{ Vector<0>() };
    }
}
