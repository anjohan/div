#ifndef SCHRODINGER_H
#define SCHRODINGER_H
#include "Potensial.h"

int schrodinger(int n, double rho_min, double rho_max, double* egenverdier, double** egenvektorer, Potensial* V, char* filnavn);
#endif
