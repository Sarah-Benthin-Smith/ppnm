#pragma once
#include <vector>
#include <cmath>

class vector {
private:
    std::vector<double> data;

public:
    vector(int n);
    int size() const;

    double& operator[](int i);
    double operator[](int i) const;

    double norm() const;
};

/* vector arithmetic */

vector operator+(const vector& a, const vector& b);

vector operator-(const vector& a, const vector& b);

vector operator*(const vector& v, double c);

vector operator*(double c, const vector& v);

vector operator/(const vector& v, double c);