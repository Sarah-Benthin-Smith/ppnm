#include "matrix.h"
#include <stdexcept>
#include <iostream>
#include <vector>
namespace pp {

matrix::matrix() {}

matrix::matrix(int rows, int cols) {
    for (int j = 0; j < cols; j++)
        this->cols.push_back(vector(rows));
}

int matrix::rows() const {
    if (cols.empty()) return 0;
    return cols[0].size();
}

int matrix::cols_count() const {
    return cols.size();
}

vector& matrix::operator[](int j) {
    return cols[j];
}

const vector& matrix::operator[](int j) const {
    return cols[j];
}

matrix matrix::operator+(const matrix& other) const {
    if (rows() != other.rows() || cols_count() != other.cols_count())
        throw std::runtime_error("Matrix sizes must match");

    matrix result(rows(), cols_count());

    for (int j = 0; j < cols_count(); j++)
        result[j] = cols[j] + other[j];

    return result;
}

vector matrix::operator*(const vector& v) const {
    if (cols_count() != v.size())
        throw std::runtime_error("Dimension mismatch");

    vector result(rows());

    for (int j = 0; j < cols_count(); j++)
        for (int i = 0; i < rows(); i++)
            result[i] += cols[j][i] * v[j];

    return result;
}

void matrix::print() const {
    for (int i = 0; i < rows(); i++) {
        for (int j = 0; j < cols_count(); j++)
            std::cout << cols[j][i] << " ";
        std::cout << std::endl;
    }
}

}