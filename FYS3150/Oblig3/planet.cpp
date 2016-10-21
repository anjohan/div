#include "planet.h"

void Planet::euler_update_position(){
    x += dt*vx;
    y += dt*vy;
    z += dt*vz;
    /*
    printf("%s, v: %f %f %f\n",name, vx, vy, vz);
    printf("%s, dt: %f\n",name, dt);
    printf("%s, v*dt: %f %f %f\n",name, dt*vx, dt*vy, dt*vz);
    */
}
void Planet::euler_update_velocity(){
    vx += dt*ax;
    vy += dt*ay;
    vz += dt*az;
    /*
    printf("%s, a: %f %f %f\n",name, ax, ay, az);
    printf("%s, dt: %f\n",name, dt);
    printf("%s, a*dt: %f %f %f\n",name, dt*ax, dt*ay, dt*az);
    */
}
void Planet::calculate_acceleration(Planet other){
    double dx, dy, dz;
    dx = other.x - x;
    dy = other.y - y;
    dz = other.z - z;
    double dr_norm = sqrt(dx*dx + dy*dy + dz*dz);
    double faktor = other.get_mass_relation_4pi2()/(dr_norm*dr_norm*dr_norm);
    ax += dx*faktor;
    ay += dy*faktor;
    az += dz*faktor;
}
