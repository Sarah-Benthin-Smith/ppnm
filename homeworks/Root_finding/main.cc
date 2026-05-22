#include <iostream>
#include <cmath>
#include <fstream>

#include "matrix.h"
#include "newton.h"

// using namespace std;

pp::vector f1(pp::vector x){

    pp::vector y(1);

    y[0] = x[0]*x[0] - 2;

    return y;
}

pp::vector rosenbrock_grad(pp::vector x){

    double X = x[0];
    double Y = x[1];

    pp::vector g(2);

    g[0] =
        -2*(1-X)
        -400*X*(Y - X*X);

    g[1] =
        200*(Y - X*X);

    return g;
}

pp::vector himmel_grad(pp::vector x){

    double X = x[0];
    double Y = x[1];

    pp::vector g(2);

    g[0] =
        4*X*(X*X + Y - 11)
        + 2*(X + Y*Y - 7);

    g[1] =
        2*(X*X + Y - 11)
        + 4*Y*(X + Y*Y - 7);

    return g;
}

int main(){

    std::ofstream pout("roots.txt");

    //  sqrt(2) 

    pp::vector x1(1);

    x1[0] = 1;

    pp::vector r1 = newton(f1,x1);

    std::cout << "sqrt(2) test:\n";
    std::cout << r1[0] << "\n\n";

    pout << "sqrt(2) test:\n";
    pout << r1[0] << "\n\n";


    //  Rosenbrock 

    pp::vector xr(2);

    xr[0] = -1;
    xr[1] = 2;


    pp::vector rr = newton(rosenbrock_grad,xr);

    std::cout << "Rosenbrock minimum:\n";
    std::cout << rr[0] << " "
         << rr[1] << "\n\n";

    pout << "Rosenbrock minimum:\n";
    pout << rr[0] << " "
         << rr[1] << "\n\n";

    //  Himmelblau 

    pp::vector xh(2);

    xh[0] = 3;
    xh[1] = 1;

    pp::vector rh = newton(himmel_grad,xh);

    std::cout << "Himmelblau minimum:\n";
    std::cout << rh[0] << " "
         << rh[1] << "\n\n";

    pout << "Himmelblau minimum:\n";
    pout << rh[0] << " "
         << rh[1] << "\n\n";

    return 0;
}