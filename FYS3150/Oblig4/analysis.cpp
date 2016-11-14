#include "ising.h"
#include <cstdio>
#include <thread>
#include <map>
#include <cmath>
using namespace std;

void findpdf(const char* infile, const char* outfile);

int main(){
    int L = 20, N = 1000000, dN = 1, startindex=0;
    double hotT = 2.4, coldT = 1.0;
    FILE* hotfile = fopen("hotanalysis.dat","w");
    FILE* coldfile = fopen("coldanalysis.dat","w");
    FILE* orderedhotfile = fopen("hotorderedanalysis.dat","w");
    FILE* orderedcoldfile = fopen("coldorderedanalysis.dat","w");

    /*#threadstart#*/
    thread hot(ising,hotfile,"random",L,N,dN,hotT,startindex);
    thread cold(ising,coldfile,"random",L,N,dN,coldT,startindex);
    thread orderedhot(ising,orderedhotfile,"o",L,N,dN,hotT,startindex);
    thread orderedcold(ising,orderedcoldfile,"o",L,N,dN,coldT,startindex);

    hot.join();
    cold.join();

    thread hotpdf(findpdf,"hotanalysis.dat","hotpdf.dat");
    thread coldpdf(findpdf,"coldanalysis.dat","coldpdf.dat");

    orderedhot.join();
    orderedcold.join();
    hotpdf.join();
    coldpdf.join();
    /*#threadend#*/
}

void findpdf(const char* infilename, const char* outfilename){
    map<int,int> histogram;
    FILE* infile = fopen(infilename,"r");

    double energy, energy_expectation, M, Mabs, C_V, chi;
    int i, accepted, energy_int;

    while(fscanf(infile,"%d %lg %lg %lg %lg %lg %lg %d\n",&i,&energy_expectation,&M,&Mabs,&C_V,&chi,&energy,&accepted) == 8){
        energy_int = (int) round(energy);
        histogram[energy_int] += 1;
    }
    fclose(infile);

    int count;
    FILE* outfile = fopen(outfilename,"w");
    for(pair<int,int> values : histogram){
        energy_int = values.first;
        count = values.second;
        fprintf(outfile,"%d %d\n",energy_int,count);
    }
    fclose(outfile);
}
