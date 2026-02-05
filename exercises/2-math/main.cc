#include<iostream>
#include<cmath>
#include<complex>
#include<cstdio>
#include<numbers>
#include"hello.h"
#include"sfuns.h"
using complex=std::complex<double>;

constexpr double PI = std::numbers::pi;
constexpr double EXP = std::numbers::e;
constexpr complex I = complex(0,1);

int main(){
	hello();
	std::cout << "sqrt(2) = " << std::sqrt(2.0) << std::endl;
	std::cout << "2^1/5 = " << std::pow(2.0, 0.2) << std::endl;
	std::cout << "e^pi = " << std::pow(EXP, PI) << std::endl;
	std::cout << "pi^i = " << std::pow(PI, I) << std::endl;
	std::cout << "pi^e = " << std::pow(PI, EXP) << std::endl;
	std::cout << "pi^i = " << std::pow(PI, I) << std::endl;
	std::cout << "e^i = " << std::pow(EXP, I) << std::endl;
	std::cout << "i^i = " << std::pow(I, I) << std::endl;
	std::cout << "log(i) = " << std::log(I) << std::endl;
	
	// double x=1;
	// double y = sfuns::fgamma(x);
	// std::cout << "fgamma(1)=" << y << "\n";
	// std::printf("fgamma(1)=%g\n",y);
	for(double x=1;x<=10;x+=1){
		std::cout << "fgamma(" << x << ")=" << sfuns::fgamma(x) << "\n";
			// << "\t tgamma(" << x << ")=" << std::tgamma(x) << "\n";
	}
	return 0;
}