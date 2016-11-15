#include "ising.h"

int main(){
    FILE* file = fopen("test.dat","w");
    ising(file, "random", 140, 1000000, 10000000, 2.2, 0);
    fclose(file);
}
