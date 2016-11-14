#ifndef ISING_H
#define ISING_H
#include <cstdio>
#include <random>
#include <cstdlib>
#include <cstring>
#include <cmath>

int index(int i, int L);

int calculate_energy(int **spins, int L);

void output(FILE* file, int i, double T, double E, double E2, double M, double M2, double Mabs);

void ising(FILE* file, const char* mode, int L, int N, int dN, double T);
#endif
