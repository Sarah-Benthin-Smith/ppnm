#pragma once
#include <vector>
#include <functional>
#include "matrix.h"
#include "vector.h"
#include "qr.h"

using func = std::function<double(double)>;

pp::vector lsfit(
    const std::vector<func>& fs,
    const pp::vector& x,
    const pp::vector& y,
    const pp::vector& dy
);