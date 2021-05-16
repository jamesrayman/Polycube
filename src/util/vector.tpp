#include "vector.h"

#include <algorithm>

template<std::size_t DIM>
Vector<DIM>::Vector () {
    for (int i = 0; i < DIM; i++) {
        (*this)[i] = 0;
    }
}

template<std::size_t DIM>
Vector<DIM>::Vector (const Vector<DIM>& other) = default;

template<std::size_t DIM>
Vector<DIM>::Vector (const std::initializer_list<int>& data) {
    std::copy(data.begin(), data.end(), this->data.begin());
}

template<std::size_t DIM>
std::size_t Vector<DIM>::size () const {
    return DIM;
}

template<std::size_t DIM>
int Vector<DIM>::dot (const Vector<DIM>& other) const {
    int res = 0;

    for (int i = 0; i < DIM; i++) {
        res += (*this)[i] * other[i];
    }

    return res;
}

template<std::size_t DIM>
Vector<DIM> Vector<DIM>::operator+ (const Vector& other) const {
    Vector<DIM> res;

    for (int i = 0; i < DIM; i++) {
        res[i] = (*this)[i] + other[i];
    }

    return res;
}

template<std::size_t DIM>
Vector<DIM> Vector<DIM>::operator- (const Vector& other) const {
    return *this + -other;
}

template<std::size_t DIM>
Vector<DIM> Vector<DIM>::operator- () const {
    Vector<DIM> res;

    for (int i = 0; i < DIM; i++) {
        res[i] = -(*this)[i];
    }

    return res;
}

template<std::size_t DIM>
int& Vector<DIM>::operator[] (int index) {
    return data[index];
}

template<std::size_t DIM>
const int& Vector<DIM>::operator[] (int index) const {
    return data[index];
}


template<std::size_t DIM>
Vector<DIM>& Vector<DIM>::operator= (const Vector& other) {
    data = other.data;
    
    return *this;
}

template<std::size_t DIM>
bool Vector<DIM>::operator== (const Vector<DIM>& other) const {
    return data == other.data;
}

template<std::size_t DIM>
bool Vector<DIM>::operator!= (const Vector<DIM>& other) const {
    return !(*this == other);
}

template<std::size_t DIM>
Vector<DIM> Vector<DIM>::unitAxis (int axis) {
    Vector<DIM> res;

    res[axis] = 1;

    return res;
}