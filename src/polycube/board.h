#pragma once

#include <vector>

#include "polycube.h"
#include "polycube_list.h"

template<std::size_t DIM>
class Board {
private:
    Lattice<int, DIM> cubes;

public:
    Board ();
    Board (const Board&);
    Board (const Lattice<int, DIM>&);

    std::vector<Board<DIM>> solve (const PolycubeList<DIM>&);

    bool operator== (const Board<DIM>&) const; 
    bool operator!= (const Board<DIM>&) const; 
};