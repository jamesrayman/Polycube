#include "puzzle.h"

template<std::size_t DIM>
Puzzle<DIM>::Puzzle () = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Puzzle&) = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Board<DIM>& board, const PolycubeList<DIM>& polycubes) : board(board), polycubes(polycubes) {}

template<std::size_t DIM>
void Puzzle<DIM>::solveStep (std::vector<Board<DIM>>&, int, int) const {
    
}

template<std::size_t DIM>
std::vector<Board<DIM>> Puzzle<DIM>::solve () const {

}