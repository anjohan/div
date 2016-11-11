NAVN = Johansson_Anders_FYS3150_Oblig4
FLAGG = -Wall -std=c++11 -O3 -pthread
all: pdf
pdf: ${NAVN}.pdf
figs: 2by2.plt
${NAVN}.pdf: ${NAVN}.tex kilder.bib figs
	latexmk -quiet -pdf ${NAVN}.tex
2by2.plt: 2by2.gpi 2by2.dat
	gnuplot 2by2.gpi
2by2.dat: 2by2.x
	./2by2.x
	tail -n 1 2by2long.dat > 2by2longres.dat
2by2.x: ising.o 2by2.o
	g++ ${FLAGG} -o 2by2.x 2by2.o ising.o
2by2.o: 2by2.cpp
	g++ ${FLAGG} -c 2by2.cpp
ising.o: ising.cpp ising.h
	g++ ${FLAGG} -c ising.cpp
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	vim Johansson_Anders_FYS3150_Oblig4.tex makefile *.bib *.cpp
clean:
	latexmk -c
	rm *.bbl
	rm *.run.xml
	rm *.o
	rm *.plt
	rm *.dat *.eps *-converted-to.pdf
