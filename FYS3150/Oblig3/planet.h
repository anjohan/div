#ifndef PLANET_H
#define PLANET_H
#include "vec3.h"
#include "vec.h"
#include <cmath>
#include <cstdio>
using namespace std;

class Planet{
    public:
        Planet(char* name_in, double mass_relative_to_sun, double x_in, double y_in, double z_in, double vx_in, double vy_in, double vz_in){
            name = name_in;
            mass_relation_4pi2  = 4 * M_PI * M_PI * mass_relative_to_sun;
            x = x_in;
            y = y_in;
            z = z_in;
            vx = vx_in;
            vy = vy_in;
            vz = vz_in;
            printf("Planet %s created with x=%f, y=%f, z=%f, vx=%f, vy=%f, vz=%f, m/M=%f\n",name, x,y,z,vx,vy,vz,mass_relative_to_sun);
        }
        void reset_acceleration(){
            ax = 0; ay = 0; az = 0;
            ax_old = 0; ay_old = 0; az_old = 0;
        }
        void euler_update_position();
        void euler_update_velocity();
        void verlet_update_position();
        void verlet_update_velocity();
        void calculate_acceleration(Planet other);
        void move_acceleration();
        void set_dt(double dt_in){dt = dt_in;}
        double get_mass_relation_4pi2(){return mass_relation_4pi2;}
        double x, y, z, vx, vy, vz, ax, ay, az, ax_old, ay_old, az_old;
    private:
        char* name;
        double mass_relation_4pi2, dr_norm, dt;
};

#endif
