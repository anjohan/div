#include <cstdio>
#include <ctime>
#include <armadillo>
#include "felles.h"
#include "spesiell.h"

using namespace arma;

int main(){
    double *d, *v, h, t_spesiell, t_lu, y, r;
    clock_t t1, t2;
    int i, n;
    mat A; vec d2, v2;
    FILE *fil = fopen("e.dat","w");
    //Skriv ferdige LaTeX-tabeller (krever booktabs-pakken):
    fprintf(fil,"\\begin{tabular}{rrrr}\\toprule\n\\multicolumn{1}{c}{\\(n\\)} & \\multicolumn{1}{c}{LU} & \\multicolumn{1}{c}{Spesiell} & \\multicolumn{1}{c}{Forhold}\\\\");
    for(n=10; n < 10001; n*=10){
        A = zeros<mat>(n,n);
        d2 = zeros<vec>(n);

        v = new double[n+2];
        d = new double[n];
        h = 1.0/(n+1);
        for(i=0; i<n; i++){
            y = h*h*f(i*h);
            d[i] = y;
            d2[i] = y;
        }
        t_spesiell = spesiell(d,&v[1],n);
        delete [] v;

        A.at(0,0) = 2; A.at(0,1) = -1;
        A.at(n-1,n-2) = -1; A.at(n-1,n-1) = 2;
        for(i=1; i < n-1; i++){
            A.at(i,i-1) = -1;
            A.at(i,i) = 2;
            A.at(i,i+1) = -1;
        }
        t1 = clock();
        v2 = solve(A,d2);
        t2 = clock();
        t_lu = ((double) (t2 - t1))/CLOCKS_PER_SEC;
        r =  t_spesiell != 0 ? t_lu/t_spesiell : 0;

        delete [] d;
        fprintf(fil,"\\midrule\n \\(\\num{%d}\\) & \\(\\SI{%.3g}{\\second}\\) & \\(\\SI{%.3g}{\\second}\\) & \\(\\num{%.3g}\\)\\\\",n,t_lu,t_spesiell,r);
    }
    fprintf(fil,"\\bottomrule\n\\end{tabular}");
    fclose(fil);
}
