#ifndef ROQAI_H
#define ROQAI_H

#include <cmath>
#include <functional>

// std::numeric_limits<double>::quiet_NaN()

double integrate(
    std::function<double(double)> f,
    double a,
    double b,
    double acc = 1e-3,
    double eps = 1e-3,
    double f2 = NAN,
    double f3 = NAN
);

#endif