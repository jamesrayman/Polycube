#pragma once

#include <array>
#include <initializer_list>

template<std::size_t DIM>
class Vector {
    std::array<int, DIM> data;
public:
    Vector ();
    Vector (const Vector<DIM>&);
    Vector (const std::initializer_list<int>&);

    std::size_t size () const;
    int dot (const Vector<DIM>&) const;

    Vector<DIM> operator+ (const Vector<DIM>&) const;
    Vector<DIM> operator- (const Vector<DIM>&) const;
    Vector<DIM> operator- () const;

    int& operator[] (int);
    const int& operator[] (int) const;

    Vector<DIM>& operator= (const Vector<DIM>&);

    bool operator== (const Vector<DIM>&) const;
    bool operator!= (const Vector<DIM>&) const;

    static Vector<DIM> unitAxis (int);
};

#include "vector.tpp"
