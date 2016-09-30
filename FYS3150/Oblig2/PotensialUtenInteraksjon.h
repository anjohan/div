#include "Potensial.h"

#ifndef  POTENSIALUTENINTERAKSJON_H
#define POTENSIALUTENINTERAKSJON_H

class PotensialUtenInteraksjon : Potensial{
    public:
        PotensialUtenInteraksjon(double om){
            omega = om;
        }
        double operator()(double rho){
            return omega*rho*rho;
        }
    protected:
        double omega;
};

#endif
