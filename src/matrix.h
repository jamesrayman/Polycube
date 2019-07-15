#pragma once

#include <array>

#include "vector.h"

template <std::size_t DIM>
class Matrix {
private:
    std::array<Vector<DIM>, DIM> data;
public:
    Matrix ();
    Matrix (const Matrix&);

    Matrix<DIM> operator* (const Matrix<DIM>&) const;
    Vector<DIM> operator* (const Vector<DIM>&) const;
    Vector<DIM> operator* (const Vector<DIM-1>&) const;

    Vector<DIM>& operator[] (int);
    
    Matrix<DIM>& operator= (const Matrix<DIM>&);

    static Matrix<DIM> axisRotation (int, int); // params: axis index and quater turns CCW
    static Matrix<DIM> translation (const Vector<DIM-1>&);
};

#include "matrix.tpp"