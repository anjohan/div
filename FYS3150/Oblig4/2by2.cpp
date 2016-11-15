#include "ising.h"
#include <cstdio>
#include <thread>
using namespace std;

int main(){
    FILE* file1 = fopen("cold2by2.dat","w");
    FILE* file2 = fopen("2by2long.dat","w");
    FILE* file3 = fopen("hot2by2.dat","w");

    double *quickval = new double[4];
    double *slowval = new double[4];
    double *quickhotval = new double[4];

    thread quick(ising,file1,"random",2,100000,1,1.0,0,quickval);
    thread slow(ising,file2,"random",2,10000000,10000000000000,1.0,0,slowval);
    thread quickhot(ising,file3,"random",2,100000,1,2.4,0,quickhotval);
    quick.join();
    slow.join();
    quickhot.join();

    fclose(file1);
    fclose(file2);
    fclose(file3);

    FILE* resfile = fopen("2by2res.dat","w");
    fprintf(resfile,R"(\[\langle E\rangle/L^2 = \num{%g} \qquad C_V/L^2 = \num{%g} \qquad \langle\abs{M}\rangle/L^2 = \num{%g} \qquad \chi/L^2 = \num{%g}\])",slowval[0],slowval[1],slowval[2],slowval[3]);
    fclose(resfile);

    delete [] quickval;
    delete [] slowval;
    delete [] quickhotval;
}
