NAVN = Johansson_Anders_FYS3150_Oblig4
FLAGG = -Wall -std=c++11 -O3 -pthread
all: pdf
pdf: ${NAVN}.pdf
figs: 2by2.plt randomanalysis.plt accepted.plt probdist.plt 40atcondor.plt 40atcondorlong.plt 40with2E6.plt
${NAVN}.pdf: ${NAVN}.tex kilder.bib 40atcondor.dat 40atcondorlong.dat time.dat 40with2E6.dat figs
	latexmk -quiet -pdf ${NAVN}.tex
2by2.plt: multiplot.gpi cold2by2.dat time.dat
	gnuplot -e "outfile='2by2.plt'; infile='2by2.dat'; N=100000" multiplot.gpi
cold2by2.dat: 2by2.x time.dat
	./2by2.x
2by2.x: ising.o 2by2.o
	g++ ${FLAGG} -o 2by2.x 2by2.o ising.o
2by2.o: 2by2.cpp
	g++ ${FLAGG} -c 2by2.cpp
randomanalysis.plt: multiplot.gpi coldanalysis.dat plotanalysis.sh time.dat
	bash plotanalysis.sh
accepted.plt: accepted.gpi coldanalysis.dat time.dat
	gnuplot accepted.gpi
probdist.plt: probdist.gpi coldanalysis.dat time.dat
	gnuplot probdist.gpi
coldanalysis.dat: analysis.x time.dat
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
40atcondor.plt: plotphases.gpi time.dat
	gnuplot -e "infile='impdata/40Tsfrom2.2to2.4.imp'; outfile='40atcondor.plt'" plotphases.gpi
40atcondor.dat: findcritical.py time.dat
	python findcritical.py impdata/40Tsfrom2.2to2.4.imp 40atcondor.dat
40atcondorlong.plt: plotphases.gpi time.dat
	gnuplot -e "infile='impdata/condormedium.imp'; outfile='40atcondorlong.plt'" plotphases.gpi
40atcondorlong.dat: findcritical.py time.dat
	python findcritical.py impdata/condormedium.imp 40atcondorlong.dat
40with2E6.plt: plotphases.gpi time.dat
	gnuplot -e "infile='impdata/40with2E6.imp'; outfile='40with2E6.plt'" plotphases.gpi
40with2E6.dat: findcritical.py time.dat
	python findcritical.py impdata/40with2E6.imp 40with2E6.dat
time.dat: timetest.x
	./timetest.x
timetest.o: timetest.cpp
	g++ ${FLAGG} -c timetest.cpp
timetest.x: timetest.o ising.o
	g++ ${FLAGG} -o timetest.x timetest.o ising.o
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	vim Johansson_Anders_FYS3150_Oblig4.tex makefile *.bib *.cpp *.h *.gpi *.py
clean:
	latexmk -c
	rm *.bbl
	rm *.run.xml
	rm *.o
	rm *.plt
	rm *.dat *.eps *-converted-to.pdf
