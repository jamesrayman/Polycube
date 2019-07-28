#pragma once

#include <vector>

#include "polycube_list.h"
#include "board.h"

template<std::size_t DIM>
class Puzzle {
private:
    Board<DIM> board;
    PolycubeList<DIM> polycubes;

public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const PolycubeList<DIM>&);

    std::vector<Board<DIM>> solve ();
};
