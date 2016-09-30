#include "jacobi.h"
#include "funksjoner.h"
#include <cstdio>


int schrodinger(int n, double rho_min, double rho_max, double* egenverdier, double** egenvektorer, double (*V)(double),char* filnavn){
    int i, j, antall_iterasjoner;
    double **A, h, h2invers, x_ij;
    A = new double*[n];
    h = (rho_max - rho_min)/(n+1);
    h2invers = 1/(h*h);
    for(i=0; i<n; i++){
        A[i] = new double[n];
        for(j=0; j<n; j++){
            A[i][j]=0;
        }
    }
    A[0][0] = 2*h2invers + (*V)(h);
    A[n-1][n-1] = 2*h2invers + (*V)((n-1)*h);
    A[0][1] = -h2invers;
    A[n-1][n-2] = -h2invers;
    for(i=1; i<n-1; i++){
        A[i][i-1] = -h2invers;
        A[i][i+1] = -h2invers;
        A[i][i] = 2*h2invers + (*V)(rho_min + (i+1)*h);
    }

    antall_iterasjoner = jacobi(A,egenvektorer,n);
    //skrivmatrise(A,n); printf("----------\n"); skrivmatrise(egenvektorer,n);

    for(i=0; i<n; i++){
        egenverdier[i] = A[i][i];
    }

    int* minsteegenverdier = new int[3];
    finn_de_tre_minste(egenverdier,n,minsteegenverdier);

    FILE* fil = fopen(filnavn,"w");
    fprintf(fil,"\\\\rho;");
    for(i=0; i<3; i++){
        fprintf(fil,"$\\\\lambda=%5.3f$;",egenverdier[minsteegenverdier[i]]);
    }
    fprintf(fil,"\n");
    for(i=0; i<4; i++){
        fprintf(fil,"0;");
    }
    fprintf(fil,"\n");
    for(i=0; i<n; i++){
        fprintf(fil,"%.6f;",(i+1)*h);
        for(j=0; j<3; j++){
            x_ij = egenvektorer[i][minsteegenverdier[j]];
            fprintf(fil,"%.6f;",x_ij*x_ij);
        }
        fprintf(fil,"\n");
    }


    fclose(fil);

   for(i=0; i<n; i++){
        delete [] A[i];
    }
    delete [] A;
    delete [] minsteegenverdier;
    return antall_iterasjoner;
}
