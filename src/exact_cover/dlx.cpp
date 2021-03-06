#include "dlx.h"

#include <vector>
#include <algorithm>
// #include <iostream>

#include "dancing_chain.h"
#include "util.h"

namespace exact_cover {
    // int z;

    void stepDlx (std::vector<Solution>& res, Solution& curr, DancingChain& chain, int solutionLimit) {
        if (chain.size() == 0) {
            res.push_back(curr);
            std::sort(res.back().begin(), res.back().end());

            return;
        }

        if (res.size() >= solutionLimit) return;

        int cellToFill = chain.mostConstrained();
        int candCount = chain.size(cellToFill) - 1;

        if (candCount == 0) {
            // z++;
            // res.push_back(curr);
            // std::sort(res.back().begin(), res.back().end());

            return;
        }

        int startCand = 0;
        int startCandIndex = util::rand_int(std::min(40, candCount));

        for (int i = 0; i < startCandIndex; i++) {
            startCand = chain.down(cellToFill, startCand);
        }

        for (int cand = chain.down(cellToFill, startCand); ; cand = chain.down(cellToFill, cand)) {
            if (cand == 0) {
                if (startCand == 0) {
                    break;
                }
                else {
                    continue;
                }
            }

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

            stepDlx(res, curr, chain, solutionLimit);

            curr.pop_back();
            chain.batchUndo();

            if (cand == startCand) {
                break;
            }
        }
    }

    std::vector<Solution> dlx (const Problem& problem, int solutionLimit) {
        std::vector<Solution> res;

        if (problem.size() == 0)
            return res;

        DancingChain chain(problem);
        Solution curr;

        // z = 0;
        stepDlx(res, curr, chain, solutionLimit);
        // std::cout << z << "\n";

        return res;
    }
};