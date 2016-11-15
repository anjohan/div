#include "ising.h"
#include <cstdio>
#include <thread>
using namespace std;

int main(int argc, char* argv[]){
    if(argc < 5){
        printf("Too few arguments!\n");
        return 1;
    }
    const char* outfilename = argv[1];
    int N = atoif(argv[2]);
    int number_of_temperatures = atoi(argv[3]);
    int number_of_parallels = atoi(argv[4]);

    int dN = N+13, startindex=20000;
    double Tstart = 2.2, Tend = 2.4;
    double dT = (Tend-Tstart)/(number_of_temperatures-1);

    int number_of_sizes = 4;
    int Lvals [4] = {40,60,100,140};

    double *T_vals = new double[number_of_temperatures];
    int i,j,k,l;
    for(i=0; i<number_of_temperatures; i++){
        T_vals[i] = Tstart + dT*i;
    }

    int number_of_values = 4;
    int N_per_parallel = (int) round(((double) N)/number_of_parallels);
    thread ****threads = new thread***[number_of_sizes];
    double ****values = new double***[number_of_sizes];
    FILE ****files = new FILE***[number_of_sizes];
    for(i=0; i<number_of_sizes; i++){
        threads[i] = new thread**[number_of_temperatures];
        values[i] = new double**[number_of_temperatures];
        files[i] = new FILE**[number_of_temperatures];
        for(j=0; j<number_of_temperatures; j++){
            threads[i][j] = new thread*[number_of_parallels];
            values[i][j] = new double*[number_of_parallels];
            files[i][j] = new FILE*[number_of_parallels];
            for(k=0; k<number_of_parallels; k++){
                values[i][j][k] = new double[number_of_values];
                char* filename = new char[100];
                sprintf(filename,"phases%d%d%d.dat",i,j,k);
                files[i][j][k] = fopen(filename,"w");
                delete [] filename;
                threads[i][j][k] = new thread(ising,files[i][j][k], "random", Lvals[i], N_per_parallel, dN, T_vals[j], startindex, values[i][j][k]);
            }
        }
    }
    double ***resvalues = new double**[number_of_sizes];

    for(i=0; i<number_of_sizes; i++){
        resvalues[i] = new double*[number_of_temperatures];
        for(j=0; j<number_of_temperatures; j++){
            resvalues[i][j] = new double[number_of_values];
            for(l=0; l<number_of_values; l++){
                resvalues[i][j][l] = 0;
            }
            for(k=0; k<number_of_parallels; k++){
                threads[i][j][k]->join();
                fclose(files[i][j][k]);
                for(l=0; l<number_of_values; l++){
                    resvalues[i][j][l] += values[i][j][k][l]/number_of_parallels;
                }
                delete [] values[i][j][k];
            }
            delete [] threads[i][j];
            delete [] files[i][j];
            delete [] values[i][j];
        }
        delete [] threads[i];
        delete [] files[i];
        delete [] values[i];
    }

    FILE* outfile = fopen(outfilename,"w");
    fprintf(outfile,"$T$");
    for(i=0; i<number_of_sizes; i++){
        for(j=0; j<number_of_values; j++){
            fprintf(outfile," $L=%d$",Lvals[i]);
        }
    }
    fprintf(outfile,"\n");
    for(j=0; j<number_of_temperatures; j++){
        fprintf(outfile,"%g",T_vals[j]);
        for(i=0; i<number_of_sizes; i++){
            for(k=0; k<number_of_values; k++){
                fprintf(outfile," %g",resvalues[i][j][k]);
            }
        }
        fprintf(outfile,"\n");
    }



    fclose(outfile);
    for(i=0; i<number_of_sizes; i++){
        for(j=0; j<number_of_temperatures; j++){
            delete [] resvalues[i][j];
        }
        delete [] resvalues[i];
    }
    delete [] resvalues;

    delete [] T_vals;
}
