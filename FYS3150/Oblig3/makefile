NAVN = Johansson_Anders_FYS3150_Oblig3
FLAGG = -O3 -Wall -std=c++11
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex earthsun.tex
	latexmk -quiet -pdf ${NAVN}.tex
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
cpp_ui.x: cpp_ui.o
	g++ ${FLAGG} -o cpp_ui.x cpp_ui.o planet.o solarsystem.o
cpp_ui.o: cpp_ui.cpp solarsystem.o
	g++ -c ${FLAGG} cpp_ui.cpp
planet.o: planet.cpp planet.h
	g++ -c ${FLAGG} planet.cpp
solarsystem.o: solarsystem.cpp solarsystem.h planet.o
	g++ -c ${FLAGG} solarsystem.cpp
vec.o: vec.cpp vec.h
	g++ -c ${FLAGG} vec.cpp
earthsun.tex: earthsuneuler.dat earthsunverlet.dat python_ui.py
	gnuplot earthsun.gpi
earthsuneuler.dat eartnsunverlet.dat: earthsun.sh cpp_ui.x python_ui.py
	./earthsun.sh
clean:
	latexmk -c
	rm *.o *.x
	rm *.bbl
	rm *.run.xml
	rm *.dat *.eps *-converted-to.pdf
