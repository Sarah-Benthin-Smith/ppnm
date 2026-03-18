#include "vec.h"
#include <stdexcept>

namespace pp {

vector::vector() {}

vector::vector(int n) : data(n) {}

vector::vector(std::initializer_list<double> list) : data(list) {}

int vector::size() const {
    return data.size();
}

double& vector::operator[](int i) {
    return data[i];
}

const double& vector::operator[](int i) const {
    return data[i];
}

vector vector::operator+(const vector& other) const {
    if (size() != other.size())
        throw std::runtime_error("Vector sizes must match");

    vector result(size());
    for (int i = 0; i < size(); i++)
        result[i] = data[i] + other[i];

    return result;
}

vector vector::operator-(const vector& other) const {
    if (size() != other.size())
        throw std::runtime_error("Vector sizes must match");

    vector result(size());
    for (int i = 0; i < size(); i++)
        result[i] = data[i] - other[i];

    return result;
}

double vector::dot(const vector& other) const {
    if (size() != other.size())
        throw std::runtime_error("Vector sizes must match");

    double result = 0;
    for (int i = 0; i < size(); i++)
        result += data[i] * other[i];

    return result;
}

void vector::print() const {
    for (double v : data)
        std::cout << v << " ";
    std::cout << std::endl;
}

}