import os
import sys
nstart = int(sys.argv[1])
nslutt = int(sys.argv[2])

with open("timetable.dat","w") as outfile:
    outfile.write(r"""
        \[\begin{array}{rrrr}\toprule
        \multicolumn{1}{c}{\text{Number of time steps}} & \multicolumn{1}{c}{\text{Euler time}} & \multicolumn{1}{c}{\text{Verlet time}} & \multicolumn{1}{c}{\text{Ratio}}""")
    for eksp in range(nstart,nslutt+1):
        n = 10**eksp
        os.system("""
        python python_ui.py -m euler -f eulertime.dat -tn 1 -n %d -dn %d -s -b earth 3E-6 1 0 0 0 6.28318530718 0
        python python_ui.py -m verlet -f verlettime.dat -tn 1 -n %d -dn %d -s -b earth 3E-6 1 0 0 0 6.28318530718 0
        """ % (n,n,n,n))
        with open("eulertime.dat","r") as infile:
            eulertime = float(infile.readlines()[-1].split()[-1])
        with open("verlettime.dat","r") as infile:
            verlettime = float(infile.readlines()[-1].split()[-1])
        outfile.write(r"""\\ \midrule
        \num{%d} & \SI{%.3g}{\second} & \SI{%.3g}{\second} & \num{%.3g}""" % (n,eulertime,verlettime,verlettime/eulertime))
    outfile.write(r"""
    \\ \bottomrule
    \end{array}\]""")
