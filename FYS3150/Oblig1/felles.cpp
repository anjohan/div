#include <cmath>

double f(double x){
    return 100*exp(-10*x);
}

double eksakt(double x){
    return 1 - (1 - exp(-10))*x - exp(-10*x);
}

void lagmatrise(double* a, double* b, double* c, double* d, int n, double h){
    double x;
    int i;
    for(i=0; i < n-1; i++){
        a[i] = -1;
        b[i] = 2;
        c[i] = -1;
        x = (i+1) * h;
        d[i] = h*h*f(x);
    }
    b[n-1] = 2;
    d[n-1] = h*h*f(n*h);
}

double maksimal_relativ_forskjell(double* a, double* b, int n){
    int i; double maks, relativ_forskjell;

    /* Algoritme for aa finne stoerste forskjell:
     * - Anta at det er stoerst forskjell i foerste element.
     * - Gaa gjennom resten, se om noen forskjeller er stoerre.
     */
    maks = fabs((b[0]-a[0])/a[0]);
    for(i=1; i<n; i++){
        relativ_forskjell = fabs((b[i]-a[i])/a[i]);
        maks = relativ_forskjell > maks ? relativ_forskjell : maks;
    }
    return maks;
}
