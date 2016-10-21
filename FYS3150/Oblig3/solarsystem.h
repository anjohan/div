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
        SolarSystem(char* filename, vector<Planet> planets_in, double t0_in, double tn_in, int n_in){
            planets = planets_in;
            number_of_planets = planets.size();
            t0 = t0_in;
            tn = tn_in;
            n = n_in;
            dt = (tn-t0)/(n-1);
            printf("dt: %f\n",dt);
            file = fopen(filename,"w");
        }
        ~SolarSystem(){
            fclose(file);
        }
        void solve_euler();
    private:
        vector<Planet> planets;
        int number_of_planets, n;
        double t0, tn, dt;
        FILE* file;
        void reset_accelerations();
        void calculate_accelerations();
        void euler_update_positions_velocities();
        void write_data(double t);
};

#endif
