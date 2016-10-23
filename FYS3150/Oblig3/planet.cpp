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

void Planet::calculate_acceleration(Planet* other){
    double dx, dy, dz;
    dx = other->x - x;
    dy = other->y - y;
    dz = other->z - z;
    double dr_norm = sqrt(dx*dx + dy*dy + dz*dz);
    double factor = other->mass_ratio_4pi2/(dr_norm*dr_norm*dr_norm);
    ax += dx*factor;
    ay += dy*factor;
    az += dz*factor;
}

void Planet::verlet_update_position(){
    x += dt*vx + halfdt2*ax;
    y += dt*vy + halfdt2*ay;
    z += dt*vz + halfdt2*az;
}

void Planet::verlet_update_velocity(){
    vx += halfdt*(ax+ax_old);
    vy += halfdt*(ay+ay_old);
    vz += halfdt*(az+az_old);
}

void Planet::move_acceleration(){
    ax_old = ax;
    ay_old = ay;
    az_old = az;
    ax = 0; ay = 0; az = 0;
}
