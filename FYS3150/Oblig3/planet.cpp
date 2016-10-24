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


void PerihelionFinder::verlet_update_position(){
    double x_old = x, y_old = y;
    Planet::verlet_update_position();
    r_reallyold = r_old;
    r_old = r;
    r = x*x + y*y + z*z;
    if(r_reallyold > r_old && r_old < r){ // Perihelion found!
        double theta_p = atan(y_old/x_old);
        double t = i*dt;
        theta_p *= 180/M_PI*3600; // Arc seconds.
        fprintf(perihelionfile,"%f %f\n",t,theta_p);
    }
    i++;
}

void RelativisticPlanet::calculate_acceleration(Planet* other){
    double dx, dy, dz;
    dx = other->x - x;
    dy = other->y - y;
    dz = other->z - z;
    double lx, ly, lz;
    lx = y*vz-z*vy;
    ly = z*vx-x*vz;
    lz = x*vy-y*vz;
    double l_norm2 = lx*lx + ly*ly + lz*lz;
    double dr_norm = sqrt(dx*dx + dy*dy + dz*dz);
    double factor1 = other->mass_ratio_4pi2/(dr_norm*dr_norm*dr_norm);
    double factor2 = 1+3*l_norm2/(dr_norm*dr_norm*c*c);
    double factor = factor1*factor2;
    ax += dx*factor;
    ay += dy*factor;
    az += dz*factor;
}
