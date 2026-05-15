#include <iostream>
#include <cmath>
#include <fstream>
#include "lsfit.h"

int main(){

    pp::vector t(9);
    pp::vector y(9);
    pp::vector dy(9);

    t[0]=1;   y[0]=117;   dy[0]=6;
    t[1]=2;   y[1]=100;   dy[1]=5;
    t[2]=3;   y[2]=88;    dy[2]=4;
    t[3]=4;   y[3]=72;    dy[3]=4;
    t[4]=6;   y[4]=53;    dy[4]=4;
    t[5]=9;   y[5]=29.5;  dy[5]=3;
    t[6]=10;  y[6]=25.2;  dy[6]=3;
    t[7]=13;  y[7]=15.2;  dy[7]=2;
    t[8]=15;  y[8]=11.1;  dy[8]=2;

    pp::vector Y(9);
    pp::vector dY(9);

    for(int i=0;i<9;i++){
        Y[i]  = log(y[i]);
        dY[i] = dy[i]/y[i];
    }

    auto fs = std::vector<std::function<double(double)>>{
        [](double){ return 1.0; },
        [](double x){ return x; }
    };

    // pp::vector c = lsfit(fs,t,Y,dY);
    auto [c,Cov] = lsfit(fs,t,Y,dY);


    double ln_a   = c[0];
    double lambda = -c[1];

    double d_ln_a   = std::sqrt(Cov(0,0));
    double d_lambda = std::sqrt(Cov(1,1));

    double a = exp(ln_a);

    double T12  = log(2.0)/lambda;

    double dT12 =
        log(2.0)/(lambda*lambda)*d_lambda;

    std::cout << "a = " << a << "\n";
    std::cout << "lambda = " << lambda << "+/-" << d_lambda << "\n";
    std::cout << "Half-life = " << T12 << "+/-" << dT12 << " days\n";
    std::cout << "Modern Value = 3.6316 days\n";
    std::cout << "No it does not agree with the modern value\n";

    std::ofstream datafile("data.txt");

    for(int i=0;i<9;i++){
        datafile
            << t[i]  << " "
            << y[i]  << " "
            << dy[i] << "\n";
    }

    std::ofstream fitfile("fit.txt");

    for(double z=0; z<=16; z+=0.1){

        double fit = a*std::exp(-lambda*z);

        fitfile
            << z << " "
            << fit << "\n";
    }

    std::ofstream f("fit_band.txt");

    for(double t=0; t<=16; t+=0.1){

        auto F = [&](double LN_A, double Lambda){
            return std::exp(LN_A + Lambda*t);
        };

        double f0 = F(ln_a, lambda);

        double fpp = F(ln_a+d_ln_a, lambda+d_lambda);
        double fpm = F(ln_a+d_ln_a, lambda-d_lambda);
        double fmp = F(ln_a-d_ln_a, lambda+d_lambda);
        double fmm = F(ln_a-d_ln_a, lambda-d_lambda);

        f << t << " "
        << f0  << " "
        << fpp << " "
        << fpm << " "
        << fmp << " "
        << fmm << "\n";
    }

}