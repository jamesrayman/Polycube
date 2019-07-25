#pragma once

#include <vector>

#include "polycube.h"

template<std::size_t DIM>
class PolycubeList {
private:
    using Element = std::pair<Polycube<DIM>, int>;
    std::vector<Element> list;

public:
    PolycubeList ();
    PolycubeList (const PolycubeList&);
    PolycubeList (const std::vector<Polycube<DIM>>&);

    std::size_t size () const;

    const Element& operator[] (int) const;
};