#include "qr.h"
#include <cmath>

namespace pp {

qr::qr(const matrix& A) {

    int n = A.rows();
    int m = A.cols_count();

    Q = pp::matrix(n, m);
    R = pp::matrix(m, m);

    matrix V = A;

    for(int i = 0; i < m; i++) {

        double norm = 0.0;
        for(int k = 0; k < n; k++)
            norm += V[i][k] * V[i][k];

        norm = std::sqrt(norm);
        R[i][i] = norm;

        for(int k = 0; k < n; k++)
            Q[i][k] = V[i][k] / norm;

        for(int j = i + 1; j < m; j++) {

            double r = 0.0;
            for(int k = 0; k < n; k++)
                r += Q[i][k] * V[j][k];

            R[i][j] = r;

            for(int k = 0; k < n; k++)
                V[j][k] -= Q[i][k] * r;
        }
    }
}

}