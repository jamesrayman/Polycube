#include "exact_cover.h"

#include <vector>
#include <algorithm>

#include "dancing_chain.h"

void stepExactCover (std::vector<std::vector<int>>& res, std::vector<int>& curr, DancingChain& chain) {
    if (chain.size() == 0) {
        res.push_back(curr);
        return;
    }
    
    int colToFill = chain.mostConstrained();

    for (int cand = chain.down(colToFill, 0); cand != 0; cand = chain.down(colToFill, cand)) {
        curr.push_back(cand);
        chain.startUndoBatch();
        

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
