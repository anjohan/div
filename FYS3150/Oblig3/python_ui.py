import os
from numpy import *
from argparse import *

if not "cpp_ui.x" in os.listdir("."):
    os.system("make cpp_ui.x")

parser = ArgumentParser(description="User-friendly interface for simulating the solar system.")

parser.add_argument("-f","--filename",type=str,help="Name of file in which to store calculated data.")

parser.add_argument("-m","--method",choices=["euler","verlet"],default="euler",help="Numerical method to be used for simulation.")

parser.add_argument("-t0","--initial_time",type=float,default=0,help="Start time for the simulation.",dest="t0")

parser.add_argument("-tn","--final_time",type=float,default=2,help="Final time for the simulation.",dest="tn")

parser.add_argument("-n","--integration_points",dest="n",type=int,default=100000,help="Number of integration points.")

parser.add_argument("-dn","--write_interval",dest="dn",type=int,default=1,help="Write data to file at every dn'th point.")

parser.add_argument("-s","--sun",action="store_true",help="Add a sun with position and velocity such that the center of mass is in origo and stationary.")

parser.add_argument("-b","--body",action="append",nargs=8,help="Add a body (one -b for each body).", metavar=("name", "mass(solar masses)", "x", "y", "z", "vx", "vy", "vz"))

args = parser.parse_args()

"""
planet[0] = name
planet[1] = m
planet[2] = x
planet[3] = y
planet[4] = z
planet[5] = vx
planet[6] = vy
planet[7] = vz
"""
name = 0; m = 1; x = 2; y = 3; z = 4
vx = 5; vy = 6; vz = 7

planets = args.body
for planet in planets:
    planet[1:] = [float(element) for element in planet[1:]]

if args.sun:
    sun = ["sun",1]
    for i in range(2,8):
        sun.append(-sum([planet[1]*planet[i] for planet in planets]))
    planets = [sun] + planets

argstring = "%s %s %s %s %s %s" % (args.filename,args.method,args.t0,args.tn,args.n,args.dn)
for planet in planets:
    for element in planet:
        argstring += " %s" % element

#print argstring
os.system("./cpp_ui.x " + argstring)
