#include "planet.h"

void Planet::euler_update_position(){
    r.x += dt*v.x;
    r.y += dt*v.y;
    r.z += dt*v.z;
}
void Planet::euler_update_velocity(){
    v.x += dt*a.x;
    v.y += dt*a.y;
    v.z += dt*a.z;
}
void Planet::calculate_acceleration(Planet other){
    struct vec dr;
    dr.x = other.r.x - r.x;
    dr.y = other.r.y - r.y;
    dr.z = other.r.z - r.z;
    dr_norm = norm(dr);
    double faktor = other.get_mass_relation_4pi2()/(dr_norm*dr_norm*dr_norm);
    a.x += dr.x*faktor;
    a.y += dr.y*faktor;
    a.z += dr.z*faktor;
    printf("%s, acceleration: %f %f %f\n",name, a.x, a.y, a.z);
}
