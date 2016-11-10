NAVN = Johansson_Anders_FYS3150_Oblig4
FLAGG = -Wall -std=c++11 -g
all: pdf ising.x
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex kilder.bib
	latexmk -quiet -pdf ${NAVN}.tex
ising.x: ising.cpp
	g++ ${FLAGG} -o ising.x ising.cpp
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	vim Johansson_Anders_FYS3150_Oblig4.tex makefile *.bib
clean:
	latexmk -c
	rm *.bbl
	rm *.run.xml
	#rm *.o *.x
	#rm *.plt
	#rm *.dat *.eps *-converted-to.pdf
