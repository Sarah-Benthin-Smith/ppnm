#include "ROQAI.h"

#include <cmath>

double integrate(
    std::function<double(double)> f,
    double a,
    double b,
    double acc,
    double eps,
    double f2,
    double f3
){
    double h = b - a;

    if (std::isnan(f2)) {
        f2 = f(a + 2*h/6.0);
        f3 = f(a + 4*h/6.0);
    }

    double f1 = f(a + 1*h/6.0);
    double f4 = f(a + 5*h/6.0);

    double Q = (2*f1 + f2 + f3 + 2*f4)/6.0 * h;
    double q = (f1 + f2 + f3 + f4)/4.0 * h;

    double err = std::abs(Q - q);
    double tol = acc + eps * std::abs(Q);

    if (err < tol) {
        return Q;
    }
    else {
        double mid = (a + b)/2.0;

        return integrate(f, a, mid,
                          acc/std::sqrt(2.0), eps,
                          f1, f2)
             + integrate(f, mid, b,
                          acc/std::sqrt(2.0), eps,
                          f3, f4);
    }
}