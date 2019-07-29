#include "polycube_list.h"

template<std::size_t DIM>
PolycubeList<DIM>::PolycubeList () = default;

template<std::size_t DIM>
PolycubeList<DIM>::PolycubeList (const PolycubeList&) = default;

template<std::size_t DIM>
PolycubeList<DIM>::PolycubeList (const std::vector<Polycube<DIM>>& polycubes) {
    for (const auto& polycube : polycubes) {
        push(polycube, 1);
    }
}

template<std::size_t DIM>
int PolycubeList<DIM>::find (const Polycube<DIM>& polycube) const {
    for (int i = 0; i < size(); i++) {
        if (polycube == list[i].first) {
            return i;
        }
    }
    return -1;
}

template<std::size_t DIM>
void PolycubeList<DIM>::push (const Polycube<DIM>& polycube, int times) {
    int i = find(polycube);

    if (i == -1) {
        list.push_back({ polycube, times });
    }
    else {
        list[i].second += times;
    }
}

template<std::size_t DIM>
std::size_t PolycubeList<DIM>::size () const {
    return list.size();
}

template<std::size_t DIM>
const typename PolycubeList<DIM>::Element& PolycubeList<DIM>::operator[] (int index) const {
    return list[index];
}

template<std::size_t DIM>
PolycubeList<DIM>& PolycubeList<DIM>::operator= (const PolycubeList<DIM>& other) {
    list = other.list;

    return *this;
}