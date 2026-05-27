#pragma once

#include <functional>
#include "matrix.h"

struct ann {

    int n;

    pp::vector p;

    ann(int n_);

    double activation(double x);

    double activation_derivative(double x);

    double response(double x);

    double cost(pp::vector xs, pp::vector ys);

    pp::vector gradient(pp::vector xs, pp::vector ys);

    void train(pp::vector xs, pp::vector ys);
};