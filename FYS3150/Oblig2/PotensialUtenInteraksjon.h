#include "Potensial.h"
#include <cstdio>

#ifndef  POTENSIALUTENINTERAKSJON_H
#define POTENSIALUTENINTERAKSJON_H

class PotensialUtenInteraksjon : public Potensial{
    public:
        PotensialUtenInteraksjon(double om){
            omega = om;
        }
        virtual double eval(double rho){
            return omega*omega*rho*rho;
        }
    protected:
        double omega;
};

#endif
