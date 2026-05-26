#include "minimizers.cc"



double rosenbrock(vector v){

    double x = v[0];
    double y = v[1];

    return pow(1-x,2)
         + 100*pow(y-x*x,2);
}

double himmelblau(vector v){

    double x = v[0];
    double y = v[1];

    return pow(x*x+y-11,2)
         + pow(x+y*y-7,2);
}

