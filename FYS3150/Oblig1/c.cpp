#include <cstdio>
#include <cmath>
#include "felles.h"
#include "generell.h"
#include "spesiell.h"

int main(){
    double *a, *b, *c, *d, *v, *u, h, t_generell, t_spesiell, r, epsilon;
    int n, i;
    FILE *fil1 = fopen("c.dat","w");
    FILE *fil2 = fopen("d.dat","w");
    // Skriv ferdige LaTeX-tabeller (krever booktabs-pakken):
    fprintf(fil1,"\\begin{tabular}{rrrr}\\toprule\n\\multicolumn{1}{c}{\\(n\\)} & \\multicolumn{1}{c}{Generell} & \\multicolumn{1}{c}{Spesiell} & \\multicolumn{1}{c}{Forhold}\\\\");
    fprintf(fil2,"\\begin{tabular}{rr}\\toprule\n\\multicolumn{1}{c}{\\(n\\)} & \\multicolumn{1}{c}{\\(\\max\\qty{\\epsilon_i}\\)}\\\\");
    for(n=10; n < 1.1E8; n*=10){
        // Sett opp variable:
        h = 1.0/(n+1);
        a = new double[n-1]; c = new double[n-1];
        b = new double[n]; d = new double[n];
        v = new double[n+2]; u = new double[n+2];

        //Finn tidsbruk:
        lagmatrise(a,b,c,d,n,h);
        t_generell = generell(a,b,c,d,&v[1],n);
        delete [] a; delete [] b; delete [] c;
        t_spesiell = spesiell(d,&v[1],n);
        r =  t_spesiell != 0 ? t_generell/t_spesiell : 0;

        //Finn eksakt svar:
        for(i=1; i < n+1; i++){
            u[i] = eksakt(i*h);
        }

        //Relativ feil:
        epsilon = log10(maksimal_relativ_forskjell(&u[1],&v[1],n));

        //Skriv resultatene til fil:
        fprintf(fil1,"\\midrule\n \\(\\num{%d}\\) & \\(\\SI{%.3g}{\\second}\\) & \\(\\SI{%.3g}{\\second}\\) & \\(\\num{%.3g}\\)\\\\",n,t_generell,t_spesiell,r);
        fprintf(fil2,"\\midrule\n \\(\\num{%d}\\)& \\(\\num{%.3g}\\)\\\\",n,epsilon);

        delete [] d; delete [] v; delete [] u;
    }
    fprintf(fil1,"\\bottomrule\n\\end{tabular}");
    fprintf(fil2,"\\bottomrule\n\\end{tabular}");
    fclose(fil1); fclose(fil2);
}
