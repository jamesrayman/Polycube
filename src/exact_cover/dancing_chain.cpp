#include "dancing_chain.h"

namespace exact_cover {
    DancingLink::DancingLink (DancingChain& chain, int col, int row, bool active) : 
        chain(chain), col(col), row(row), active(active), size(0), up(-1), down(-1), left(-1), right(-1) { }

    void DancingLink::deactivate () {
        chain.at(right, row).left = left;
        chain.at(left, row).right = right;
        chain.at(col, up).down = down;
        chain.at(col, down).up = up;
        
        if (row == 0) chain.cellsActive--;
        else chain.at(col, 0).size--;
        active = false;
    }
    void DancingLink::reactivate () {
        chain.at(right, row).left = col;
        chain.at(left, row).right = col;
        chain.at(col, up).down = row;
        chain.at(col, down).up = row;

        if (row == 0) chain.cellsActive++;
        else chain.at(col, 0).size++;
        active = true;
    }


    DancingChain::DancingChain () = default;
    DancingChain::DancingChain (const DancingChain&) = default;
    DancingChain::DancingChain (const Problem& problem) {
        int nCells = problem[0].size(), nCands = problem.size();
        cellsActive = nCells;

        for (int col = 0; col <= nCells; col++) {
            links.emplace_back();
            for (int row = 0; row <= nCands; row++) {
                bool linkActive;

                if (row == 0) linkActive = true;
                else if (col == 0) linkActive = false;
                else linkActive = problem[row-1][col-1];

                links.back().emplace_back(*this, col, row, linkActive);
            }
        }

        for (int row = 0; row < links[0].size(); row++) {
            int initCol = -1;
            int prevCol = -1;
            for (int col = 0; ; ++col %= links.size()) {
                if (!active(col, row)) {
                    if (initCol == -1 && col == links.size() - 1) break;
                    continue;
                }

                if (initCol == -1) {
                    initCol = prevCol = col;
                }
                else {
                    if (at(prevCol, row).right != -1) break;

                    at(prevCol, row).right = col;
                    at(col, row).left = prevCol;

                    prevCol = col;
                }
            }
        }

        for (int col = 0; col < links.size(); col++) {
            int initRow = -1;
            int prevRow = -1;
            for (int row = 0; ; ++row %= links[0].size()) {
                if (!active(col, row)) {
                    if (initRow == -1 && row == links[0].size() - 1) break;
                    continue;
                }

                if (initRow == -1) {
                    initRow = prevRow = row;
                }
                else {
                    if (at(col, prevRow).down != -1) break;

                    at(col, prevRow).down = row;
                    at(col, row).up = prevRow;
                    at(col, 0).size++;

                    prevRow = row;
                }
            }
        }
    }

    DancingLink& DancingChain::at (int col, int row) {
        return links[col][row];
    }

    const DancingLink& DancingChain::at (int col, int row) const {
        return links[col][row];
    }


    void DancingChain::undo () {
        int row = history.back(); history.pop_back();
        int col = history.back(); history.pop_back();

        links[col][row].reactivate();
    }
    void DancingChain::batchUndo () {
        while (history.back() != -1) {
            undo();
        }
        
        history.pop_back();
    }
    void DancingChain::startUndoBatch () {
        history.push_back(-1);
    }

    bool DancingChain::active (int col, int row) const {
        return at(col, row).active;
    }
    void DancingChain::deactivate (int col, int row) {
        history.push_back(col);
        history.push_back(row);

        at(col, row).deactivate();
    }

    int DancingChain::up (int col, int row) const {
        return at(col, row).up;
    }
    int DancingChain::down (int col, int row) const {
        return at(col, row).down;
    }
    int DancingChain::left (int col, int row) const {
        return at(col, row).left;
    }
    int DancingChain::right (int col, int row) const {
        return at(col, row).right;
    }

    int DancingChain::mostConstrained () const {
        int bestIndex = right(0, 0);

        for (int index = right(0, 0); index != 0; index = right(index, 0)) {
            if (size(index) < size(bestIndex))
                bestIndex = index;
        }

        return bestIndex;
    }
    int DancingChain::size () const {
        return cellsActive;
    }

    int DancingChain::size (int cell) const {
        return at(cell, 0).size;
    }
}