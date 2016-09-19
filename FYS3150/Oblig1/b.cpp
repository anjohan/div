#include <cstdio>
#include "felles.h"
#include "generell.h"
#include "spesiell.h"

int main(){
    double *a, *b, *c, *d, *v;
    double h, x;
    int n, i;
    char *filnavn;
    FILE* fil;
    for(n=10; n<1001; n*=10){
        h = 1.0/(n+1);
        a = new double[n-1]; c = new double[n-1];
        b = new double[n]; d = new double[n]; v = new double[n+2];

        //Oppsett av variable
        v[0] = 0; v[n+1] = 0;
        lagmatrise(a,b,c,d,n,h);

        //Finn v:
        generell(a,b,c,d,&v[1],n);
        delete [] a; delete [] b; delete [] c;

        //Skriv resultatene til fil:
        filnavn = new char[20];
        sprintf(filnavn,"generell%d.dat",n);
        fil = fopen(filnavn,"w");
        for(i=0; i < n+2; i++){
            fprintf(fil, "%.3f %.3f\n", i*h, v[i]);
        }
        fclose(fil);
        delete [] filnavn;
        //Lag plott av spesiell i tillegg
        spesiell(d,&v[1],n);
        filnavn = new char[20];
        sprintf(filnavn,"spesiell%d.dat",n);
        fil = fopen(filnavn,"w");
        for(i=0; i < n+2; i++){
            fprintf(fil, "%.3f %.3f\n", i*h, v[i]);
        }
        fclose(fil);
        delete [] d; delete [] v; delete [] filnavn;
    }
    // Eksakt
    fil = fopen("bu.dat","w");
    n /= 10;
    for(i=0; i < n+2; i++){
        x = i*h;
        fprintf(fil, "%.3f %.3f\n",x,eksakt(x));
    }
    fclose(fil);
}
