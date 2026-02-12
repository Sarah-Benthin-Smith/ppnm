#include "vec.h"
#include <string>
#include <ostream>
#include <cmath>


// void vec::print(std::string s) const {
//     std::cout << s << x << " " << y << " " << z << std::endl;
//     }

void vec::print(const std::string& s) const {
    std::cout << s << x << " " << y << " " << z << std::endl;
} 

bool approx(double a, double b, double acc, double eps) {
    return std::abs(a - b) <= acc + eps * std::abs(a + b);
}

// bool approx(const vec& a, const vec& b){
// 	if(!approx(a.x,b.x))return false;
// 	if(!approx(a.y,b.y))return false;
// 	if(!approx(a.z,b.z))return false;
// 	return true;
// 	}

bool approx(const vec& a, const vec& b, double acc, double eps){
    if(!approx(a.x, b.x, acc, eps)) return false;
    if(!approx(a.y, b.y, acc, eps)) return false;
    if(!approx(a.z, b.z, acc, eps)) return false;
    return true;
}

std::ostream& operator<<(std::ostream& os, const vec& v){
    os << "{ " << v.x << ", " << v.y << ", " << v.z << " } ";
    return os;
    }