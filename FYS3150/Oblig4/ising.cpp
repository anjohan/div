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

void output(FILE* file, int i, int L, double T, double E, double E2, double M, double M2, double Mabs, double energy, int number_of_accepted_flips){
    double divisorinv = 1.0/i;
    double beta = 1/T;
    double E_value = E*divisorinv;
    double E2_value = E2*divisorinv;
    double M_value = M*divisorinv;
    double M2_value = M2*divisorinv;
    double Mabs_value = Mabs*divisorinv;
    divisorinv = 1.0/(L*L);
    double C_V = (E2_value - E_value*E_value)*beta*beta*divisorinv;
    double chi = (M2_value - M_value*M_value)*beta*divisorinv;
    E_value *= divisorinv;
    M_value *= divisorinv;
    Mabs_value *= divisorinv;
    fprintf(file,"%d %g %g %g %g %g %g %d\n",i,E_value,M_value,Mabs_value,C_V,chi,energy,number_of_accepted_flips);
}

void monte_carlo_cycle(int** spins, double* probabilities, int &L, int &L2, double &energy, double &magnetic_moment, int &number_of_accepted_flips, uniform_real_distribution<double> &ran, mt19937_64 &dom){
    int j;
    for(j=0; j<L2; j++){
        int flip_x = (int) (ran(dom)*L);
        int flip_y = (int) (ran(dom)*L);
        int spin_above = spins[flip_x][index(flip_y+1,L)];
        int spin_below = spins[flip_x][index(flip_y-1,L)];
        int spin_right = spins[index(flip_x+1,L)][flip_y];
        int spin_left = spins[index(flip_x-1,L)][flip_y];
        int energy_difference = 2*spins[flip_x][flip_y]*(spin_above+spin_below+spin_right+spin_left);
        if(ran(dom) <= probabilities[(energy_difference+8)/4]){
            energy += energy_difference;
            spins[flip_x][flip_y] *= -1;
            magnetic_moment += 2*spins[flip_x][flip_y];
            number_of_accepted_flips++;
        }
    }
}



void ising(FILE* file, const char* startmode, int L, int N, int dN, double T, int startindex){
    int i, j;
    int L2 = L*L;

    random_device rd;
    mt19937_64 dom(rd());
    uniform_real_distribution<double> ran(0.0,1.0);

    int **spins = new int*[L];
    for(i=0; i<L; i++){
        spins[i] = new int[L];
        for(j=0; j<L; j++){
            if(strcmp(startmode,"random")==0){
                spins[i][j] = ran(dom) > 0.5 ? 1 : -1;
            }
            else{
                spins[i][j] = 1;
            }
        }
    }
    double energy = calculate_energy(spins,L);
    double magnetic_moment = calculate_magnetic_moment(spins,L);
    double expected_energy=0, expected_energy2=0, expected_magnetic_moment=0, expected_magnetic_moment2=0, expected_magnetic_moment_abs=0;
    int number_of_accepted_flips = 0;


    double *probabilities = new double[5];
    for(i=0; i<5; i++){
        probabilities[i] = exp(-(-8+4*i)/T);
    }
    for(i=0; i<startindex; i++){
        monte_carlo_cycle(spins, probabilities, L, L2, energy, magnetic_moment, number_of_accepted_flips, ran, dom);
    }
    expected_energy=0, expected_energy2=0, expected_magnetic_moment=0, expected_magnetic_moment2=0, expected_magnetic_moment_abs=0;
    number_of_accepted_flips = 0;
    int endindex = N - startindex;
    for(i=0; i<endindex; i++){
        expected_energy += energy;
        expected_energy2 += energy*energy;
        expected_magnetic_moment += magnetic_moment;
        expected_magnetic_moment2 += magnetic_moment*magnetic_moment;
        expected_magnetic_moment_abs += abs(magnetic_moment);
        if(i % dN == 0){
            output(file,i+1,L,T,expected_energy,expected_energy2,expected_magnetic_moment,expected_magnetic_moment2,expected_magnetic_moment_abs,energy,number_of_accepted_flips);
        }
        monte_carlo_cycle(spins, probabilities, L, L2, energy, magnetic_moment, number_of_accepted_flips, ran, dom);
    }
    output(file,endindex,L,T,expected_energy,expected_energy2,expected_magnetic_moment,expected_magnetic_moment2,expected_magnetic_moment_abs,energy,number_of_accepted_flips);
    for(i=0; i<L; i++){
        delete [] spins[i];
    }
    delete [] spins;
    delete [] probabilities;
}
