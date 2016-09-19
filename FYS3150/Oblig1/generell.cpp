#include <ctime>

double generell(double* a, double* b, double* c, double* d, double* v, int n){
    /* Parameterne er som beskrevet i algoritmen
     * for generelle, tridiagonale matriser.
     */
    clock_t t1, t2;
    double t, r;
    int i;
    double *b_ny = new double[n];
    double *d_ny = new double[n];
    b_ny[0] = b[0];
    d_ny[0] = d[0];
    t1 = clock();

    //Radreduksjon:
    for(i=1; i<n; i++){
        if(a[i-1]!=0){
            r = a[i-1]/b_ny[i-1];
            b_ny[i] = b[i]-c[i-1]*r;
            d_ny[i] = d[i]-d_ny[i-1]*r;
        }
        else {
            b_ny[i] = b[i];
            d_ny[i] = d[i];
        }
    }

    //Tilbakesubstitusjon:
    v[n-1] = d_ny[n-1]/b_ny[n-1];
    for(i=n-2; i>=0; i--){
        v[i] = (d_ny[i] - c[i]*v[i+1])/b_ny[i];
    }
    t2 = clock();
    t = ((double) (t2 - t1))/CLOCKS_PER_SEC;
    delete [] b_ny;
    delete [] d_ny;
    return t;
}
