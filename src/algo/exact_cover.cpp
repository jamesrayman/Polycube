#include "exact_cover.h"

#include <vector>
#include <algorithm>

#include "dancing_chain.h"

void stepExactCover (std::vector<std::vector<int>>& res, std::vector<int>& curr, DancingChain& chain, int solutionLimit) {
    if (chain.size() == 0) {
        res.push_back(curr);
        std::sort(res.back().begin(), res.back().end());

        return;
    }

    if (res.size() >= solutionLimit) return;

    int cellToFill = chain.mostConstrained();
    for (int cand = chain.down(cellToFill, 0); cand != 0; cand = chain.down(cellToFill, cand)) {
        curr.push_back(cand-1);
        chain.startUndoBatch();

        for (int candCell = chain.right(cellToFill, cand); chain.active(cellToFill, cand); candCell = chain.right(cellToFill, cand)) {
            chain.deactivate(candCell, 0);

            for (int candToRemove = chain.down(candCell, cand); candToRemove != cand;
            candToRemove = chain.down(candCell, cand)) {

                for (int candToRemoveCell = chain.right(candCell, candToRemove); chain.active(candCell, candToRemove);
                candToRemoveCell = chain.right(candCell, candToRemove)) {
                    chain.deactivate(candToRemoveCell, candToRemove);
                }
            }
            chain.deactivate(candCell, cand);
        }

        stepExactCover (res, curr, chain, solutionLimit);

        curr.pop_back();
        chain.batchUndo();
    }
}

std::vector<std::vector<int>> exactCover (const std::vector<std::vector<char>>& candidates, int solutionLimit) {
    std::vector<std::vector<int>> res;

    if (candidates.size() == 0)
        return res;

    DancingChain chain (candidates);
    std::vector<int> curr;

    stepExactCover(res, curr, chain, solutionLimit);

    return res;
}
