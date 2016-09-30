#include "Potensial.h"
#include <cstdio>

#ifndef  POTENSIALUTENINTERAKSJON_H
#define POTENSIALUTENINTERAKSJON_H

class PotensialUtenInteraksjon : public Potensial{
    public:
        PotensialUtenInteraksjon(double om){
            omega = om;
        }
        double eval(double rho){
            printf("hei\n");
            return omega*omega*rho*rho;
        }
    protected:
        double omega;
};

#endif
