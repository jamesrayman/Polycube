#pragma once

#include <vector>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"

template<std::size_t DIM>
class Block {
private:
    Lattice<bool, DIM> block;
    std::vector<Matrix<DIM+1>> rotations; // proper rotations

public:
    Block ();
    Block (const Block<DIM>&);
    Block (const Lattice<bool, DIM>&);

    const std::vector<Matrix<DIM+1>>& allRotations () const;
    
    bool operator[] (const Vector<DIM>&) const;

    bool operator== (const Block<DIM>&) const;
    bool operator!= (const Block<DIM>&) const;

    Block<DIM>& operator= (const Block<DIM>&);
};
