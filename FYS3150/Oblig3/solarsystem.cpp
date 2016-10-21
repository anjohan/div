#include "solarsystem.h"

void SolarSystem::solve_euler(){
    int i;
    double t = t0;
    reset_accelerations();
    calculate_accelerations();
    write_data(t);
    for(i=0; i<n; i++){
        euler_update_positions_velocities();
        calculate_accelerations();
        write_data(t);
        reset_accelerations();
        t += dt;
    }
    finish();
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
        fprintf(file," %f %f %f",planets[i].x,planets[i].y,planets[i].z);
        fprintf(file," %f %f %f",planets[i].vx,planets[i].vy,planets[i].vz);
        fprintf(file," %f %f %f",planets[i].ax,planets[i].ay,planets[i].az);
    }
    fprintf(file,"\n");
}
