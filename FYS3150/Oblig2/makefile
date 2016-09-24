NAVN = Johansson_Anders_FYS3150_Oblig2
FLAGG = -O3 -Wall -std=c++11
all: pdf uteninteraksjon.x
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex ${NAVN}.bcf
	pdflatex -shell-escape ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
${NAVN}.bcf: kilder.bib ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
	biber ${NAVN}
uteninteraksjon.x: uteninteraksjon.o funksjoner.o schrodinger.o jacobi.o
	g++ -o uteninteraksjon.x uteninteraksjon.o funksjoner.o schrodinger.o jacobi.o
uteninteraksjon.o: uteninteraksjon.cpp
	g++ -c ${FLAGG} uteninteraksjon.cpp
funksjoner.o: funksjoner.cpp funksjoner.h
	g++ -c ${FLAGG} funksjoner.cpp
schrodinger.o: schrodinger.cpp schrodinger.h
	g++ -c ${FLAGG} schrodinger.cpp
jacobi.o: jacobi.cpp jacobi.h
	g++ -c ${FLAGG} jacobi.cpp
test.x: test.o funksjoner.o jacobi.o
	g++ -o test.x test.o funksjoner.o jacobi.o
test.o: test.cpp
	g++ -c ${FLAGG} test.cpp
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
clean:
	rm *.log *.out *.aux *.o *.x *.toc *.bcf *.bbl *.blg *.run.xml
	rm -rf _minted-${NAVN}
	rm *.dat *.eps *-converted-to.pdf
