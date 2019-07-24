#pragma once

#include <vector>

#include "block.h"
#include "block_list.h"

template<std::size_t DIM>
class Board {
private:
    Lattice<int, DIM> cubes;

public:
    Board ();
    Board (const Board&);
    Board (const Lattice<int, DIM>&);

    std::vector<Board<DIM>> solve (const BlockList<DIM>& blocks);

    bool operator== (const Board<DIM>&) const; 
    bool operator!= (const Board<DIM>&) const; 
};