#include <iostream>
#include <fstream>
#include <cmath>

#include "ode.h"

// vector f(double x, vector y){
//     (void)x;                    // To avoid error for not using x 
//     return y;
// }

vector f(double x, vector y){
    (void)x;

    vector dydx(2);

    dydx[0] = y[1];     // u' = v
    dydx[1] = -y[0];    // v' = -u

    return dydx;
}

int main(){

    vector y0(2);
    y0[0] = 1;
    y0[1] = 0;

    auto [xs,ys] = driver(
        f,
        0,
        20,
        y0,
        0.1,
        1e-3,
        1e-3
    );

    std::ofstream out("out.data");

    for(size_t i=0;i<xs.size();i++){
        out << xs[i] << " "
            << ys[i][0] << " "
            << cos(xs[i]) << "\n";
    }

    return 0;
}