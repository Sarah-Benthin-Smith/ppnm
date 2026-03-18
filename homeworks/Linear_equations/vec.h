#ifndef PP_VEC_H
#define PP_VEC_H

#include <iostream>
#include <vector>
#include <string>

namespace pp{

class vector {
private:
    std::vector<double> data;

public:
    vector();
    vector(int n);
    vector(std::initializer_list<double> list);

    int size() const;

    double& operator[](int i);
    const double& operator[](int i) const;

    vector operator+(const vector& other) const;
    vector operator-(const vector& other) const;
    double dot(const vector& other) const;

    void print() const;
};

}
#endif