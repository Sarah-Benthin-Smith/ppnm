#include "matrix.h"
#include <cmath>
#include "qr.h"


pp::vector gradient(
    std::function<double(pp::vector)> f,
    pp::vector x
){
    double fx = f(x);

    pp::vector g(x.size());

    for(int i=0; i<x.size(); i++){

        double dx = (1+fabs(x[i]))*pow(2,-26);

        x[i] += dx;

        g[i] = (f(x)-fx)/dx;

        x[i] -= dx;
    }

    return g;
}

pp::matrix hessian(
    std::function<double(pp::vector)> f,
    pp::vector x
){
    int n = x.size();

    pp::matrix H(n,n);

    pp::vector gx = gradient(f,x);

    for(int j=0; j<n; j++){

        double dx = (1+fabs(x[j]))*pow(2,-13);

        x[j] += dx;

        pp::vector dg = gradient(f,x) - gx;

        for(int i=0; i<n; i++){
            H[i][j] = dg[i]/dx;
        }

        x[j] -= dx;
    }

    return H;
}

struct Result {
    pp::vector xmin;
    int steps;
};

Result newton(
    std::function<double(pp::vector)> f,
    pp::vector x,
    double acc = 1e-3
){
    int steps = 0;

    while(true){

        steps++;

        pp::vector g = gradient(f,x);

        if(g.norm() < acc) break;

        pp::matrix H = hessian(f,x);

        // Levenberg regularization
        for(int i=0; i<H.size1(); i++){
            H[i][i] += 1e-6;
        }

        pp::qr decomp(H);
        pp::vector dx = decomp.solve(-g);

        double lambda = 1.0;

        while(lambda >= 1.0/1024){

            pp::vector z = x + lambda*dx;

            if(f(z) < f(x)) break;

            lambda /= 2.0;
        }

        x += lambda*dx;

        if(steps > 1000){
            std::cerr << "Too many steps\n";
            break;
        }
    }

    std::cout << "Steps = " << steps << "\n";

    return {x, steps};
}