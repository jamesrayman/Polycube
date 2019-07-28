#include "board.h"

template<std::size_t DIM>
Board<DIM>::Board () = default;

template<std::size_t DIM>
Board<DIM>::Board (const Board& other) = default;

template<std::size_t DIM>
Board<DIM>::Board (const Lattice<int, DIM>& other) : Lattice<int, DIM>(other) { 
    auto allPos = Lattice<int, DIM>::allPositions();

    for (const auto& i : allPos) {
        int val = Lattice<int, DIM>::at(i);

        if (val != 0) {
            cubeFreq[val]++;
        }
    }
}

template<std::size_t DIM>
void Board<DIM>::setAt (const Vector<DIM>& index, int val) {
    auto& cell = at(index);

    if (cell != 0) cubeFreq[cell]--;
    if (val != 0) cubeFreq[val]++;

    cell = val;
}

template<std::size_t DIM>
bool Board<DIM>::place (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {

}

template<std::size_t DIM>
bool Board<DIM>::unplace (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {

}

template<std::size_t DIM>
Board<DIM> Board<DIM>::transform (const Matrix<DIM+1>& transformation) const {

}

template<std::size_t DIM>
bool Board<DIM>::operator== (const Board<DIM>& other) const {

}

template<std::size_t DIM>
bool Board<DIM>::operator!= (const Board<DIM>& other) const {
    return !(*this == other);
}

template<std::size_t DIM>
int Board<DIM>::operator[] (const Vector<DIM>& index) const {
    return Lattice<int, DIM>::operator[](index);
}