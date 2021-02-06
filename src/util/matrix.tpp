#include "matrix.h"
#include "util.h"

#include <algorithm>

template<std::size_t DIM>
Matrix<DIM>::Matrix () {
    for (int i = 0; i < DIM; i++) {
        (*this)[i] = Vector<DIM>();
    }
}

template<std::size_t DIM>
Matrix<DIM>::Matrix (const Matrix&) = default;

template<std::size_t DIM>
Matrix<DIM>::Matrix (const std::initializer_list<Vector<DIM>>& data) {
    std::copy(data.begin(), data.end(), this->data.begin());
}

template<std::size_t DIM>
std::size_t Matrix<DIM>::size () const {
    return DIM;
}

template<std::size_t DIM>
Vector<DIM> Matrix<DIM>::row (int index) const {
    Vector<DIM> res;

    for (int i = 0; i < DIM; i++) {
        res[i] = (*this)[i][index];
    }

    return res;
}


template<std::size_t DIM>
Matrix<DIM> Matrix<DIM>::operator* (const Matrix<DIM>& other) const {
    Matrix<DIM> res;

    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            res[i][j] = row(j).dot(other[i]);
        }
    }

    return res;
}

template<std::size_t DIM>
Vector<DIM> Matrix<DIM>::operator* (const Vector<DIM>& other) const {
    Vector<DIM> res;

    for (int i = 0; i < DIM; i++) {
        res[i] = row(i).dot(other);
    }

    return res;
}

template<std::size_t DIM>
Vector<DIM-1> Matrix<DIM>::operator* (const Vector<DIM-1>& other) const {
    Vector<DIM> proper;

    for (int i = 0; i < DIM-1; i++) {
        proper[i] = other[i];
    }

    proper[DIM-1] = 1;

    Vector<DIM> properRes = *this * proper;
    Vector<DIM-1> res;

    for (int i = 0; i < DIM-1; i++) {
        res[i] = properRes[i];
    }

    return res;
}


template<std::size_t DIM>
template<typename T>
Lattice<T, DIM-1> Matrix<DIM>::operator* (const Lattice<T, DIM-1>& lattice) const {
    return lattice.transform(*this);
}

template<std::size_t DIM>
Matrix<DIM>& Matrix<DIM>::operator= (const Matrix<DIM>& other) {
    data = other.data;

    return *this;
}

template<std::size_t DIM>
bool Matrix<DIM>::operator== (const Matrix<DIM>& other) const {
    return data == other.data;
}

template<std::size_t DIM>
bool Matrix<DIM>::operator!= (const Matrix<DIM>& other) const {
    return !(*this == other);
}


template<std::size_t DIM>
Vector<DIM>& Matrix<DIM>::operator[] (int i) {
    return data[i];
}

template<std::size_t DIM>
const Vector<DIM>& Matrix<DIM>::operator[] (int i) const {
    return data[i];
}

template<std::size_t DIM>
Matrix<DIM> Matrix<DIM>::identity () {
    Matrix<DIM> res;
    
    for (int i = 0; i < DIM; i++) {
        res[i][i] = 1;
    }

    return res;
}

template<std::size_t DIM>
Matrix<DIM> Matrix<DIM>::planeRotation (int xAxis, int yAxis, int qturns) {
    Matrix<DIM> res = identity();

    res[xAxis][xAxis] = util::chi(qturns+1);
    res[xAxis][yAxis] = util::chi(qturns);
    res[yAxis][xAxis] = util::chi(qturns+2);
    res[yAxis][yAxis] = util::chi(qturns+1);

    return res;
}

template<std::size_t DIM>
void Matrix<DIM>::generateAllRotations (std::vector<Matrix<DIM>>& res, Matrix<DIM>& curr, 
                                        std::bitset<DIM>& mask, std::vector<int>& perm, int det, int n) {
    int i = perm.size();
    
    if (i == n) {
        if (det * util::sgn(perm) == 1) {
            res.push_back(curr);
        }
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!mask[j]) {
            mask[j] = true;
            perm.push_back(j);
            curr[i][j] = 1;

            generateAllRotations(res, curr, mask, perm, det, n);

            curr[i][j] = -1;

            generateAllRotations(res, curr, mask, perm, -det, n);

            mask[j] = false;
            perm.pop_back();
            curr[i][j] = 0;
        }
    }
}

template<std::size_t DIM>
std::vector<Matrix<DIM>> Matrix<DIM>::allRotations (int dimensions) {
    std::vector<Matrix<DIM>> res;
    Matrix<DIM> mat;
    std::bitset<DIM> mask;
    std::vector<int> v;

    for (int i = dimensions; i < DIM; i++) {
        mat[i][i] = 1;
    }

    generateAllRotations(res, mat, mask, v, 1, dimensions);

    return res;
}

template<std::size_t DIM>
std::vector<Matrix<DIM>> Matrix<DIM>::allImproperRotations (int dimensions) {
    std::vector<Matrix<DIM>> res;
    Matrix<DIM> mat;
    std::bitset<DIM> mask;
    std::vector<int> v;

    for (int i = dimensions; i < DIM; i++) {
        mat[i][i] = 1;
    }

    generateAllRotations(res, mat, mask, v, 1, dimensions);
    generateAllRotations(res, mat, mask, v, -1, dimensions);

    return res;
}

template<std::size_t DIM>
std::vector<Matrix<DIM>> Matrix<DIM>::allUnitTranslations () {
    std::vector<Matrix<DIM>> res;
    Vector<DIM-1> shift;

    for (int i = 0; i < DIM-1; i++) {
        shift[i] = 1;
        res.push_back(Matrix<DIM>::translation(shift));

        shift[i] = -1;
        res.push_back(Matrix<DIM>::translation(shift));
        
        shift[i] = 0;
    }

    return res;
}



template<std::size_t DIM>
Matrix<DIM> Matrix<DIM>::translation (const Vector<DIM-1>& shift) {
    Matrix<DIM> res = identity();

    for (int i = 0; i < DIM-1; i++) {
        res[DIM-1][i] = shift[i];
    }

    return res;
}