#include "ising.h"
#include <cstdio>
#include <thread>
using namespace std;

int main(){
    FILE* file1 = fopen("cold2by2.dat","w");
    FILE* file2 = fopen("2by2long.dat","w");
    FILE* file3 = fopen("hot2by2.dat","w");

    thread quick(ising,file1,"random",2,100000,1,1.0);
    thread slow(ising,file2,"random",2,10000000,10000000000000,1.0);
    thread quickhot(ising,file3,"random",2,100000,1,2.4);
    quick.join();
    slow.join();
    quickhot.join();

    fclose(file1);
    fclose(file2);
    fclose(file3);
}
