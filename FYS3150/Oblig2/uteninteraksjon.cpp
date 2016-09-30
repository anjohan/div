#include <cstdio>
#include "funksjoner.h"
#include "schrodinger.h"

double V(double rho) {return rho*rho;}

int main(){
    double rho_min = 0, rho_maks = 8;
    int i,n, antall_iterasjoner;
    char* filnavn;
    double *egenverdier, **egenvektorer;
    int* minsteegenverdier = new int[3];
    FILE *fil = fopen("egenverdier.dat","w");
    fprintf(fil,R"(\begin{array}{ccccc}\toprule)"); fprintf(fil,"\n");
    fprintf(fil,R"(n & \lambda_0 & \lambda_1 & \lambda_2 & \text{Number of iterations}\\)");
    for(n=50; n < 351; n+=50){
        egenverdier = new double[n-1];
        egenvektorer = new double*[n-1];
        for(i=0; i<n-1; i++){
            egenvektorer[i] = new double[n-1];
        }
        filnavn = new char[20];
        sprintf(filnavn,"nlik%d.dat",n);
        antall_iterasjoner = schrodinger(n-1,rho_min,rho_maks,egenverdier,egenvektorer,V,filnavn);

        finn_de_tre_minste(egenverdier,n-1,minsteegenverdier);

        fprintf(fil,"\\midrule\n \\num{%d}",n);
        for(i=0; i<3; i++){
            fprintf(fil,R"( & \num{%.3f})",egenverdier[minsteegenverdier[i]]);
        }
        fprintf(fil,R"( & \num{%d})",antall_iterasjoner);
        fprintf(fil,R"(\\)");

        delete [] egenverdier;
        for(i=0; i<n-1; i++){
            delete [] egenvektorer[i];
        }
        delete [] egenvektorer;
        delete [] filnavn;
    }
    delete [] minsteegenverdier;
    fprintf(fil,R"(\bottomrule \end{array})");
    fclose(fil);
}
