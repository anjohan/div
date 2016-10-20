#ifndef VEC3_H
#define VEC3_H

class vec3
    {
    public:
        double components[3];
        vec3();
        vec3(double x, double y, double z);

        double x(){return components[0];}
        double y(){return components[1];}
        double z(){return components[2];}

        double lengthSquared();
        double length();
        double operator()(int indeks){return components[indeks];}
        double operator[](int indeks){return components[indeks];}
        void operator+=(vec3 rhs);
        vec3 operator+(vec3 rhs);
        vec3 operator-(vec3 rhs);
        vec3 operator*(double rhs);
        void copy(vec3 rhs);
        void reset();
    };

#endif
