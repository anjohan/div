#ifndef PLANET_H
#define PLANET_H
#include "vec3.h"
#include "vec.h"
#include <cmath>
#include <cstdio>
using namespace std;

class Planet{
    public:
        Planet(char* name_in, double mass_relative_to_sun, vec r0, vec v0){
            name = name_in;
            mass_relation_4pi2  = 4 * M_PI * M_PI * mass_relative_to_sun;
            r = r0; v = v0;
        }
        void reset_acceleration(){
            a.x = 0; a.y = 0; a.z = 0;
        }
        vec position(){return r;}
        vec velocity(){return v;}
        void euler_update_position();
        void euler_update_velocity();
        void calculate_acceleration(Planet other);
        void set_dt(double dt_in){dt = dt_in;}
        double get_mass_relation_4pi2(){return mass_relation_4pi2;}
        struct vec r, v, a;
    private:
        char* name;
        double mass_relation_4pi2, dr_norm, dt;
};

#endif
