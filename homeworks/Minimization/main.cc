#include <iostream>
#include <cmath>
#include <fstream>

#include "matrix.h"
#include "minimizers.cc"

double rosenbrock(pp::vector v){

    double x = v[0];
    double y = v[1];

    return pow(1-x,2)
         + 100*pow(y-x*x,2);
}

double himmelblau(pp::vector v){

    double x = v[0];
    double y = v[1];

    return pow(x*x+y-11,2)
         + pow(x+y*y-7,2);
}

// Assignment B

double higgs_cost(pp::vector p,
                  const std::vector<double>& E,
                  const std::vector<double>& sigma,
                  const std::vector<double>& err)
{
    double m = p[0];
    double G = p[1];
    double A = p[2];

    double sum = 0.0;

    for(size_t i = 0; i < E.size(); i++){
        double denom = (E[i] - m)*(E[i] - m) + (G*G)/4.0;
        double model = A / denom;

        double r = (model - sigma[i]) / err[i];
        sum += r*r;
    }

    return sum;
}

int main(){

    std::ofstream pout("minimas.txt");

    // Rosenbrock funktion

    pp::vector start(2);

    start[0] = -2;
    start[1] = 5;

    pout << "=== Rosenbrock function ===\n";

    auto resR = newton(rosenbrock, start);

    pout << "Steps   = " << resR.steps << "\n";

    pout << "Minimum = (";
    for(int i = 0; i < resR.xmin.size(); i++){
        pout << resR.xmin[i];
        if(i < resR.xmin.size() - 1) pout << ", ";
    }
    pout << ")\n\n";

    // Himmelblau funktion

    pp::vector starth(2);

    starth[0] = 4;
    starth[1] = 4;

    pout << "=== Himmelblau function ===\n";

    auto resH = newton(himmelblau, starth);

    pout << "Steps   = " << resH.steps << "\n";

    pout << "Minimum = (";
    for(int i = 0; i < resH.xmin.size(); i++){
        pout << resH.xmin[i];
        if(i < resH.xmin.size() - 1) pout << ", ";
    }
    pout << ")\n";

}