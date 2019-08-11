#pragma once

#include <vector>
#include <unordered_map>

#include "../util/vector.h"
#include "../util/lattice.h"
#include "polycube.h"

template<std::size_t DIM>
class Board : public Lattice<int, DIM> {
private:
    int nextCube;

    bool renameEqual (const Board<DIM>&) const;

    using Lattice<int, DIM>::transform;
    using Lattice<int, DIM>::isomorphic;

    using Lattice<int, DIM>::operator==;
    using Lattice<int, DIM>::operator!=;

    using Lattice<int, DIM>::operator[];
public:
    Board ();
    Board (const Board&);
    Board (const Lattice<int, DIM>&);

    bool fits (const Polycube<DIM>&, const Matrix<DIM+1>&);
    void put (int, int);
    bool place (const Polycube<DIM>&, const Matrix<DIM+1>&);
    void unplace (const Polycube<DIM>&, const Matrix<DIM+1>&);
    Board<DIM> transform (const Matrix<DIM+1>&) const;
    bool isomorphic (const Board<DIM>&, const std::vector<Matrix<DIM+1>>&) const; 

    bool operator== (const Board<DIM>&) const;
    bool operator!= (const Board<DIM>&) const;

    int operator[] (const Vector<DIM>&) const;
};

#include "board.tpp"
