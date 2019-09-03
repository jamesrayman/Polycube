#include "board.h"

template<std::size_t DIM>
Board<DIM>::Board () {
    nextCube = 1;
}

template<std::size_t DIM>
Board<DIM>::Board (const Board& other) = default;

template<std::size_t DIM>
Board<DIM>::Board (const Lattice<int, DIM>& other) : Lattice<int, DIM>(other) { 
    auto allPos = Lattice<int, DIM>::allPositions();
    std::unordered_map<int, int> cubeFreq;

    for (const auto& i : allPos) {
        int val = Lattice<int, DIM>::at(i);

        if (val != 0) {
            cubeFreq[val]++;
        }
    }

    nextCube = 1;

    while (cubeFreq[nextCube] > 0) {
        nextCube++;
    }
}

template<std::size_t DIM>
bool Board<DIM>::fits (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {
    auto allPositions = polycube.allPositions();
    
    for (const auto& position : allPositions) {
        auto tPosition = transformation * position;
        if (polycube[position] && (!Lattice<int, DIM>::inBounds(tPosition) || (*this)[tPosition] != 0)) {
            return false;
        }
    }

    return true;
}

template<std::size_t DIM>
void Board<DIM>::put (int index, int value) {
    (*this)[this->vectorIndex(index)] = value;
}

template<std::size_t DIM>
bool Board<DIM>::place (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {
    auto allPositions = polycube.allPositions();

    if (!fits(polycube, transformation)) return false;

    for (const auto& position : allPositions) {
        auto tPosition = transformation * position;
        
        if (polycube[position]) {
            (*this)[tPosition] = nextCube;
        }
    }

    nextCube++;

    return true;
}

template<std::size_t DIM>
void Board<DIM>::unplace (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {
    auto allPositions = polycube.allPositions();

    for (const auto& position : allPositions) {
        auto tPosition = transformation * position;
        
        if (polycube[position]) {
            (*this)[tPosition] = 0;
        }
    }

    nextCube--;
}

template<std::size_t DIM>
bool Board<DIM>::operator== (const Board<DIM>& other) const {
    return false;
}

template<std::size_t DIM>
bool Board<DIM>::operator!= (const Board<DIM>& other) const {
    return !(*this == other);
}

template<std::size_t DIM>
int Board<DIM>::operator[] (const Vector<DIM>& index) const {
    return Lattice<int, DIM>::operator[](index);
}