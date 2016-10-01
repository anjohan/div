#ifndef  POTENSIALMEDINTERAKSJON_H
#define POTENSIALMEDINTERAKSJON_H

#include "Potensial.h"
#include "PotensialUtenInteraksjon.h"

class PotensialMedInteraksjon : public PotensialUtenInteraksjon{
    public:
        PotensialMedInteraksjon(double omega) : PotensialUtenInteraksjon(omega){;}
        virtual double eval(double rho){
            return PotensialUtenInteraksjon::eval(rho) + 1/rho;
        }
};

#endif
