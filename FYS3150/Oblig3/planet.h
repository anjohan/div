#ifndef PLANET_H
#define PLANET_H
#include "vec3.h"
#include <cmath>
#include <string>
using namespace std;

class Planet{
    public:
        Planet(string name_in, double mass_relative_to_sun, vec3 r0, vec3 v0){
            v.copy(v0);
            r.copy(r0);
            name = name_in;
            mass_relation_4pi2  = 4 * M_PI * M_PI * mass_relative_to_sun;
        }
        void reset_acceleration(){
            a.reset();
        }
        vec3 position(){return r;}
        void euler_update_position();
        void euler_update_velocity();
        void calculate_acceleration(Planet other);
        double set_dt(double dt_in){dt = dt_in;}
    private:
        vec3 a, v, r, a_next, a_tmp, dr;
        string name;
        double mass_relation_4pi2, dr_norm, dt;
};

#endif
