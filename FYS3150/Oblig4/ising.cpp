#include <cstdio>
#include <random>

using namespace std;

int index(int i, int L){
    return i % L;
}

int energy(int **spins, int L){
    int i,j;
    int E = 0;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++){
            E -= spins[index(i,L)][index(j,L)] * (spins[index(i+1,L)][index(j,L)] + spins[index(i,L)][index(j+1,L)]);
        }
    }
    return E;
}

int magnetic_moment(int **spins, int L){
    int i,j;
    int M = 0;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++){
            M += spins[i][j];
        }
    }
    return M;
}



void ising(){
    int L = 2, i, j, k, l;
    double T = 1.0;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<double> random(0.0,1.0);

    int **spins = new int*[L];
    for(i=0; i<L; i++){
        spins[i] = new int[L];
        for(j=0; j<L; j++){
            spins[i][j] = 1;
        }
    }
    int N = 1000000;
    int E = energy(spins,L);

    double probabilities[5];
    for(i=0; i<5; i++){
        probabilities[i] = exp(-(-8+4*i)/T);
    }

    for(i=0; i<N; i++){
        ;
    }




    for(i=0; i<L; i++){
        delete [] spins[i];
    }
    delete [] spins;
}

int main(){
    ising();
}
