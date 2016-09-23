double finn_storste_utenfor_diagonal_symmetrisk(double** A, int n, int* kl){
    double maks = A[1][0] * A[1][0];
    double a_ij, a_ij_kvadrat;
    int k = 1, l = 0;
    int i, j;
    for(i=2; i<n; i++){
        for(j=0; j<i; j++){
            a_ij = A[i][j];
            a_ij_kvadrat = a_ij*a_ij;
            if(a_ij*a_ij > maks){
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
