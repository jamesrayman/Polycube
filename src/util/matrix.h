#pragma once

#include <array>
#include <vector>
#include <bitset>
#include <initializer_list>

template<std::size_t DIM>
class Matrix;

#include "vector.h"
#include "lattice.h"

template<std::size_t DIM>
class Matrix {
private:
    std::array<Vector<DIM>, DIM> data;

    Vector<DIM> row (int) const;

    static void generateAllRotations(std::vector<Matrix<DIM>>&, Matrix<DIM>&, std::bitset<DIM>&, std::vector<int>&, int, int);
public:
    Matrix ();
    Matrix (const Matrix&);
    Matrix (const std::initializer_list<Vector<DIM>>&);

    size_t size () const;

    Matrix<DIM> operator* (const Matrix<DIM>&) const;
    Vector<DIM> operator* (const Vector<DIM>&) const;
    Vector<DIM-1> operator* (const Vector<DIM-1>&) const;
    template<typename T>
    Lattice<T, DIM-1> operator* (const Lattice<T, DIM-1>&) const;

    Vector<DIM>& operator[] (int);
    const Vector<DIM>& operator[] (int) const;
    
    Matrix<DIM>& operator= (const Matrix<DIM>&);

    static Matrix<DIM> identity ();
    static Matrix<DIM> planeRotation (int, int, int);
    static std::vector<Matrix<DIM>> allRotations(int);;
    static Matrix<DIM> translation (const Vector<DIM-1>&);
};

#include "matrix.tpp"