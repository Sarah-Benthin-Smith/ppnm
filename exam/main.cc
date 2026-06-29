#include <iostream>
#include <cmath>
#include <fstream>
#include "lsfit.h"
#include "minimizers.h"

int main(){

    std::ofstream pout("README.txt");

    pout << "The Gauss-Newton algorithm" << "\n";
    pout << "\nThe method is used to solve non-linear least squares problems. It is an extension to Newtons method for finding the minima of a non-linear function." << "\n";
    pout << "I will be using alterations of code created in homeworks OLS and Minimization." << "\n";
    pout << "This includes the minimizers.cc and minimizers.h in Minimization, where the Hessian algorithm has been removed and the Gauss-Newton has been added instead." << "\n";
    pout << "It also includes the qr decomposition used in various handins, here no alterations has been made - it is the same for the matrix class and the lsfit." << "\n";
    // pout << "" << "\n";
    // pout << "" << "\n";

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

    auto [c,Cov] = lsfit(fs,t,Y,dY);

    double c0 = c[0];
    double c1 = -c[1];

    double dc0 = std::sqrt(Cov(0,0));
    double dc1 = std::sqrt(Cov(1,1));

    double a = exp(c0);
    double da = a*dc0;
    double T12  = log(2.0)/c1;
    double dT12 = log(2.0)/(c1*c1)*dc1;

    pout << "\nLog-linear fit (OLS):" << "\n";
    pout << "a = " << a << " +/- " << da << "\n";
    pout << "lambda = " << c1 << "+/-" << dc1 << "\n";
    pout << "Half-life = " << T12 << "+/-" << dT12 << " days\n";

    auto r_gn = [&](pp::vector c_gn) {
    pp::vector res_gn(9);
    for (int i = 0; i < 9; i++)
        res_gn[i] = (c_gn[0]*std::exp(-c_gn[1]*t[i]) - y[i]) / dy[i];
    return res_gn;
    };

    pp::vector c0_gn(2);
    c0_gn[0] = 100.0;   // gæt på a
    c0_gn[1] = 0.2;     // gæt på lambda

    auto [c_gn, Cov_gn, iters_gn] = pp::gauss_newton(r_gn, c0_gn);

    double a_gn      = c_gn[0];
    double lambda_gn = c_gn[1];
    double T12_gn    = std::log(2.0)/lambda_gn;

    double da_gn      = std::sqrt(Cov_gn(0,0));
    double dlambda_gn = std::sqrt(Cov_gn(1,1));
    double dT12_gn    = std::log(2.0)/(lambda_gn*lambda_gn)*dlambda_gn;

    pout << "\nDirect nonlinear fit (Gauss-Newton, " << iters_gn << " iterations):" << "\n";
    pout << "a = " << a_gn << " +/- " << da_gn << "\n";
    pout << "lambda = " << lambda_gn << " +/- " << dlambda_gn << "\n";
    pout << "Half-life = " << T12_gn << " +/- " << dT12_gn << " days\n";
    pout << "\nModern Value = 3.6316 days\n";
    double sigma_diff = std::abs(T12_gn - 3.6316) / dT12_gn;
    pout << "Difference from modern value: " << sigma_diff << " sigma\n";

    std::ofstream datafile("data.txt");

    for(int i=0;i<9;i++){
        datafile
            << t[i]  << " "
            << y[i]  << " "
            << dy[i] << "\n";
    }

    std::ofstream fitout("fit.dat");
    fitout << "# t  y_ols  y_gn\n";
    for(double tt=0; tt<=15; tt+=0.1){
        double y_ols = a    * exp(-c1       * tt);
        double y_gn  = a_gn * exp(-lambda_gn * tt);
        fitout << tt << " " << y_ols << " " << y_gn << "\n";
    }
    fitout.close();

    return 0;

}


    
    // std::ofstream fitout("fit.dat");

    // for(double tt=0; tt<=15; tt+=0.1){

    //     // best fit
    //     double yfit = a * exp(-c1 * tt);

    //     // combinations
    //     double a_pp = exp(c0 + dc0);
    //     double a_pm = exp(c0 + dc0);
    //     double a_mp = exp(c0 - dc0);
    //     double a_mm = exp(c0 - dc0);

    //     double lambda_pp = (c1 + dc1);
    //     double lambda_pm = (c1 - dc1);
    //     double lambda_mp = (c1 + dc1);
    //     double lambda_mm = (c1 - dc1);

    //     double y_pp = a_pp * exp(-lambda_pp * tt);
    //     double y_pm = a_pm * exp(-lambda_pm * tt);
    //     double y_mp = a_mp * exp(-lambda_mp * tt);
    //     double y_mm = a_mm * exp(-lambda_mm * tt);

    //     // envelope (min/max)
    //     double y_max = std::max({y_pp, y_pm, y_mp, y_mm});
    //     double y_min = std::min({y_pp, y_pm, y_mp, y_mm});

    //     fitout << tt << " " << yfit << " " << y_min << " " << y_max << "\n";
    // }

    // fitout.close();