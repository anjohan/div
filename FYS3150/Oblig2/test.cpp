#include "funksjoner.h"
#include "jacobi.h"
#include <cstdio>

int main(){
    double **A, **R;
    int iterasjoner, i, j, n = 3;
    A = new double*[n];
    R = new double*[n];
    for(i=0; i<n; i++){
        A[i] = new double[n];
        R[i] = new double[n];
    }

    /*#eigenteststart#*/
    A[0][0] = 7; A[0][1] = -2; A[0][2] = 0;
    A[1][0] = -2; A[1][1] = 6; A[1][2] = -2;
    A[2][0] = 0; A[2][1] = -2; A[2][2] = 5;

    iterasjoner = jacobi(A,R,n, 1E-12);
    /*#eigentestslutt#*/

    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%7.3f",A[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------\n");
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%7.3f",R[i][j]);
        }
        printf("\n");
    }
    delete [] A;
    delete [] R;

    FILE *file = fopen("storstetest.txt","w");
    A = new double*[5];
    int *kl = new int[2];
    for(i=0; i<5; i++){
        A[i] = new double[5];
    }
    /*#largeststart#*/
    A[0][0] = 2;
    A[1][0] = 4; A[1][1] = 12;
    A[2][0] = -2; A[2][1] = -5; A[2][2] = 1;
    A[3][0] = 1; A[3][1] = 0; A[3][2] = 4; A[3][3] = 2;
    A[4][0] = 1; A[4][1] = 0; A[4][2] = 4; A[4][3] = 2; A[4][4] = -7;
    largest_nondiagonal_symmetric(A,5,kl);
    fprintf(file,"k=%d, l=%d",kl[0],kl[1]);
    /*#largestend#*/
    fclose(file);
    for(i=0; i<5; i++){
        delete [] A[i];
    }
    delete [] A;
}
