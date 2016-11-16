import sys

infilename = sys.argv[1]
outfilename = sys.argv[2]

with open(infilename,"r") as infile:
    lines = infile.readlines()

Ls = []
for word in lines[0].split(" ")[1:17:4]:
    Ls.append(int(word.split("=")[1][:-1]))


chis = []
C_Vs = []
for i in range(4):
    chis.append([])
    C_Vs.append([])

Ts = []

for line in lines[1:]:
    words = line.split()
    Ts.append(float(words[0]))
    for i in range(4):
        chis[i].append(float(words[4+i*4]))
        C_Vs[i].append(float(words[2+i*4]))

T_Cs = []

with open(outfilename,"w") as outfile:
    outfile.write(r"\[\begin{array}{cc}\toprule L & T_C ")
    for i in range(4):
        L = Ls[i]
        #T_C = Ts[chis[i].index(max(chis[i]))]
        T_C = Ts[C_Vs[i].index(max(C_Vs[i]))]
        T_Cs.append(T_C)
        outfile.write(r"\\ \midrule \num{%d} & \num{%g} " % (L,T_C))
    outfile.write(r"\\ \bottomrule\end{array}\]" + "\n")

    # Find approximation to T_C(L=inf):
    nu = 1.0
    T_C_inf = 0
    for i in range(4):
        for j in range(4):
            if not i == j:
                T_C_inf += (1.0/12) * (T_Cs[i] - (T_Cs[i] - T_Cs[j])/(Ls[i]**(-1/nu) - Ls[j]**(-1/nu)) *Ls[i]**(-1/nu))

    outfile.write(r"Approximation to the thermodynamic limit: \[T_C(L=\infty) = \num{%g}\]" % T_C_inf)
