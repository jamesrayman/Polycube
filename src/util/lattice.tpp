#include "lattice.h"
#include "util.h"

template<typename T, std::size_t DIM>
Lattice<T, DIM>::Lattice () = default;

template<typename T, std::size_t DIM>
template<std::size_t N>
Lattice<T, DIM>::Lattice (const Vector<N>& shape, const T& value) : data(shape[N-DIM], Lattice<T, DIM-1>(shape, value)) { }

template<typename T, std::size_t DIM>
Lattice<T, DIM>::Lattice (const Lattice&) = default;

template<typename T, std::size_t DIM>
Lattice<T, DIM>::Lattice (const std::initializer_list<Lattice<T, DIM-1>>& data) : data(data) {}


template<typename T, std::size_t DIM>
template<std::size_t N>
T& Lattice<T, DIM>::at (const Vector<N>& index) {
    return data[index[N-DIM]].at(index);
}

template<typename T, std::size_t DIM>
template<std::size_t N>
const T& Lattice<T, DIM>::at (const Vector<N>& index) const {
    return data[index[N-DIM]].at(index);
}

template<typename T, std::size_t DIM>
int Lattice<T, DIM>::dimension () const {
    return DIM;
}

template<typename T, std::size_t DIM>
Vector<DIM> Lattice<T, DIM>::shape () const {
    Vector<DIM> res;
    res[0] = data.size();

    if (data.size() == 0) return res;
    auto subshape = data[0].shape();

    for (int i = 0; i < DIM-1; i++) {
        res[i+1] = subshape[i];
    }

    return res;
}

template<typename T, std::size_t DIM>
Matrix<DIM+1> Lattice<T, DIM>::properTransformation (const Matrix<DIM+1>& transform) const {
    auto shape = this->shape();
    auto newShape = transform * shape;

    Vector<DIM> translation;

    for (int i = 0; i < DIM; i++) {
        if (newShape[i] < 0) {
            translation[i] = -newShape[i] - 1;
        }
    }

    return Matrix<DIM+1>::translation(translation) * transform;
}

template<typename T, std::size_t DIM>
std::vector<Vector<DIM>> Lattice<T, DIM>::allPositions () const {
    return util::allMinors(shape());
}


template<typename T, std::size_t DIM>
Lattice<T, DIM> Lattice<T, DIM>::transform (const Matrix<DIM+1>& rotation) const {
    auto properRotation = properTransformation(rotation);
    auto allPositions = this->allPositions();
    auto resShape = rotation * shape();

    for (int i = 0; i < DIM; i++) {
        if (resShape[i] < 0) {
            resShape[i] = -resShape[i];
        }
    }

    Lattice<T, DIM> res (resShape);

    for (const auto& position : allPositions) {
        res[properRotation * position] = (*this)[position];
    }

    return res;
}

template<typename T, std::size_t DIM>
T& Lattice<T, DIM>::operator[] (const Vector<DIM>& index) {
    return at(index);
}

template<typename T, std::size_t DIM>
const T& Lattice<T, DIM>::operator[] (const Vector<DIM>& index) const {
    return at(index);
}



template<typename T>
Lattice<T, 0>::Lattice () = default;

template<typename T>
Lattice<T, 0>::Lattice (const T& value) : value(value) { }

template<typename T>
template<std::size_t N>
Lattice<T, 0>::Lattice (const Vector<N>& shape, const T& value) : value(value) { }

template<typename T>
Lattice<T, 0>::Lattice (const Lattice&) = default;

template<typename T>
template<std::size_t N>
T& Lattice<T, 0>::at (const Vector<N>& index) {
    return value;
}

template<typename T>
template<std::size_t N>
const T& Lattice<T, 0>::at (const Vector<N>& index) const {
    return value;
}

template<typename T>
int Lattice<T, 0>::dimension () const {
    return 0;
}

template<typename T>
Vector<0> Lattice<T, 0>::shape () const {
    return Vector<0>();
}

template<typename T>
Lattice<T, 0> Lattice<T, 0>::transform (const Matrix<0>& rotation) const { }

template<typename T>
T& Lattice<T, 0>::operator[] (const Vector<0>& index) {
    return at(index);
}

template<typename T>
const T& Lattice<T, 0>::operator[] (const Vector<0>& index) const {
    return at(index);
}

