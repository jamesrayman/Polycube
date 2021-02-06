#include "polycube.h"

#include "vector.h"
#include "matrix.h"
#include "lattice.h"

template<std::size_t DIM>
Polycube<DIM>::Polycube () : rotations{ Matrix<DIM+1>::identity() } { }

template<std::size_t DIM>
Polycube<DIM>::Polycube (const Polycube<DIM>&) = default;

template<std::size_t DIM>
Polycube<DIM>::Polycube (const Lattice<bool, DIM>& other) : Lattice<bool, DIM>(other) {
    auto allRotations = Matrix<DIM+1>::allRotations(DIM);

    for (auto& rotation : allRotations) {
        rotation = Lattice<bool, DIM>::properTransformation(rotation);
        
        if (!Lattice<bool, DIM>::isomorphic(rotation * *this, rotations)) {
            rotations.push_back(rotation);
        }
    }
}

template<std::size_t DIM>
const std::vector<Matrix<DIM+1>>& Polycube<DIM>::allRotations () const {
    return rotations;
}

template<std::size_t DIM>
bool Polycube<DIM>::operator== (const Polycube<DIM>& other) const {
    return Lattice<bool, DIM>::isomorphic(other, Matrix<DIM+1>::allRotations(DIM));
}

template<std::size_t DIM>
bool Polycube<DIM>::operator!= (const Polycube<DIM>& other) const {
    return !(*this == other);

}

template<std::size_t DIM>
bool Polycube<DIM>::operator[] (const Vector<DIM>& index) const {
    return Lattice<bool, DIM>::operator[](index);
}

template<std::size_t DIM>
Polycube<DIM>& Polycube<DIM>::operator= (const Polycube<DIM>&) = default;