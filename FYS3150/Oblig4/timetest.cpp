#include "ising.h"
#include <ctime>
#include <cstdio>
#include <thread>
using namespace std;

int main(){
    int L = 30, N = 100000, dN = N+37, startindex=0;
    double T = 1.0;
    double partime, seqtime;

    FILE* file1 = fopen("time1.dat","w");
    FILE* file2 = fopen("time2.dat","w");
    FILE* file3 = fopen("time3.dat","w");
    FILE* file4 = fopen("time4.dat","w");

    double *res1 = new double[4];
    double *res2 = new double[4];
    double *res3 = new double[4];
    double *res4 = new double[4];

    time_t start = time(NULL);
    ising(file1,"random",L,N,dN,T,startindex,res1);
    ising(file2,"random",L,N,dN,T,startindex,res2);
    time_t end = time(NULL);
    seqtime = difftime(end,start);

    start = time(NULL);
    thread thread1(ising,file3,"random",L,N,dN,T,startindex,res3);
    thread thread2(ising,file4,"random",L,N,dN,T,startindex,res4);
    thread1.join();
    thread2.join();
    end = time(NULL);
    partime = difftime(end,start);

    FILE* file = fopen("time.dat","w");
    fprintf(file,R"(\[\text{Sequential time: }\SI{%g}{\second}\qquad\text{Parallel time: }\SI{%g}{\second}\])",seqtime,partime);
    fclose(file);
}
