import os
if "table.dat" in os.listdir("."):
    os.system("rm table.dat")
from math import sqrt
with open("table.dat","w") as outfile:
    outfile.write(r"""
    \[\begin{array}{rcc}\toprule
    \multicolumn{1}{c}{n} & \text{Euler error} & \text{Verlet error}""")
    with open("error.dat","r") as infile:
        for line in infile:
            n, eulerx, eulery, verletx, verlety = [float(word) for word in line.split()]
            erroreuler = sqrt((eulerx-1)**2 + eulery**2)
            errorverlet = sqrt((verletx-1)**2 + verlety**2)
            outfile.write(r"""\\ \midrule
            \num{%d} & \num{%.2g} & \num{%.2g}""" % (n,erroreuler,errorverlet))
    outfile.write(r"""
    \\ \bottomrule
    \end{array}\]""")
