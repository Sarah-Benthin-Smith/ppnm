#ifndef PP_MATRIX_H
#define PP_MATRIX_H

#include "vec.h"
#include <vector>

namespace pp {

class matrix {
private:
    std::vector<vector> cols;

public:
    matrix();
    matrix(int rows, int cols);

    int rows() const;
    int cols_count() const;

    vector& operator[](int j);
    const vector& operator[](int j) const;

    matrix operator+(const matrix& other) const;

    vector operator*(const vector& v) const;

    void print() const;
};

}

#endif