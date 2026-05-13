#include "lsfit.h"

pp::vector lsfit(
    const std::vector<func>& fs,
    const pp::vector& x,
    const pp::vector& y,
    const pp::vector& dy
){
    int n = x.size();
    int m = fs.size();

    pp::matrix A(n,m);

    pp::vector b(n);

    for(int i=0;i<n;i++){

        b[i] = y[i]/dy[i];

        for(int k=0;k<m;k++){
            A(i,k)=fs[k](x[i])/dy[i];
        }
    }

    pp::qr qr(A);

    pp::vector c = qr.solve(b);

    return c;
}