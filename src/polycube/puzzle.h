#pragma once

#include <vector>

#include "board.h"

template<std::size_t DIM>
class Puzzle {
private:
    Board<DIM> board;
    std::vector<Polycube<DIM>> polycubes;
    std::vector<std::vector<char>> candidates;

    int nBoardCells, nCells;

    void solveStep (std::vector<Board<DIM>>&, Board<DIM>&, int, int, int, int, int&) const;
public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const std::vector<Polycube<DIM>>&);

    void initialize ();

    std::vector<Board<DIM>> solve () const;
};

#include "puzzle.tpp"