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
Board<DIM> Board<DIM>::transform (const Matrix<DIM+1>& transformation) const {
    return Board<DIM>(Lattice<int, DIM>::transform(transformation));
}

template<std::size_t DIM>
bool Board<DIM>::renameEqual (const Board<DIM>& other) const {
    if (this->shape() != other.shape()) return false;

    auto allPositions = this->allPositions();
    std::unordered_map<int, int> corresp;
    std::unordered_map<int, int> invCorresp;
    corresp[0] = 0;
    invCorresp[0] = 0;

    for (const auto& position : allPositions) {
        int cube = (*this)[position], otherCube = other[position];

        if (corresp.count(cube)) {
            if (corresp[cube] != otherCube) return false;
        }
        else {
            if (invCorresp.count(otherCube)) return false;

            corresp[cube] = otherCube;
            invCorresp[otherCube] = cube;
        }
    }

    return true;
}

template<std::size_t DIM>
bool Board<DIM>::isomorphic (const Board<DIM>& other, const std::vector<Matrix<DIM+1>>& transforms) const {
    for (const auto& transform : transforms) {
        if (other.renameEqual(transform * *this)) {
            return true;
        }
    }
    return false;
}

template<std::size_t DIM>
bool Board<DIM>::operator== (const Board<DIM>& other) const {
    return isomorphic(other, Matrix<DIM+1>::allRotations(DIM));
}

template<std::size_t DIM>
bool Board<DIM>::operator!= (const Board<DIM>& other) const {
    return !(*this == other);
}

template<std::size_t DIM>
int Board<DIM>::operator[] (const Vector<DIM>& index) const {
    return Lattice<int, DIM>::operator[](index);
}