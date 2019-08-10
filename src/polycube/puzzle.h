#pragma once

#include <vector>

#include "polycube_list.h"
#include "board.h"

template<std::size_t DIM>
class Puzzle {
private:
    Board<DIM> board;
    PolycubeList<DIM> polycubes;
    std::vector<Vector<DIM>> positions;

    void solveStep (std::vector<Board<DIM>>&, Board<DIM>&, int, int, int, int, int&) const;
public:
    Puzzle ();
    Puzzle (const Puzzle&);
    Puzzle (const Board<DIM>&, const PolycubeList<DIM>&);

    void initialize ();

    std::vector<Board<DIM>> solve () const;
};

#include "puzzle.tpp"