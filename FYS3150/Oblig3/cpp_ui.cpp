#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string.h>
#include "planet.h"
#include "solarsystem.h"

int main(int argc, char* argv[]){
    if(argc < 24 || (argc - 8) % 8 != 0){
        printf("%d command line arguments provided. 5+8n required for n bodies, 23 minimum.\n", argc-1);
        return 1;
    }
    char* filename = argv[1];
    char* method = argv[2];
    char* sunmotion = argv[3];
    double t0 = atof(argv[4]);
    double tn = atof(argv[5]);
    int n = atoi(argv[6]);
    int dn = atoi(argv[7]);
    char* name;
    int i; double m;
    vector<Planet*> planets;
    double x,y,z,vx,vy,vz;
    Planet *p;
    for(i=8; i < argc; i+=8){
        name = argv[i];
        m = atof(argv[i+1]);
        x = atof(argv[i+2]);
        y = atof(argv[i+3]);
        z = atof(argv[i+4]);
        vx = atof(argv[i+5]);
        vy = atof(argv[i+6]);
        vz = atof(argv[i+7]);
        if(strcmp(sunmotion,"fixed")==0 && strcmp(name,"sun")==0){
            p = new StationaryPlanet(name,m,x,y,z,vx,vy,vz);
        }
        else{
            p = new Planet(name,m,x,y,z,vx,vy,vz);
        }
        planets.push_back(p);
    }
    SolarSystem solarsystem(filename,planets,t0,tn,n,dn);
    if(strcmp(method,"euler")==0){
        //printf("Solving with Forward Euler.\n");
        solarsystem.solve_euler();
    }
    else if(strcmp(method,"verlet")==0){
        //printf("Solving with Velocity-Verlet.\n");
        solarsystem.solve_verlet();
    }
    else{
        printf("Invalid method %s specified.",method);
        return 1;
    }
    int number_of_planets = planets.size();
    for(i=0; i<number_of_planets; i++){
        delete planets[i];
    }
}
