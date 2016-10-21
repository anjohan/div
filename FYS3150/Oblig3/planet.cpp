#include "planet.h"

void Planet::euler_update_position(){
    r += v*dt;
    printf("%s d_position: ",name); (v*dt).print();
}
void Planet::euler_update_velocity(){
    v += a*dt;
    printf("%s d_velocity: ",name); (a*dt).print();
}
void Planet::calculate_acceleration(Planet other){
    dr = other.position() - r;
    dr_norm = dr.length();
    a += dr * (mass_relation_4pi2/(dr_norm*dr_norm*dr_norm));
}
