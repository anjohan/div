#include <ctime>

double spesiell(double* d, double* v, int n){
    /* Parameterne er som beskrevet i algoritmen
     * for generelle, tridiagonale matriser.
     */
    clock_t t1, t2;
    double t;
    double *b_ny = new double[n];
    double *d_ny = new double[n];
    int i;
    t1 = clock();

    //Radreduksjon:
    b_ny[0] = 2;
    d_ny[0] = d[0];
    for(i=1; i<n; i++){
        b_ny[i] = (i+2.0)/(i+1); //C++ indekserer fra 0
        d_ny[i] = d[i] + d_ny[i-1]/b_ny[i-1];
    }

    //Tilbakesubstitusjon:
    v[n-1] = d_ny[n-1]/b_ny[n-1];
    for(i=n-2; i>-1; i--){
        v[i] = (d_ny[i] + v[i+1])/b_ny[i];
    }
    t2 = clock();
    t = ((double) (t2 - t1))/CLOCKS_PER_SEC;
    delete [] d_ny;
    delete [] b_ny;
    return t;
}
