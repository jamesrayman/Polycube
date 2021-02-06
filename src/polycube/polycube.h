#pragma once

#include <vector>

#include "vector.h"
#include "matrix.h"
#include "lattice.h"

template<std::size_t DIM>
class Polycube : public Lattice<bool, DIM> {
private:
    std::vector<Matrix<DIM+1>> rotations; // proper rotations

    using Lattice<bool, DIM>::transform;
    using Lattice<bool, DIM>::isomorphic;

    using Lattice<bool, DIM>::operator==;
    using Lattice<bool, DIM>::operator!=;

    using Lattice<bool, DIM>::operator[];
public:
    Polycube ();
    Polycube (const Polycube<DIM>&);
    Polycube (const Lattice<bool, DIM>&);

    const std::vector<Matrix<DIM+1>>& allRotations () const;

    bool operator== (const Polycube<DIM>&) const;
    bool operator!= (const Polycube<DIM>&) const;

    bool operator[] (const Vector<DIM>&) const;

    Polycube<DIM>& operator= (const Polycube<DIM>&);

};

#include "polycube.tpp"