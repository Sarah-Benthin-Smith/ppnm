#include "matrix.h"
#include <iostream>
#include <vector>
#include "vec.h"
#include "qr.h"

int main() {

    pp::vector v1 = {1,2,3};
    pp::vector v2 = {4,5,6};

    pp::vector v3 = v1 + v2;
    v3.print();

    pp::matrix M(3,2);

    M[0][0] = 1;
    M[0][1] = 2;
    M[0][2] = 3;

    M[1][0] = 4;
    M[1][1] = 5;
    M[1][2] = 6;

    M.print();

    pp::qr decomp(M);

    std::cout << "Q:\n";
    decomp.Q.print();

    std::cout << "\nR:\n";
    decomp.R.print();

}