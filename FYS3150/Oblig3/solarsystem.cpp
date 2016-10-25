#include "solarsystem.h"


SolarSystem::SolarSystem(char* filename, vector<Planet*> planets_in, double t0_in, double tn_in, int n_in, int dn_in){
    planets = planets_in;
    number_of_planets = planets.size();
    t0 = t0_in;
    tn = tn_in;
    n = n_in;
    dn = dn_in;
    dt = (tn-t0)/(n-1);
    file = fopen(filename,"w");
    int i;
    fprintf(file,"#");
    for(i=0; i<number_of_planets; i++){
        fprintf(file," %f",planets[i]->mass_ratio);
        planets[i]->set_dt(dt);
    }
    fprintf(file,"\n");
}

void SolarSystem::solve_euler(){
    int i;
    double t = t0;
    reset_accelerations();
    clock_t start, end;
    start = clock();
    calculate_accelerations();
    write_data(t);
    for(i=0; i<n; i++){
        euler_update_positions_velocities();
        reset_accelerations();
        calculate_accelerations();
        if(i % dn == 0){
            write_data(t);
        }
        t += dt;
    }
    write_data(t);
    end = clock();
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    fprintf(file,"# %f",time);
    finish();
}

void SolarSystem::solve_verlet(){
    int i;
    double t = t0;
    reset_accelerations();
    clock_t start, end;
    start = clock();
    calculate_accelerations();
    write_data(t);
    for(i=0; i<=n; i++){
        verlet_update_positions();
        move_accelerations();
        calculate_accelerations();
        verlet_update_velocities();
        if(i % dn == 0){
            write_data(t);
        }
        t += dt;
    }
    write_data(t);
    end = clock();
    double time = ((double) (end - start))/CLOCKS_PER_SEC;
    fprintf(file,"# %f",time);
    finish();
}

void SolarSystem::reset_accelerations(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i]->reset_acceleration();
    }
}

void SolarSystem::move_accelerations(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i]->move_acceleration();
    }
}

void SolarSystem::verlet_update_positions(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i]->verlet_update_position();
    }
}

void SolarSystem::verlet_update_velocities(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i]->verlet_update_velocity();
    }
}

void SolarSystem::calculate_accelerations(){
    int i, j;
    for(i=0; i<number_of_planets-1; i++){
        for(j=i+1; j<number_of_planets; j++){
            planets[i]->calculate_acceleration(planets[j]);
            planets[j]->calculate_acceleration(planets[i]);
        }
    }
}

void SolarSystem::euler_update_positions_velocities(){
    int i;
    for(i=0; i<number_of_planets; i++){
        planets[i]->euler_update_position();
        planets[i]->euler_update_velocity();
    }
}

void SolarSystem::write_data(double t){
    fprintf(file,"%f",t);
    int i;
    for(i=0; i<number_of_planets; i++){
        fprintf(file," %f %f %f",planets[i]->x,planets[i]->y,planets[i]->z);
        fprintf(file," %f %f %f",planets[i]->vx,planets[i]->vy,planets[i]->vz);
        //fprintf(file," %f %f %f",planets[i]->ax,planets[i]->ay,planets[i]->az);
    }
    fprintf(file,"\n");
}
