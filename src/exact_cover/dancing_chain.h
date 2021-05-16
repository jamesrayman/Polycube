#pragma once

#include <vector>

#include "exact_cover.h"

namespace exact_cover {
    class DancingChain;

    class DancingLink {
        friend class DancingChain;
    private:
        DancingChain& chain;

        int up, down, left, right;
        bool active;
        int col, row;
        int size;
    public:
        DancingLink () = delete;
        DancingLink (const DancingLink&) = default;
        DancingLink (DancingChain&, int, int, bool);
        
        void deactivate ();
        void reactivate ();
    };

    class DancingChain {
        friend class DancingLink;
    private:
        std::vector<std::vector<DancingLink>> links;
        int cellsActive;
        
        std::vector<int> history;

        DancingLink& at (int, int);
        const DancingLink& at (int, int) const;
    public:
        DancingChain ();
        DancingChain (const DancingChain&);
        DancingChain (const Problem&);

        void undo ();
        void batchUndo ();
        void startUndoBatch ();

        bool active (int, int) const;
        void deactivate (int, int);

        int up (int, int) const;
        int down (int, int) const;
        int left (int, int) const;
        int right (int, int) const;

        int mostConstrained () const;
        int size () const;
        int size (int) const;
    };
}
