#pragma once

#include <array>

template <std::size_t DIM>
class Vector {
    std::array<int, DIM> data;
public:
    Vector ();
    Vector (const Vector&);

    Vector<DIM> operator+ (const Vector&) const;
    Vector<DIM> operator- (const Vector&) const;
    Vector<DIM> operator- () const;

    int& operator[] (int);
    const int& operator[] (int) const;

    Vector<DIM>& operator= (const Vector&);

    static Vector<DIM> unitAxis (int);
};

#include "vector.tpp"
