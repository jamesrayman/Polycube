#pragma once

#include <vector>

#include "block.h"

template<std::size_t DIM>
class BlockList {
private:
    using Element = std::pair<Block<DIM>, int>;
    std::vector<Element> list;

public:
    BlockList ();
    BlockList (const BlockList&);
    BlockList (const std::vector<Block<DIM>>&);

    std::size_t size () const;

    const Element& operator[] (int) const;
};