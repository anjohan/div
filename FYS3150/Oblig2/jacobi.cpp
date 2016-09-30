#include "funksjoner.h"
#include <cmath>
#include <cstdio>

int jacobi(double** A, double** R, int n, double toleranse = 1E-8){
    double tau, tangens, cosinus, sinus, maks;
    int i, k, l, *kl, iterasjoner, maks_iterasjoner;
    double a_kk, a_ll, a_kl, a_ik, a_il, r_ik, r_il;
    kl = new int[2];
    maks_iterasjoner = 1000000;
    iterasjoner = 0;
    lagidentitet(R,n);
    //skrivmatrise(R,n);
    maks = finn_storste_utenfor_diagonal_symmetrisk(A,n,kl);
    while(iterasjoner <= maks_iterasjoner && maks > toleranse){
        k = kl[0]; l = kl[1];
        a_kk = A[k][k]; a_ll = A[l][l]; a_kl = A[k][l];
        tau = (a_ll-a_kk)/(2*a_kl);
        tangens = 1/(tau - (tau>0 ? 1 : -1)*sqrt(1 + tau*tau));
        cosinus = 1/sqrt(1 + tangens*tangens);
        sinus = tangens*cosinus;

        //Transformasjon:
        A[k][k] = a_kk*cosinus*cosinus - 2*a_kl*cosinus*sinus + a_ll*sinus*sinus;
        A[l][l] = a_ll*cosinus*cosinus + 2*a_kl*cosinus*sinus + a_kk*sinus*sinus;
        A[k][l] = 0;
        A[l][k] = 0; //Symmetrisk
        for(i=0; i<n; i++){
            if(i!=k && i!=l){
                a_ik = A[i][k]; a_il = A[i][l];
                A[i][k] = a_ik*cosinus - a_il*sinus;
                A[i][l] = a_il*cosinus + a_ik*sinus;
                A[k][i] = A[i][k]; A[l][i] = A[i][l]; //Symmetrisk
            }
            r_ik = R[i][k]; r_il = R[i][l];
            //Oppdaterer egenvektormatrisen:
            R[i][k] = r_ik*cosinus - r_il*sinus;
            R[i][l] = r_ik*sinus + r_il*cosinus;
        }

        iterasjoner++;
        if(iterasjoner % 1000 == 0){
            printf("\r%d",iterasjoner);
            fflush(stdout);
        }
        maks = finn_storste_utenfor_diagonal_symmetrisk(A,n,kl);
    }
    printf("\n");
    return iterasjoner;
}
