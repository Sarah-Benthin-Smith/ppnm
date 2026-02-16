#include "vec.h"
#include <string>
#include <iostream>
#include <cmath>


// void vec::print(std::string s) const {
//     std::cout << s << x << " " << y << " " << z << std::endl;
//     }

namespace vec_funs{

vec& vec::operator+=(const vec& other){
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

vec& vec::operator-=(const vec& other){
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

vec& vec::operator*=(double n){
    x *= n;
    y *= n;
    z *= n;
    return *this;
}

vec& vec::operator/=(double n){
    x /= n;
    y /= n;
    z /= n;
    return *this;
}

// non menber

vec operator+(const vec& a, const vec& b){
    vec r = a;
    r += b;
    return r;
}

vec operator-(const vec& a){
    vec r = a;
    r *= -1;
    return r;
}

vec operator-(const vec& a, const vec& b){
    vec r = a;
    r -= b;
    return r;
}

vec operator*(const vec& a, double n){
    vec r = a;
    r *= n;
    return r;
}

vec operator*(double n, const vec& a){
    vec r = a;
    r *= n;
    return r;
}

vec operator/(const vec& a, double n){
    vec r = a;
    r /= n;
    return r;
}

bool approx(double a, double b, double acc, double eps) {
    if(std::fabs(a-b)<acc)return true;
    if(std::fabs(a-b)<eps*(std::fabs(a)+std::fabs(b)))return true;
    return false;
}

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

void vec::print(const std::string& s) const {
    std::cout << s << x << " " << y << " " << z << std::endl;
} 
}