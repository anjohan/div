NAVN = Johansson_Anders_FYS3150_Oblig2
FLAGG = -O3 -Wall -std=c++11
all: pdf enpartikkel.x
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex plot1.tex plot2.tex
	latexmk -silent -shell-escape -pdf ${NAVN}.tex
enpartikkel.x: enpartikkel.o funksjoner.o schrodinger.o jacobi.o Potensial.o
	g++ -o enpartikkel.x enpartikkel.o funksjoner.o schrodinger.o jacobi.o Potensial.o
enpartikkel.o: enpartikkel.cpp
	g++ -c ${FLAGG} enpartikkel.cpp
funksjoner.o: funksjoner.cpp funksjoner.h
	g++ -c ${FLAGG} funksjoner.cpp
schrodinger.o: schrodinger.cpp schrodinger.h
	g++ -c ${FLAGG} schrodinger.cpp
jacobi.o: jacobi.cpp jacobi.h
	g++ -c ${FLAGG} jacobi.cpp
Potensial.o: Potensial.cpp Potensial.h
	g++ -c ${FLAGG} Potensial.cpp
PotensialUtenInteraksjon.o: PotensialUtenInteraksjon.cpp PotensialUtenInteraksjon.h
	g++ -c ${FLAGG} PotensialUtenInteraksjon.cpp
PotensialMedInteraksjon.o: PotensialMedInteraksjon.cpp PotensialMedInteraksjon.h
	g++ -c ${FLAGG} PotensialMedInteraksjon.cpp
topartikler.x: topartikler.o PotensialMedInteraksjon.o PotensialUtenInteraksjon.o Potensial.o schrodinger.o jacobi.o funksjoner.o
	g++ -o topartikler.x topartikler.o PotensialMedInteraksjon.o PotensialUtenInteraksjon.o Potensial.o schrodinger.o jacobi.o funksjoner.o
topartikler.o: topartikler.cpp
	g++ -c ${FLAGG} topartikler.cpp
test.x: test.o funksjoner.o jacobi.o
	g++ -o test.x test.o funksjoner.o jacobi.o
test.o: test.cpp
	g++ -c ${FLAGG} test.cpp
plot1.tex: plot.gpi nlik250.dat
	gnuplot plot.gpi
plot2.tex: plotto.gpi omegamed5.00.dat
	gnuplot plotto.gpi
omegamed5.00.dat: topartikler.x
	./topartikler.x
nlik250.dat: enpartikkel.x
	time ./enpartikkel.x
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
clean:
	latexmk -c
	rm *.bbl *.o *.x
	rm -rf _minted-${NAVN}
	rm *.dat *.eps *-converted-to.pdf *.h.gch plot*.tex
