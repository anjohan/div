#!/usr/bin/python

import sys
from math import *

if len(sys.argv)==2:
    print eval(sys.argv[1])
elif len(sys.argv)==3:
    exec(sys.argv[1])
    print eval(sys.argv[2])
else:
    print "Dust"
