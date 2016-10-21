#include "solarsystem.h"

void SolarSystem::solve_euler(){
    int i;
    double t = t0;
    write_data(t);
    calculate_accelerations();
    for(i=0; i<n; i++){
        euler_update_positions_velocities();
        reset_accelerations();
        calculate_accelerations();
        t += dt;
        write_data(t);
    }
}

void SolarSystem::reset_accelerations(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i].reset_acceleration();
    }
}

void SolarSystem::calculate_accelerations(){
    int i, j;
    for(i=0; i<number_of_planets-1; i++){
        for(j=i+1; j<number_of_planets; j++){
            planets[i].calculate_acceleration(planets[j]);
            planets[j].calculate_acceleration(planets[i]);
        }
    }
}

void SolarSystem::euler_update_positions_velocities(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i].euler_update_position();
        planets[i].euler_update_velocity();
    }
}

void SolarSystem::write_data(double t){
    fprintf(file,"%f",t);
    int i;
    for(i=0; i<number_of_planets; i++){
        vec3 r = planets[i].position();
        fprintf(file," %f %f %f",r[0],r[1],r[2]);
    }
    fprintf(file,"\n");
}
