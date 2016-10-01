#include <cstdio>
#include "schrodinger.h"
#include "PotensialUtenInteraksjon.h"
#include "PotensialMedInteraksjon.h"
#include "funksjoner.h"


int main(){
    double omega, rho_min = 0, rho_maks = 8;
    int i,n=250, antall_iterasjoner;
    double *egenverdier, **egenvektorer;
    int* minsteegenverdier = new int[3];
    char* filnavn1, *filnavn2;
    egenvektorer = new double*[n-1];
    egenverdier = new double[n-1];
    PotensialUtenInteraksjon *Vuten;
    PotensialMedInteraksjon *Vmed;
    for(i=0; i<n-1; i++){
        egenvektorer[i] = new double[n-1];
    }
    for(omega=0.04; omega < 6; omega*=5){
        Vuten = new PotensialUtenInteraksjon(omega);
        Vmed = new PotensialMedInteraksjon(omega);
        filnavn1 = new char[20];
        filnavn2 = new char[20];
        sprintf(filnavn1,"omegauten%.2f.dat",omega);
        sprintf(filnavn2,"omegamed%.2f.dat",omega);
        antall_iterasjoner = schrodinger(n-1,rho_min,rho_maks,egenverdier,egenvektorer,Vuten,filnavn1);
        antall_iterasjoner = schrodinger(n-1,rho_min,rho_maks,egenverdier,egenvektorer,Vmed,filnavn2);

        delete [] filnavn1;
        delete [] filnavn2;
        delete Vuten;
        delete Vmed;
    }
    for(i=0; i<n-1; i++){
        delete [] egenvektorer[i];
    }
    delete [] egenvektorer;
    delete [] egenverdier;
    delete [] minsteegenverdier;
}
