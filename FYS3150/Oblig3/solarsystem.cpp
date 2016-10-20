#include "solarsystem.h"

void SolarSystem::solve_euler(){
    int i, j, k;
    double t = t0;
    calculate_accelerations();
    for(i=0; i<=n; i++){
        euler_update_positions_velocities();
        calculate_accelerations();
        t += dt;
    }
}

void SolarSystem::calculate_accelerations(){
    int i, j;
    for(i=0; i<number_of_planets-1; i++){
        planets[i].reset_acceleration();
        for(j=i; j<number_of_planets; i++){
            planets[i].calculate_acceleration(planets[j]);
            planets[j].calculate_acceleration(planets[i]);
        }
    }
}

void SolarSystem::euler_update_positions_velocities(){
    int i;
    for(i=1; i<number_of_planets; i++){
        planets[i].euler_update_position();
        planets[i].euler_update_velocity();
    }
}
