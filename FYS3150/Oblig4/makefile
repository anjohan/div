NAVN = Johansson_Anders_FYS3150_Oblig4
FLAGG = -Wall -std=c++11 -O3 -pthread
all: pdf
pdf: ${NAVN}.pdf
figs: 2by2.plt randomanalysis.plt accepted.plt probdist.plt
${NAVN}.pdf: ${NAVN}.tex kilder.bib figs
	latexmk -quiet -pdf ${NAVN}.tex
2by2.plt: multiplot.gpi cold2by2.dat
	gnuplot -e "outfile='2by2.plt'; infile='2by2.dat'; N=100000" multiplot.gpi
cold2by2.dat: 2by2.x
	./2by2.x
2by2.x: ising.o 2by2.o
	g++ ${FLAGG} -o 2by2.x 2by2.o ising.o
2by2.o: 2by2.cpp
	g++ ${FLAGG} -c 2by2.cpp
randomanalysis.plt: multiplot.gpi coldanalysis.dat plotanalysis.sh
	bash plotanalysis.sh
accepted.plt: accepted.gpi coldanalysis.dat
	gnuplot accepted.gpi
probdist.plt: probdist.gpi coldanalysis.dat
	gnuplot probdist.gpi
coldanalysis.dat: analysis.x
	./analysis.x
analysis.x: analysis.o ising.o
	g++ ${FLAGG} -o analysis.x analysis.o ising.o
analysis.o: analysis.cpp
	g++ ${FLAGG} -c analysis.cpp
ising.o: ising.cpp ising.h
	g++ ${FLAGG} -c ising.cpp
phases.o: phases.cpp
	g++ ${FLAGG} -c phases.cpp
phases.x: phases.o ising.o
	g++ ${FLAGG} -o phases.x phases.o ising.o
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	vim Johansson_Anders_FYS3150_Oblig4.tex makefile *.bib *.cpp *.h *.gpi
clean:
	latexmk -c
	rm *.bbl
	rm *.run.xml
	rm *.o
	rm *.plt
	rm *.dat *.eps *-converted-to.pdf
