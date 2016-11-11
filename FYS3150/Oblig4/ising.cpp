#include "ising.h"

using namespace std;

int index(int i, int L){
    if(i == -1) return L-1;
    if(i == L) return 0;
    return i;
}

int calculate_energy(int **spins, int L){
    int i,j;
    int E = 0;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++){
            E -= spins[index(i,L)][index(j,L)] * (spins[index(i+1,L)][index(j,L)] + spins[index(i,L)][index(j+1,L)]);
        }
    }
    return E;
}

int calculate_magnetic_moment(int **spins, int L){
    int i,j;
    int M = 0;
    for(i=0; i<L; i++){
        for(j=0; j<L; j++){
            M += spins[i][j];
        }
    }
    return M;
}

void output(FILE* file, int i, double T, int E, int E2, int M, int M2, int Mabs){
    double E_value = ((double) E)/i;
    double E2_value = ((double) E2)/i;
    double M_value = ((double) M)/i;
    double M2_value = ((double) M2)/i;
    double Mabs_value = ((double) Mabs)/i;
    double beta = 1/T;
    double C_V = (E2_value - E_value*E_value)*beta*beta;
    double chi = (M2_value - M_value*M_value)*beta;
    fprintf(file,"%d %g %g %g %g %g %g %g %g\n",i,T,E_value,E2_value,M_value,M2_value,Mabs_value,C_V,chi);
}



void ising(FILE* file, int L, int N, int dN, double T){
    int i, j;
    int L2 = L*L;

    random_device rd;
    mt19937_64 gen(rd());
    uniform_real_distribution<double> random(0.0,1.0);
    //srand(time(NULL));

    int **spins = new int*[L];
    for(i=0; i<L; i++){
        spins[i] = new int[L];
        for(j=0; j<L; j++){
            spins[i][j] = random(gen) > 0.5 ? 1 : -1;
        }
    }
    int energy = calculate_energy(spins,L);
    int magnetic_moment = calculate_magnetic_moment(spins,L);
    int expected_energy=0, expected_energy2=0, expected_magnetic_moment=0, expected_magnetic_moment2=0, expected_magnetic_moment_abs=0;


    double probabilities[5];
    for(i=0; i<5; i++){
        probabilities[i] = exp(-(-8+4*i)/T);
    }

    for(i=0; i<N; i++){
        expected_energy += energy;
        expected_energy2 += energy*energy;
        expected_magnetic_moment += magnetic_moment;
        expected_magnetic_moment2 += magnetic_moment*magnetic_moment;
        expected_magnetic_moment_abs += abs(magnetic_moment);
        if(i % dN == 0){
            output(file,i+1,T,expected_energy,expected_energy2,expected_magnetic_moment,expected_magnetic_moment2,expected_magnetic_moment_abs);
        }
        for(j=0; j<L2; j++){
            int flip_x = (int) (random(gen)*L);
            int flip_y = (int) (random(gen)*L);
            int spin_above = spins[index(flip_x,L)][index(flip_y+1,L)];
            int spin_below = spins[index(flip_x,L)][index(flip_y-1,L)];
            int spin_right = spins[index(flip_x+1,L)][index(flip_y,L)];
            int spin_left = spins[index(flip_x-1,L)][index(flip_y,L)];
            int energy_difference = 2*spins[flip_x][flip_y]*(spin_above+spin_below+spin_right+spin_left);
            if(random(gen) <= probabilities[(energy_difference+8)/4]){
                //printf("Flipping (%d,%d)\n",flip_x,flip_y);
                energy += energy_difference;
                spins[flip_x][flip_y] *= -1;
                magnetic_moment += 2*spins[flip_x][flip_y];
            }
        }
    }
    expected_energy *= 1.0/N;
    expected_energy2 *= 1.0/N;
    expected_magnetic_moment *= 1.0/N;
    expected_magnetic_moment2 *= 1.0/N;
    expected_magnetic_moment_abs *= 1.0/N;
    for(i=0; i<L; i++){
        delete [] spins[i];
    }
    delete [] spins;
}
