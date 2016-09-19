NAVN = Johansson_Anders_FYS3150_Oblig1
FLAGG = -O3 -Wall
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex b.tex b_spesiell.tex c.dat e.dat ${NAVN}.bcf forside.pdf
	pdflatex -shell-escape ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
${NAVN}.bcf: kilder.bib ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
	biber ${NAVN}
b.tex b_spesiell.tex: b.gpi generell10.dat
	gnuplot b.gpi
generell10.dat: b.x
	./b.x
b.x: b.o generell.o felles.o spesiell.o
	g++ -o b.x felles.o generell.o b.o spesiell.o
b.o: b.cpp
	g++ -c ${FLAGG} b.cpp
c.dat: c.x
	./c.x
c.x: c.o generell.o felles.o spesiell.o
	g++ -o c.x felles.o generell.o spesiell.o c.o
c.o: c.cpp
	g++ -c ${FLAGG} c.cpp
e.dat: e.x
	./e.x
e.x: e.o felles.o spesiell.o
	g++ -o e.x felles.o spesiell.o e.o -larmadillo -llapack -lblas
e.o: e.cpp
	g++ -c ${FLAGG} e.cpp
generell.o: generell.cpp
	g++ -c ${FLAGG} generell.cpp
felles.o: felles.cpp
	g++ -c ${FLAGG} felles.cpp
spesiell.o: spesiell.cpp
	g++ -c ${FLAGG} spesiell.cpp
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
clean:
	rm b.tex b_spesiell.tex *.log *.out *.aux *.o *.dat *.eps *-converted-to.pdf *.x *.toc *.bcf *.bbl *.blg *.run.xml
	rm -rf _minted-Johansson_Anders_FYS3150_Oblig1
