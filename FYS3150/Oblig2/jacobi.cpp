#include "funksjoner.h"
#include <cmath>
#include <cstdio>

int jacobi(double** A, double** R, int n, double tolerance = 1E-8){
    double tau, tangens, cosinus, sinus, max;
    int i, k, l, *kl, iterations, max_iterations;
    double a_kk, a_ll, a_kl, a_ik, a_il, r_ik, r_il;
    kl = new int[2];
    max_iterations = 1000000;
    iterations = 0;
    lagidentitet(R,n);
    /*#jacobistart#*/
    max = largest_nondiagonal_symmetric(A,n,kl);
    do {
        k = kl[0]; l = kl[1];
        a_kk = A[k][k]; a_ll = A[l][l]; a_kl = A[k][l];
        tau = (a_ll-a_kk)/(2*a_kl);
        tangens = -tau - (tau>0 ? -1 : 1)*sqrt(1 + tau*tau);
        cosinus = 1/sqrt(1 + tangens*tangens);
        sinus = tangens*cosinus;

        A[k][k] = a_kk*cosinus*cosinus - 2*a_kl*cosinus*sinus\
                  + a_ll*sinus*sinus;
        A[l][l] = a_ll*cosinus*cosinus + 2*a_kl*cosinus*sinus\
                  + a_kk*sinus*sinus;
        A[k][l] = 0;
        A[l][k] = 0;
        for(i=0; i<n; i++){
            if(i!=k && i!=l){
                a_ik = A[i][k]; a_il = A[i][l];
                A[i][k] = a_ik*cosinus - a_il*sinus;
                A[i][l] = a_il*cosinus + a_ik*sinus;
                A[k][i] = A[i][k]; A[l][i] = A[i][l]; //Symmetric
            }
            r_ik = R[i][k]; r_il = R[i][l];
            R[i][k] = r_ik*cosinus - r_il*sinus;
            R[i][l] = r_ik*sinus + r_il*cosinus;
        }

        iterations++;
        max = largest_nondiagonal_symmetric(A,n,kl);
    } while(iterations <= max_iterations && max > tolerance);
    /*#jacobiend#*/
    return iterations;
}
