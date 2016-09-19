feil = [abs((atan(x+h)-atan(x-h))/(2*h) - (1.0/3)) for h in [10**(-a) for a in linspace(0,10,100)]]
