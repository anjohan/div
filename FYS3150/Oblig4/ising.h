#ifndef ISING_H
#define ISING_H
#include <cstdio>
#include <random>
#include <cstdlib>
#include <cstring>

int index(int i, int L);

int calculate_energy(int **spins, int L);

void output(FILE* file, int i, double T, int E, int E2, int M, int M2, int Mabs);

void ising(FILE* file, const char* mode, int L, int N, int dN, double T);
#endif
