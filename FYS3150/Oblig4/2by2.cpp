#include "ising.h"
#include <cstdio>
#include <thread>
using namespace std;

int main(){
    FILE* file1 = fopen("2by2.dat","w");
    FILE* file2 = fopen("2by2long.dat","w");

    // ising(file1,2,10000000,1000,1.0);
    // ising(file2,2,10000000,1000,1.0);

    thread quick(ising,file1,2,100000,1000,1.0);
    thread slow(ising,file2,2,10000000,1000,1.0);
    quick.join();
    slow.join();

    fclose(file1);
    fclose(file2);
}
