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

vector pend(double t, vector y1){
    (void)t;
    double b = 0.25;
    double c = 5.0;
    vector dydt(2);

    double theta = y1[0];
    double omega = y1[1];

    dydt[0] = omega;
    dydt[1] = -b*omega - c*std::sin(theta);

    return dydt;
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

    vector y10(2);
    y10[0] = M_PI - 0.1;
    y10[1] = 0.0;

    auto [ts, ys1] = driver(
        pend,
        0.0,
        10.0,
        y0,
        0.1,
        1e-4,
        1e-4
    );

    std::ofstream pendout("pendulum.data");

    for(size_t i=0;i<ts.size();i++){
        pendout << ts[i] << " "
                << ys1[i][0] << " "   // theta
                << ys1[i][1] << "\n"; // omega
    }


    return 0;
}