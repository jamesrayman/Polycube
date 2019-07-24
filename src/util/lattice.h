#pragma once

#include <vector>
#include <initializer_list>

#include "vector.h"
#include "matrix.h"

template<typename T, std::size_t DIM>
class Lattice {
    friend class Lattice<T, DIM+1>;
private:
    std::vector<Lattice<T, DIM-1>> data;

    template<std::size_t N>
    T& at (const Vector<N>&);

    template<std::size_t N>
    const T& at (const Vector<N>&) const;
public:
    Lattice ();
    Lattice (const Lattice&);
    Lattice (const std::initializer_list<Lattice<T, DIM-1>>&);

    template<std::size_t N>
    Lattice (const Vector<N>&, const T& = T());

    int dimension () const;
    Vector<DIM> shape () const;
    Matrix<DIM+1> properTransformation (const Matrix<DIM+1>&) const;
    std::vector<Vector<DIM>> allPositions () const;
    Lattice<T, DIM> transform (const Matrix<DIM+1>&) const;
    bool isomorph (const Lattice<T, DIM>, const std::vector<Matrix<DIM+1>>&);

    T& operator[] (const Vector<DIM>&);
    const T& operator[] (const Vector<DIM>&) const;

    bool operator== (const Lattice<T, DIM>&) const;
    bool operator!= (const Lattice<T, DIM>&) const;
};

template<typename T>
class Lattice<T, 0> {
    friend class Lattice<T, 1>;
private:
    T value;

    template<std::size_t N>
    T& at (const Vector<N>&);

    template<std::size_t N>
    const T& at (const Vector<N>&) const;

public:
    Lattice ();
    Lattice (const T&);
    Lattice (const Lattice&);

    template<std::size_t N>
    Lattice(const Vector<N>&, const T& = T());

    int dimension () const;
    Vector<0> shape () const;
    Lattice<T, 0> transform (const Matrix<0>&) const;

    T& operator[] (const Vector<0>&);
    const T& operator[] (const Vector<0>&) const;

    bool operator== (const Lattice<T, 0>&) const;
    bool operator!= (const Lattice<T, 0>&) const;
};

#include "lattice.tpp"
