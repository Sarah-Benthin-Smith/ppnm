#include <iostream>
#include <random>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

#include "matrix.h"
#include "qr.h"

using namespace std;

// random number generator in the range 0 ≤ x ≤ 1
double rand_double(){ 
    static random_device rd; // Seed
    static mt19937 gen(rd()); // Random engine
    static uniform_real_distribution<> dis(0.0,1.0); // Values between 0 and 1
    return dis(gen);
}

pp::matrix random_matrix(int n,int m){ // Random matrix generator
    pp::matrix A(n,m);
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        A(i,j)=rand_double();
    return A;
}

pp::vector random_vector(int n){ // Random vector generator
    pp::vector v(n);
    for(int i=0;i<n;i++) v[i]=rand_double();
    return v;
}

// main program
int main(){ 

    int n = 5;
    {
        ofstream out("data.dat"); // Timing experiment from data

        for(int N = 10; N <= 500; N += 10){ // Loops over matrix sizes
            pp::matrix A = random_matrix(N,N); // Generate random matrix
            auto start = chrono::high_resolution_clock::now(); // Start timer
            pp::qr decomp(A); // Perform QR decomposition
            auto end = chrono::high_resolution_clock::now(); // Stop timer
            double time = chrono::duration<double>(end - start).count(); // Compute elapsed time
            out << N << " " << time << "\n"; // Save to file
        }

        out.close();
    }

    cout<<"n = "<<n<<"\n"; // Choosing matrix size for experiment

    // 1. QR decomposition test (A=QR)
    pp::matrix A = random_matrix(n,n);
    pp::qr decomp(A);

    cout<<"\n--- Checking Q^T Q = I ---\n"; // Orthogonality of Q (Q^T Q = I)
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            double sum=0;
            for(int k=0;k<n;k++)
                sum+=decomp.Q(k,i)*decomp.Q(k,j); // Dot product between columns i and j, j=i => 1, j≠i => 0

            if(i==j) cout<<sum-1<<" ";
            else cout<<sum<<" ";
        }
        cout<<"\n";
    }

    cout<<"\n--- Checking QR - A ---\n";
    pp::matrix QR = decomp.Q * decomp.R; // Satisfies QR = A

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<QR(i,j)-A(i,j)<<" "; // Print difference
        cout<<"\n";
    }

    // 2. SOLVE TEST
    cout<<"\n--- Solve test ---\n";

    pp::vector b = random_vector(n);
    pp::vector x = decomp.solve(b);
    pp::vector Ax = A*x;

    cout<<"Ax - b:\n";
    for(int i=0;i<n;i++)
        cout<<Ax[i]-b[i]<<" ";
    cout<<"\n";

    // 3. DETERMINANT
    cout<<"\n--- Determinant ---\n";
    cout<<"det(A) = "<<decomp.det()<<"\n";

    // 4. INVERSE TEST
    cout<<"\n--- Inverse test ---\n";

    pp::matrix B = decomp.inverse(); // B=A^-1
    pp::matrix AB = A*B; // AB=I

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<AB(i,j)-1<<" ";
            else cout<<AB(i,j)<<" ";
        }
        cout<<"\n";
    }

    return 0;
}