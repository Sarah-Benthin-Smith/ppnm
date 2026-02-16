#include "vec.h"
#include <iostream>
#include <iomanip>
#include <complex>

int main(){
	using namespace vec_funs;
    vec<double> a(1.123456789, 2.123456789, 3.123456789);
    vec<float>  b(1.123456789f, 2.123456789f, 3.123456789f);

    std::cout << "1. double and float vecs" << std::endl;
    std::cout << "double vec = " << a << std::endl;
    std::cout << "float vec = " << b << std::endl;

    std::cout << "2. Mixing scalar types" << std::endl;
	std::cout << "2*a = " << 2*a << "(integer*double)" << std::endl;

    std::cout << "3. Adding complex numbers" << std::endl;	
    using cd = std::complex<double>;
    vec<cd> c(cd(1,1), cd(2,0), cd(0,3));
    std::cout << "complex vec: " << c << std::endl;

    std::cout << "4. Any type" << std::endl;	
    vec<double> d(1.123456788, 2.123456788, 3.123456788);
    std::cout << "a = " << a << std::endl;
    std::cout << "d = " << d << std::endl;

    if(approx(a,d)){
        std::cout << "approx works for vec<double>'s" << std::endl;
    }

    // print method
    // a.print("Vector a: ");

    return 0;
}