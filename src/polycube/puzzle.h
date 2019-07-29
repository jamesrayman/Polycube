#pragma once

#include <vector>

#include "polycube_list.h"
#include "board.h"

template<std::size_t DIM>
class Puzzle {
private:
    Board<DIM> board;
    PolycubeList<DIM> polycubes;

    void solveStep (std::vector<Board<DIM>>&, int, int) const;
public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const PolycubeList<DIM>&);

    std::vector<Board<DIM>> solve () const;
};

#include "puzzle.tpp"