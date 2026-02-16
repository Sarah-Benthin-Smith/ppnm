#include "vec.h"
#include <iostream>
#include <iomanip>

int main(){
	using namespace vec_funs;
    vec a(1,2,3);
    vec b(4,5,6);

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;

	// Testing addition
	vec c = a + b;
	std::cout << "a+b = " << c << std::endl;

	// Testing subtraction
	vec d = b - a;
	std::cout << "b-a = " << d << std::endl;

	// Testing multiplication
	std::cout << "2*a = " << 2*a << std::endl;
	std::cout << "a*3 = " << a*3 << std::endl;

	// Testing division
	std::cout << "a/2 = " << a/2 << std::endl;

	// Testing negative vector
	std:: cout << "-a = " << -a << std::endl;

	// += operator
    vec e = a;
    e += b;
    std::cout << "e += b -> " << e << std::endl;	

	// approximation
    vec f(1.0000001,2.0000001,3.0000001);
    std::cout << std::setprecision(10);
    std::cout << "f = " << f << std::endl;
    if(approx(a,f)){
        std::cout << "a approx f" << std::endl;
    }

    // print method
    a.print("Vector a: ");

    return 0;
}