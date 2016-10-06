#include <cstdio>
#include "funksjoner.h"
#include "schrodinger.h"
#include "Potensial.h"
#include <ctime>


int main(){
    double rho_min = 0, rho_maks = 8;
    int i,n, antall_iterasjoner;
    char* filnavn;
    double *egenverdier, **egenvektorer, time;
    clock_t t1, t2;
    int* minsteegenverdier = new int[3];
    FILE *fil = fopen("egenverdier.dat","w");
    Potensial *V = new Potensial;
    fprintf(fil,R"(\begin{array}{cccccr}\toprule)"); fprintf(fil,"\n");
    fprintf(fil,R"(n & \lambda_0 & \lambda_1 & \lambda_2 & \text{Number of iterations} & \text{Time}\\)");
    for(n=50; n < 401; n+=50){
        egenverdier = new double[n-1];
        egenvektorer = new double*[n-1];
        for(i=0; i<n-1; i++){
            egenvektorer[i] = new double[n-1];
        }
        filnavn = new char[20];
        sprintf(filnavn,"nlik%d.dat",n);
        t1 = clock();
        antall_iterasjoner = schrodinger(n-1,rho_min,rho_maks,egenverdier,egenvektorer,V,filnavn);
        t2 = clock();
        time = ((double) (t2 - t1))/CLOCKS_PER_SEC;

        finn_de_tre_minste(egenverdier,n-1,minsteegenverdier);

        fprintf(fil,"\\midrule\n \\num{%d}",n);
        for(i=0; i<3; i++){
            fprintf(fil,R"( & \num{%.3f})",egenverdier[minsteegenverdier[i]]);
        }
        fprintf(fil,R"( & \num{%d} & \SI{%.3g}{\second})",antall_iterasjoner,time);
        fprintf(fil,R"(\\)");

        delete [] egenverdier;
        for(i=0; i<n-1; i++){
            delete [] egenvektorer[i];
        }
        delete [] egenvektorer;
        delete [] filnavn;
    }
    delete [] minsteegenverdier;
    delete V;
    fprintf(fil,R"(\bottomrule \end{array})");
    fclose(fil);
}
