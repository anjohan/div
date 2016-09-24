#include <cstdio>

double finn_storste_utenfor_diagonal_symmetrisk(double** A, int n, int* kl){
    double maks = A[1][0] * A[1][0];
    double a_ij, a_ij_kvadrat;
    int k = 1, l = 0;
    int i, j;
    for(i=2; i<n; i++){
        for(j=0; j<i; j++){
            a_ij = A[i][j];
            a_ij_kvadrat = a_ij*a_ij;
            if(a_ij_kvadrat > maks){
                k = i; l = j;
                maks = a_ij_kvadrat;
            }
        }
    }
    kl[0] = k; kl[1] = l;
    return maks;
}

void lagidentitet(double** R, int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            R[i][j] = i==j ? 1 : 0;
        }
    }
}

void finn_de_tre_minste(double* verdier, int n, int* resultater){
    double minste, nestminste, nestnestminste;
    int idx_minste, idx_nestminste, idx_nestnestminste, i;
    minste = verdier[0]; idx_minste=0;
    for(i=1; i<n; i++){
        if(verdier[i] < minste){
            minste = verdier[i]; idx_minste=i;
        }
    }
    resultater[0] = idx_minste;
    i = idx_minste == 0 ? 1 : 0;
    idx_nestminste = i; nestminste = verdier[i];
    while(i<n){
        if(verdier[i] < nestminste && verdier[i] > minste){
            idx_nestminste = i; nestminste = verdier[i];
        }
        i++;
    }
    resultater[1] = idx_nestminste;
    if(idx_minste == 0){i = idx_nestminste == 1 ? 2 : 1;}
    else if(idx_minste == 1){i = idx_nestminste == 0? 2 : 0;}
    else{i = idx_nestminste == 0 ? 1 : 0;}
    idx_nestnestminste = i; nestnestminste = verdier[i];
    while(i<n){
        if(verdier[i] < nestnestminste && verdier[i] > nestminste){
            idx_nestnestminste = i; nestnestminste = verdier[i];
        }
        i++;
    }
    resultater[2] = idx_nestnestminste;
}

void skrivmatrise(double** A, int n){
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            printf("%8.4f ",A[i][j]);
        }
        printf("\n");
    }
}
