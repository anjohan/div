#include "funksjoner.h"
#include "jacobi.h"
#include <cstdio>

int main(){
    double **A, **R;
    int iterasjoner, i, j, n = 3;
    int *kl = new int[2];
    A = new double*[n];
    R = new double*[n];
    for(i=0; i<n; i++){
        A[i] = new double[n];
        R[i] = new double[n];
    }
    lagidentitet(R,n);
    A[0][0] = 7; A[0][1] = -2; A[0][2] = 0;
    A[1][0] = -2; A[1][1] = 6; A[1][2] = -2;
    A[2][0] = 0; A[2][1] = -2; A[2][2] = 5;

    iterasjoner = jacobi(A,R,n, 1E-12);
    printf("%d\n----\n",iterasjoner);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%7.3f",A[i][j]);
        }
        printf("\n");
    }
    printf("----------------\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%7.3f",R[i][j]);
        }
        printf("\n");
    }
    printf("\n%.4f",finn_storste_utenfor_diagonal_symmetrisk(R,n,kl));
    delete [] A;
    delete [] R;
}
