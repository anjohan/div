#include "PotensialUtenInteraksjon.h"

#ifndef  POTENSIALMEDINTERAKSJON_H
#define POTENSIALMEDINTERAKSJON_H

class PotensialMedInteraksjon : public PotensialUtenInteraksjon{
    public:
        PotensialMedInteraksjon(double omega) : PotensialUtenInteraksjon(omega){;}
        double eval(double rho){
            return PotensialUtenInteraksjon::eval(rho) + 1/rho;
        }
};

#endif
