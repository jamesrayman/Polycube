#include "puzzle.h"

#include <iostream>
#include "../io/format.h"

template<std::size_t DIM>
Puzzle<DIM>::Puzzle () = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Puzzle&) = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Board<DIM>& board, const PolycubeList<DIM>& polycubes) : board(board), polycubes(polycubes) {
    positions = board.allPositions();
}

template<std::size_t DIM>
void Puzzle<DIM>::solveStep (std::vector<Board<DIM>>& res, Board<DIM>& curr, int listIndex, int posIndex, int rotIndex, int n) const {
    //std::cout << listIndex << " " << n << " " format::board(curr) << "\n";
    
    if (listIndex == polycubes.size()) {
        if (std::find(res.begin(), res.end(), curr) == res.end()) {
            res.push_back(curr);
        }
        return;
    }

    const auto& polycube = polycubes[listIndex].first;
    int m = polycubes[listIndex].second;
    const auto& rotations = polycube.allRotations();

    if (m == n) {
        solveStep(res, curr, listIndex+1, 0, 0, 0);
        return;
    }

    for (int i = posIndex; i < positions.size(); i++) {
        for (int j = rotIndex; j < rotations.size(); j++) {
            auto transform = Matrix<DIM+1>::translation(positions[i]) * rotations[j];
            if (curr.place(polycube, transform)) {
                solveStep(res, curr, listIndex, i, j+1, n+1);
                curr.unplace(polycube, transform);
            }
        }

        rotIndex = 0;
    }
}

template<std::size_t DIM>
std::vector<Board<DIM>> Puzzle<DIM>::solve () const {
    std::vector<Board<DIM>> res;
    auto b = board;

    solveStep(res, b, 0, 0, 0, 0);

    return res;
}