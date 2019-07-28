#pragma once

#include <vector>

#include "../util/vector.h"
#include "../util/matrix.h"
#include "../util/lattice.h"

template<std::size_t DIM>
class Polycube : public Lattice<bool, DIM> {
private:
    std::vector<Matrix<DIM+1>> rotations; // proper rotations

    using Lattice<int, DIM>::transform;

    using Lattice<int, DIM>::operator==;
    using Lattice<int, DIM>::operator!=;
public:
    Polycube ();
    Polycube (const Polycube<DIM>&);
    Polycube (const Lattice<bool, DIM>&);

    const std::vector<Matrix<DIM+1>>& allRotations () const;

    bool operator== (const Polycube<DIM>&) const;
    bool operator!= (const Polycube<DIM>&) const;

    Polycube<DIM>& operator= (const Polycube<DIM>&);
};
