import sys

infilename = sys.argv[1]
outfilename = sys.argv[2]

with open(infilename,"r") as infile:
    lines = infile.readlines()

Ls = []
for word in lines[0].split(" ")[1:17:4]:
    Ls.append(int(word.split("=")[1][:-1]))


chis = []
for i in range(4):
    chis.append([])

Ts = []

for line in lines[1:]:
    words = line.split()
    Ts.append(float(words[0]))
    for i in range(4):
        chis[i].append(float(words[4+i*4]))

with open(outfilename,"w") as outfile:
    outfile.write(r"\[\begin{array}{cc}\toprule L & \chi ")
    for i in range(4):
        L = Ls[i]
        T_C = Ts[chis[i].index(max(chis[i]))]
        outfile.write(r"\\ \midrule \num{%d} & \num{%g} " % (L,T_C))
    outfile.write(r"\\ \bottomrule\end{array}\]")
