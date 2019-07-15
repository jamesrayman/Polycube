#include "matrix.h"

template <std::size_t DIM>
Matrix<DIM>::Matrix () {
    for (int i = 0; i < DIM; i++) {
        (*this)[i] = Vector<DIM>();
    }
}

template <std::size_t DIM>
Matrix<DIM>::Matrix (const Matrix&) = default;

template <std::size_t DIM>
Matrix<DIM> Matrix<DIM>::operator* (const Matrix<DIM>& other) const {

}

template <std::size_t DIM>
Vector<DIM> Matrix<DIM>::operator* (const Vector<DIM>& other) const {

}

template <std::size_t DIM>
Vector<DIM> Matrix<DIM>::operator* (const Vector<DIM-1>& other) const {
    
}

template <std::size_t DIM>
Matrix<DIM>& Matrix<DIM>::operator= (const Matrix<DIM>& other) {
    data = other.data;

    return *this;
}

template <std::size_t DIM>
Vector<DIM>& Matrix<DIM>::operator[] (int i) {
    return data[i];
}

template <std::size_t DIM>
Matrix<DIM> Matrix<DIM>::axisRotation (int axis, int qturns) {

}

template <std::size_t DIM>
Matrix<DIM> Matrix<DIM>::translation (const Vector<DIM-1>& shift) {
    Matrix<DIM> res;

    for (int i = 0; i < DIM-1; i++) {
        res[DIM-1][i] = shift[i];
    }

    for (int i = 0; i < DIM; i++) {
        res[i][i] = 1;
    }

    return res;
}