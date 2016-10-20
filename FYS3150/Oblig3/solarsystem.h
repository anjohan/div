#ifndef SOLARSYSTEM_H
#define SOLARSYSTEM_H
#include "planet.h"
#include <vector>
#include "vec3.h"
#include <string>
using namespace std;

class SolarSystem{
    public:
        SolarSystem(vector<Planet> planets_in, double t0_in, double tn_in, int n_in){
            Planet sun(string("Sun"),1, vec3(), vec3());
            planets.push_back(sun);
            number_of_planets = planets_in.size();
            t0 = t0_in;
            tn = tn_in;
            n = n_in;
            dt = (tn-t0)/n;
            int i;
            for(i=0; i<number_of_planets; i++){
                planets_in[i].set_dt(dt);
                planets.push_back(planets_in[i]);
            }
            number_of_planets++;
        }
        void solve_euler();
        void calculate_accelerations();
        void euler_update_positions_velocities();
    private:
        vector<Planet> planets;
        int number_of_planets, n;
        double t0, tn, dt;
};

#endif
