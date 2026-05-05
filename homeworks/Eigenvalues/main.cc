#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

#include "matrix.h"
#include "EVD.h"

using namespace pp;



// Matrix comparison
bool approx_equal(const pp::matrix& A, const pp::matrix& B, double tol = 1e-8) {
    for (int i = 0; i < A.size1(); i++) {
        for (int j = 0; j < A.size2(); j++) {
            if (std::abs(A(i,j) - B(i,j)) > tol) return false;
        }
    }
    return true;
}    

// Transpose function

pp::matrix transpose(const pp::matrix& M) {
    pp::matrix T(M.size2(), M.size1());
    for (int i = 0; i < M.size1(); i++)
        for (int j = 0; j < M.size2(); j++)
            T(j,i) = M(i,j);
    return T;
}

pp::matrix identity_matrix(int n) {
    pp::matrix I(n, n);  // adjust if your constructor differs

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            I(i,j) = (i == j) ? 1.0 : 0.0;
        }
    }

    return I;
}

// main program
int main(){ 
    using namespace std;
    using namespace pp;

    // 1. Create a symmetric test matrix
    matrix A(3,3);

    A(0,0)=4;  A(0,1)=1;  A(0,2)=1;
    A(1,0)=1;  A(1,1)=3;  A(1,2)=0;
    A(2,0)=1;  A(2,1)=0;  A(2,2)=2;

    cout << "Input matrix A:\n";
    A.print(); // assuming you have this

    // 2. Run Jacobi diagonalization
    auto [w, V] = jacobi(A);

    // 3. Print eigenvalues
    cout << "\nEigenvalues:\n";
    for(int i=0;i<w.size();i++){
        cout << w[i] << " ";
    }
    cout << endl;

    // 4. Print eigenvectors
    cout << "\nEigenvector matrix V:\n";
    V.print();

    // check of  VTAV==D, VDVT==A, VTV==1, VVT==1
    
    pp::matrix D(V.size1(), V.size2());

    for (int i = 0; i < w.size(); i++) {
        D(i,i) = w[i];
    }

    // Calculate

    std::cout << "Check of EVD, 1 means true" << "\n";

    auto VT = transpose(V);
    auto left = VT * A * V;

    std::cout << "VTAV == D: " << approx_equal(left, D) << "\n";

    auto right = V * D * VT;

    std::cout << "VDVT == A: " << approx_equal(right, A) << "\n";

    auto I1 = VT * V;
    pp::matrix I = identity_matrix(V.size1()); // you need this

    std::cout << "VTV == I: " << approx_equal(I1, I) << "\n";

    auto I2 = V * VT;

    std::cout << "VVT == I: " << approx_equal(I2, I) << "\n";

    return 0;
}