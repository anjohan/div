#include "vec3.h"
#include <cmath>

vec3::vec3(){
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

vec3::vec3(double x, double y, double z){
    components[0] = x;
    components[1] = y;
    components[2] = z;
}


void vec3::copy(vec3 rhs){
    components[0] = rhs[0];
    components[1] = rhs[1];
    components[2] = rhs[2];
}

void vec3::reset(){
    components[0] = 0;
    components[1] = 0;
    components[2] = 0;
}

void vec3::operator+=(vec3 rhs){
    components[0] += rhs[0];
    components[1] += rhs[1];
    components[2] += rhs[2];
}

vec3 vec3::operator+(vec3 rhs){
    vec3 nyvektor = *this; //Lager kopi
    nyvektor += rhs;
    return nyvektor;
}

vec3 vec3::operator-(vec3 rhs){
    return operator+(rhs * (-1));
}

vec3 vec3::operator*=(double rhs){
    components[0] *= rhs;
    components[1] *= rhs;
    components[2] *= rhs;
}

vec3 vec3::operator*(double rhs){
    vec3 nyvektor = *this; //Lager kopi
    nyvektor *= rhs;
    return nyvektor;
}

double vec3::lengthSquared(){
    return x()*x() + y()*y() + z()*z();
}

double vec3::length(){
    return sqrt(lengthSquared());
}
