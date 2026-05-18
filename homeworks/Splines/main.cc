#include <cstdio>
#include <cmath>
#include "vec.h"

// Deklarationer fra Ispline.cc
double linterp(const vector& x, const vector& y, double z);
double linterpInteg(const vector& x, const vector& y, double z);

int main() {
    // Opret tabel: x = 0, 0.5, 1, ..., 9 og y = cos(x)
    int n = 19;  // 0 til 9 med step 0.5
    vector x(n), y(n);
    
    for (int i = 0; i < n; i++) {
        x[i] = i * 0.5;
        y[i] = cos(x[i]);
    }
    
    // Generer data til plots
    FILE* interp_file = fopen("interp.data", "w");
    FILE* integ_file = fopen("integ.data", "w");
    
    int npoints = 200;
    for (int i = 0; i < npoints; i++) {
        double z = x[0] + (x[n-1] - x[0]) * i / (npoints - 1);
        
        double y_interp = linterp(x, y, z);
        double y_exact = cos(z);
        
        double integ_interp = linterpInteg(x, y, z);
        double integ_exact = sin(z) - sin(x[0]);  // ∫cos(t)dt = sin(t)
        
        fprintf(interp_file, "%g %g %g\n", z, y_interp, y_exact);
        fprintf(integ_file, "%g %g %g\n", z, integ_interp, integ_exact);
    }
    
    fclose(interp_file);
    fclose(integ_file);
    
    // Udskriv også tabelpunkterne
    FILE* points_file = fopen("points.data", "w");
    for (int i = 0; i < n; i++) {
        fprintf(points_file, "%g %g\n", x[i], y[i]);
    }
    fclose(points_file);
    
    printf("Data gemt i interp.data, integ.data og points.data\n");
    
    return 0;
}
