#include "solarsystem.h"

void SolarSystem::solve_euler(){
    int i;
    double t = t0;
    for(i=0; i<n; i++){
        write_data(t);
        calculate_accelerations();
        euler_update_positions_velocities();
        reset_accelerations();
        t += dt;
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
        vec r = planets[i].r;
        vec v = planets[i].v;
        vec a = planets[i].a;
        fprintf(file," %f %f %f",r.x,r.y,r.z);
        fprintf(file," %f %f %f",v.x,v.y,v.z);
        fprintf(file," %f %f %f",a.x,a.y,a.z);
    }
    fprintf(file,"\n");
}
