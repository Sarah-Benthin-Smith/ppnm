#include <iostream>
#include <cmath>
#include <functional>
#include <vector>
#include <fstream>
#include <string>

#include "ROQAI.h"

using namespace std;

int ncalls = 0;

double call_counter(function<double(double)> f, double x){
    ncalls++;
    return f(x);
}

double erf_integral(
    std::function<double(function<double(double)>,double,double,double,double,double,double)> integrate,
    double z)
{
    const double inv_sqrt_pi = 2.0 / std::sqrt(M_PI);

    auto I = [&](auto f, double a, double b){
        return integrate(f, a, b, 1e-6, 1e-6, NAN, NAN);
    };

    if (z < 0)
        return -erf_integral(integrate, -z);

    if (z <= 1.0){
        auto f = [](double x){ return std::exp(-x*x); };
        return inv_sqrt_pi * I(f, 0.0, z);
    }

    auto f = [z](double t){
        double u = z + (1.0 - t)/t;
        return std::exp(-u*u) / (t*t);
    };

    return 1.0 - inv_sqrt_pi * I(f, 0.0, 1.0);
}



// double erf_integral(function<double(double)> integrate, double z);

int main(){

    struct Test {
        function<double(double)> f;
        double a,b;
        double exact;
        string name;
    };

    vector<Test> tests = {

        {
            [](double x){ return sqrt(x); },
            0,1,
            2.0/3.0,
            "∫₀¹ sqrt(x) dx"
        },

        {
            [](double x){ return 1.0/sqrt(x); },
            0,1,
            2.0,
            "∫₀¹ 1/sqrt(x) dx"
        },

        {
            [](double x){ return sqrt(1-x*x); },
            0,1,
            M_PI/4.0,
            "∫₀¹ sqrt(1-x²) dx"
        },

        {
            [](double x){ return log(x)/sqrt(x); },
            0,1,
            -4.0,
            "∫₀¹ ln(x)/sqrt(x) dx"
        }
    };

    ofstream txt_file("initial_integral_solutions.txt");

    for(const auto& test : tests){

        ncalls = 0;

        auto counted_f = [test](double x){
            return call_counter(test.f,x);
        };

        double result = integrate(counted_f,test.a,test.b);

        double error = fabs(result - test.exact);

        txt_file << "-----------------------------------\n";
        txt_file << test.name << "\n";
        txt_file << "Result        = " << result << "\n";
        txt_file << "Exact         = " << test.exact << "\n";
        txt_file << "Actual error  = " << error << "\n";
        txt_file << "Function calls= " << ncalls << "\n";
    }
    txt_file.close();

    ofstream file("erf_data.dat");

    for(double z = -3.0; z <= 3.0; z += 0.05){

        auto integ = [](function<double(double)> f, double a, double b,
                         double acc, double eps,
                         double f2, double f3){
            return integrate(f,a,b,acc,eps,f2,f3);
        };

        double val = erf_integral(integ, z);
        double ref = erf(z); // C++ standard reference

        file << z << " " << val << " " << ref << "\n";
    }

    file.close();

    return 0;
}