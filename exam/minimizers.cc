#include "minimizers.h"
#include "qr.h"
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <limits>

namespace pp {

// FORWARD DIFFERENCE GRADIENT
vector gradient(std::function<double(vector)> phi, vector x){
    vector g(x.size());
    double phix = phi(x);

    for(int i = 0; i < x.size(); i++){
        double dxi = (1.0 + std::abs(x[i])) * std::pow(2.0, -26);

        x[i] += dxi;
        g[i] = (phi(x) - phix) / dxi;
        x[i] -= dxi;
    }

    return g;
}

// CENTRAL DIFFERENCE GRADIENT
vector gradient_central(std::function<double(vector)> phi, vector x){

    vector g(x.size());

    for(int i = 0; i < x.size(); i++){

        double dxi =
            (1.0 + std::abs(x[i]))
            * std::cbrt(std::numeric_limits<double>::epsilon());

        x[i] += dxi;
        double fp = phi(x);

        x[i] -= 2.0*dxi;
        double fm = phi(x);

        x[i] += dxi;

        g[i] = (fp - fm)/(2.0*dxi);
    }

    return g;
}

// FORWARD DIFFERENCE JACOBIAN of residual vector r(c)
matrix jacobian(std::function<vector(vector)> r, vector c){
    vector r0 = r(c);
    int n = r0.size();   // antal residualer (datapunkter)
    int m = c.size();    // antal parametre

    matrix J(n, m);

    for(int j = 0; j < m; j++){
        double dcj = (1.0 + std::abs(c[j])) * std::pow(2.0, -26);

        c[j] += dcj;
        vector r1 = r(c);

        for(int i = 0; i < n; i++)
            J(i,j) = (r1[i] - r0[i]) / dcj;

        c[j] -= dcj;
    }

    return J;
}

// GAUSS-NEWTON MINIMIZER
std::tuple<pp::vector, pp::matrix, int> gauss_newton(
    std::function<pp::vector(pp::vector)> r,
    pp::vector c,
    double acc,
    int max_iter,
    double alpha_min
){
    int m = c.size();

    auto ssq = [&](vector cc){
        vector rr = r(cc);
        double s = 0.0;
        for(int i = 0; i < rr.size(); i++) s += rr[i]*rr[i];
        return s;
    };

    auto covariance = [&](const qr& Q){
        matrix Rinv = Q.inverse();
        matrix Cov(m,m);
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++){
                double sum = 0;
                for(int k = 0; k < m; k++)
                    sum += Rinv(i,k)*Rinv(j,k);
                Cov(i,j) = sum;
            }
        return Cov;
    };

    for(int iter = 0; iter < max_iter; iter++){

        matrix J  = jacobian(r, c);
        vector rc = r(c);

        vector g(m);
        for(int j = 0; j < m; j++){
            double sum = 0;
            for(int i = 0; i < rc.size(); i++)
                sum += J(i,j)*rc[i];
            g[j] = 2.0*sum;
        }

        if(g.norm() < acc){
            qr QRJ(J);
            return {c, covariance(QRJ), iter};
        }

        qr QRJ(J);
        vector dc = QRJ.solve(-rc);

        double f0 = ssq(c);
        double lambda = 1.0;
        vector z = c;

        while(true){
            z = c + lambda*dc;
            double fz = ssq(z);

            if(fz < f0) break;
            if(lambda < alpha_min) break;

            lambda /= 2.0;
        }

        c = z;
    }

    matrix J = jacobian(r, c);
    qr QRJ(J);
    return {c, covariance(QRJ), max_iter};
}

}