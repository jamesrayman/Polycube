#include "puzzle.h"

#include "format.h"
#include "exact_cover.h"

template<std::size_t DIM>
Puzzle<DIM>::Puzzle () = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Puzzle&) = default;

template<std::size_t DIM>
Puzzle<DIM>::Puzzle (const Board<DIM>& board, const std::vector<Polycube<DIM>>& polycubes, int sturdyLayers)
: board(board), polycubes(polycubes), sturdyLayers(sturdyLayers) { 
    nBoardCells = board.size();
    nCells = nBoardCells + polycubes.size();
}

template<std::size_t DIM>
void Puzzle<DIM>::initialize () {
    auto allPositions = board.allPositions();
    int polycubeIndex = 0;

    for (const auto& polycube : polycubes) {
        for (const auto& rotation : polycube.allRotations()) {
            for (const auto& position : allPositions) {
                auto transform = Matrix<DIM+1>::translation(position) * rotation;

                if (board.fits(polycube, transform, sturdyLayers)) {
                    std::vector<char> candidate (nCells, false);
                    candidate[nBoardCells + polycubeIndex] = true;

                    auto polycubePositions = polycube.allPositions();

                    for (const auto& pos : polycubePositions) {
                        if (polycube[pos]) {
                            candidate[board.intIndex(transform * pos)] = true;
                        }
                    }
                    candidates.push_back(candidate);
                }
            }
        }
        polycubeIndex++;
    }
}

template<std::size_t DIM>
std::vector<Board<DIM>> Puzzle<DIM>::solve (int solutionLimit) const {
    std::vector<Board<DIM>> res;

    auto solutions = exactCover(candidates, solutionLimit);

    for (const auto& solution : solutions) {
        Board<DIM> b = board;
        int cube = 1;

        for (int cand : solution) {
            for (int i = 0; i < nBoardCells; i++) {
                if (candidates[cand][i]) {
                    b.put(i, cube);
                }
            }
            cube++;
        }

        //if (std::find(res.begin(), res.end(), b) == res.end()) {
            res.push_back(b);
        //}
    }

    return res;
}
