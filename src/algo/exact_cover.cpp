#include "exact_cover.h"

#include <vector>
#include <algorithm>

#include "dancing_chain.h"

void stepExactCover (std::vector<std::vector<int>>& res, std::vector<int>& curr, DancingChain& chain) {
    if (chain.size() == 0) {
        res.push_back(curr);
        return;
    }
    
    int cellToFill = chain.mostConstrained();

    for (int cand = chain.down(cellToFill, 0); cand != 0; cand = chain.down(cellToFill, cand)) {
        curr.push_back(cand);
        chain.startUndoBatch();
        
        for (int candCell = chain.right(cellToFill, cand); chain.active(cellToFill, cand); candCell = chain.right(cellToFill, cand)) {
            for (int candToRemove = chain.down(cellToFill, candCell); chain.active(cellToFill, candCell); candToRemove = chain.down(cellToFill, candCell)) {
                chain.deactivate(candCell, candToRemove);
            }
        }

        stepExactCover (res, curr, chain);

        curr.pop_back();
        chain.batchUndo();
    }
}

std::vector<std::vector<int>> exactCover (const std::vector<std::vector<char>>& candidates) {
    std::vector<std::vector<int>> res;
    DancingChain chain (candidates);

    std::vector<int> curr;
    stepExactCover(res, curr, chain);

    return res;
}
