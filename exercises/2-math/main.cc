#include<iostream>
#include<cmath>
#include<cstdio>
#include<numbers>
#include"hello.h"
#include"sfuns.h"

int main(){
	hello();
	constexpr double PI = std::numbers::pi;
	constexpr double EXP = std::numbers::e;
	double sqrt2=std::sqrt(2.0);
	std::cout << "sqrt(2) = " << sqrt2 << std::endl;
	double power2=std::pow(2.0, 0.2);
	std::cout << "2^1/5 = " << power2 << std::endl;
	double powerepi=std::pow(EXP, PI);
	std::cout << "e^pi = " << powerepi << std::endl;
	double powerpie=std::pow(PI, EXP);
	std::cout << "pi^e = " << powerpie << std::endl;
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