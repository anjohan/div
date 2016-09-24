#include <cstdio>
#include "funksjoner.h"
#include "schrodinger.h"

double V(double rho) {return rho*rho;}

int main(){
    double rho_min = 0, rho_maks = 9;
    int i,n = 251;
    double *egenverdier, **egenvektorer;
    int* minsteegenverdier = new int[3];
    egenverdier = new double[n-1];
    egenvektorer = new double*[n-1];
    for(i=0; i<n-1; i++){
        egenvektorer[i] = new double[n-1];
    }

    schrodinger(n-1,rho_min,rho_maks,egenverdier,egenvektorer,V,"test.dat");

    finn_de_tre_minste(egenverdier,n-1,minsteegenverdier);

    for(i=0; i<3; i++){
        printf("%5.4f\n",egenverdier[minsteegenverdier[i]]);
    }

    delete [] egenverdier;
    for(i=0; i<n-1; i++){
        delete [] egenvektorer[i];
    }
    delete [] egenvektorer;
}
