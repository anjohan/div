#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include "planet.h"
#include <vector>
#include "vec3.h"
#include <string>
#include <cstdio>
using namespace std;

class SolarSystem{
    public:
        SolarSystem(char* filename, vector<Planet> planets_in, double t0_in, double tn_in, int n_in, int dn_in){
            planets = planets_in;
            number_of_planets = planets.size();
            t0 = t0_in;
            tn = tn_in;
            n = n_in;
            dn = dn_in;
            dt = (tn-t0)/(n-1);
            int i;
            for(i=0; i<number_of_planets; i++){
                planets[i].set_dt(dt);
            }
            printf("dt: %f\n",dt);
            file = fopen(filename,"w");
        }
        void finish(){fclose(file);}
        void solve_euler();
        void solve_verlet();
    private:
        vector<Planet> planets;
        int number_of_planets, n, dn;
        double t0, tn, dt;
        FILE* file;
        void reset_accelerations();
        void calculate_accelerations();
        void move_accelerations();
        void euler_update_positions_velocities();
        void verlet_update_positions();
        void verlet_update_velocities();
        void write_data(double t);
};

#endif
