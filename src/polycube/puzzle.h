#pragma once

#include <vector>

#include "board.h"
#include "exact_cover.h"

template<std::size_t DIM>
class Puzzle {
private:
    Board<DIM> board;
    std::vector<Polycube<DIM>> polycubes;
    exact_cover::Problem problem;

    int nBoardCells, nCells;
public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const std::vector<Polycube<DIM>>&);

    void initialize ();

    std::vector<Board<DIM>> solve (int) const;
};

#include "puzzle.tpp"