#pragma once

#include <vector>
#include <unordered_map>

#include "../util/vector.h"
#include "../util/lattice.h"
#include "polycube.h"

template<std::size_t DIM>
class Board : public Lattice<int, DIM> {
private:
    std::unordered_map<int, int> cubeFreq;

    using Lattice<int, DIM>::transform;

    using Lattice<int, DIM>::operator==;
    using Lattice<int, DIM>::operator!=;
public:
    Board ();
    Board (const Board&);
    Board (const Lattice<int, DIM>&);

    bool place (const Polycube<DIM>&, const Matrix<DIM+1>&);
    bool unplace (const Polycube<DIM>&, const Matrix<DIM+1>&);
    Board<DIM> transform (const Matrix<DIM+1>&) const;

    bool operator== (const Board<DIM>&) const;
    bool operator!= (const Board<DIM>&) const;
};
