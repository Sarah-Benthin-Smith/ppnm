#include <iostream>
#include <fstream>
#include <cmath>

#include "ode.h"

// vector f(double x, vector y){
//     (void)x;                    // To avoid error for not using x 
//     return y;
// }

vector f(double x, vector y){ // Example
    (void)x;

    vector dydx(2);

    dydx[0] = y[1];     // u' = v
    dydx[1] = -y[0];    // v' = -u

    return dydx;
}

vector pend(double t, vector y1){ // Pendulum assignment
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

vector orbit(double phi, vector y2){ // Assignment b for 3 points
    (void)phi;

    double eps = 0.01;

    vector dydphi(2);

    double u = y2[0];
    double up = y2[1];

    dydphi[0] = up;
    dydphi[1] = 1.0 - u + eps*u*u;

    return dydphi;
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

    // Pendulum assignment
    vector y10(2);
    y10[0] = M_PI - 0.1;
    y10[1] = 0.0;

    auto [ts, ys1] = driver(
        pend,
        0.0,
        10.0,
        y10,
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


    // Orbit assignment
    vector y20(2); // Circular
    y20[0] = 1.0;
    y20[1] = 0.0;
    auto [phis, ys2] = driver(
        orbit,
        0.0,
        50.0,     // many rotations
        y20,
        0.05,
        1e-5,
        1e-5
    );

    vector y20_(2); // Elliptical
    y20_[0] = 1.0;
    y20_[1] = -0.5;
    auto [phis_, ys2_] = driver(
        orbit,
        0.0,
        50.0,     // many rotations
        y20_,
        0.05,
        1e-5,
        1e-5
    );

    std::ofstream orout("orbit_cir.data");

    for(size_t i=0;i<phis.size();i++){

        // Circular
        double phi = phis[i];
        double u   = ys2[i][0];

        double r = 1.0/u;

        double x2 = r * cos(phi);
        double y2 = r * sin(phi);

        orout << x2 << " " << y2 << "\n";
    }

    std::ofstream epsout("orbit_eps.data");

    for(size_t i=0;i<phis_.size();i++){

        // Elliptical
        double phi_ = phis_[i];
        double u_   = ys2_[i][0];

        double r_ = 1.0/u_;

        double x2_ = r_ * cos(phi_);
        double y2_ = r_ * sin(phi_);

        epsout << x2_ << " " << y2_ << "\n";
    }        

    return 0;
}