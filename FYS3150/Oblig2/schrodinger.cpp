#include "jacobi.h"


void schrodinger(int n, double rho_min, double rho_max, double* egenverdier, double** egenvektorer, double (*V)(double)){
    int i, j;
    double **A, h, h2invers;
    A = new double*[n];
    h = (rho_max - rho_min)/n;
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
        A[i][i] = 2*h2invers + (*V)((i+1)*h);
    }

    jacobi(A,egenvektorer,n);

    for(i=0; i<n; i++){
        egenverdier[i] = A[i][i];
    }

   for(i=0; i<n; i++){
        delete [] A[i];
    }
    delete [] A;
}
