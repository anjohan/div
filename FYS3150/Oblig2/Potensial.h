#ifndef POTENSIAL_H
#define POTENSIAL_H

class Potensial{
    public:
        virtual double eval(double rho){return rho*rho;}
        virtual ~Potensial(){;}
};



#endif
