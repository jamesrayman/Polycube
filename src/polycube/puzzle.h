#pragma once

#include <vector>

#include "board.h"

template<std::size_t DIM>
class Puzzle {
private:
    int sturdyLayers;
    Board<DIM> board;
    std::vector<Polycube<DIM>> polycubes;
    std::vector<std::vector<char>> candidates;

    int nBoardCells, nCells;
public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const std::vector<Polycube<DIM>>&, int);

    void initialize ();

    std::vector<Board<DIM>> solve (int) const;
};

#include "puzzle.tpp"