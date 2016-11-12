#include "ising.h"
#include <cstdio>
#include <thread>
using namespace std;

int main(){
    int L = 20, N = 1000000, dN = 1;
    double hotT = 2.4, coldT = 1.0;
    FILE* hotfile = fopen("hotanalysis.dat","w");
    FILE* coldfile = fopen("coldanalysis.dat","w");
    FILE* orderedhotfile = fopen("hotorderedanalysis.dat","w");
    FILE* orderedcoldfile = fopen("coldorderedanalysis.dat","w");

    thread hot(ising,hotfile,"random",L,N,dN,hotT);
    thread cold(ising,coldfile,"random",L,N,dN,coldT);
    thread orderedhot(ising,orderedhotfile,"ordered",L,N,dN,hotT);
    thread orderedcold(ising,orderedcoldfile,"ordered",L,N,dN,coldT);

    hot.join();
    cold.join();
    orderedhot.join();
    orderedcold.join();
}
