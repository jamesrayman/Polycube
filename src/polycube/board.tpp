#include "board.h"
#include <iostream>

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
bool Board<DIM>::secure (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {
    auto translations = Matrix<DIM+1>::allUnitTranslations();
    auto allPositions = polycube.allPositions();
    bool res = true;

    place(polycube, transformation);

    for (const auto& translation : translations) {
        if (translation[DIM][1] != 0) continue;

        bool slidable = true;

        for (const auto& position : allPositions) {
            auto tPosition = translation * transformation * position;

            if (polycube[position] && Lattice<int, DIM>::inBounds(tPosition) && (*this)[tPosition] != nextCube-1) {
                slidable = false;
                break;
            }
        }

        if (slidable) {
            res = false;
            break;
        }
    }
    
    unplace(polycube, transformation);

    return res;
}

template<std::size_t DIM>
bool Board<DIM>::fits (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation, int sturdyLayers) {
    auto allPositions = polycube.allPositions();
    bool sturdy = false;
    
    for (const auto& position : allPositions) {
        auto tPosition = transformation * position;
        if (polycube[position] && (!Lattice<int, DIM>::inBounds(tPosition) || (*this)[tPosition] != 0)) {
            return false;
        }
        if (polycube[position] && tPosition[1] >= this->shape()[1] - sturdyLayers) {
            sturdy = true;
        }      
    }

    return sturdy || secure(polycube, transformation);
}

template<std::size_t DIM>
void Board<DIM>::put (int index, int value) {
    (*this)[this->vectorIndex(index)] = value;
}

template<std::size_t DIM>
bool Board<DIM>::place (const Polycube<DIM>& polycube, const Matrix<DIM+1>& transformation) {
    auto allPositions = polycube.allPositions();

    if (!fits(polycube, transformation, this->shape()[1])) return false;

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