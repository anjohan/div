#include "planet.h"
#include "solarsystem.h"
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    vector<Planet*> classic;
    vector<Planet*> relativistic;
    Planet *sun1, *sun2, *mercury1, *mercury2;
    double endtime = 100;
    long int n = 1000000000;
    char *navn1 = (char*) "sunclassic", *navn2 = (char*) "mercuryclassic";
    char *navn3 = (char*) "sunrelativistic", *navn4 = (char*) "mercuryrelativistic";
    char *navn5 = (char*) "classic.dat", *navn6 = (char*) "relativistic.dat";

    sun1 = new Planet(navn1,1.0,-1.652E-7*0.30750,0,0,0,-1.652E-7*12.44,0);
    mercury1 = new PerihelionFinder(navn2,1.652E-7,0.3075,0,0,0,12.44,0);
    sun2 = new RelativisticPlanet(navn3,1.0,-1.652E-7*0.30750,0,0,0,-1.652E-7*12.44,0);
    mercury2 = new RelativisticPlanet(navn4,1.652E-7,0.3075,0,0,0,12.44,0);

    classic.push_back(sun1); classic.push_back(mercury1);
    relativistic.push_back(sun2); relativistic.push_back(mercury2);

    SolarSystem solarsystemclassic(navn5,classic,0,endtime,n,n-3);
    SolarSystem solarsystemrelativistic(navn6,relativistic,0,endtime,n,n-3);

    solarsystemclassic.solve_verlet();
    solarsystemrelativistic.solve_verlet();

    delete sun1; delete sun2; delete mercury1; delete mercury2;
}
