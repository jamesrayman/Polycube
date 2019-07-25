#pragma once

#include <vector>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"

template<std::size_t DIM>
class Polycube {
private:
    Lattice<bool, DIM> polycube;
    std::vector<Matrix<DIM+1>> rotations; // proper rotations

public:
    Polycube ();
    Polycube (const Polycube<DIM>&);
    Polycube (const Lattice<bool, DIM>&);

    const std::vector<Matrix<DIM+1>>& allRotations () const;
    
    bool operator[] (const Vector<DIM>&) const;

    bool operator== (const Polycube<DIM>&) const;
    bool operator!= (const Polycube<DIM>&) const;

    Polycube<DIM>& operator= (const Polycube<DIM>&);
};
