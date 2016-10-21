NAVN = Johansson_Anders_FYS3150_Oblig3
FLAGG = -O3 -Wall -std=c++11
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex test.tex
	latexmk -f -pdf ${NAVN}.tex
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
cpp_ui.x: cpp_ui.o
	g++ ${FLAGG} -o cpp_ui.x cpp_ui.o planet.o vec3.o solarsystem.o
cpp_ui.o: cpp_ui.cpp solarsystem.o
	g++ -c ${FLAGG} cpp_ui.cpp
planet.o: planet.cpp planet.h vec3.o
	g++ -c ${FLAGG} planet.cpp
vec3.o: vec3.cpp vec3.h
	g++ -c ${FLAGG} vec3.cpp
test.dat: cpp_ui.x
	./cpp_ui.x "test.dat" "euler" 0 0.99 1000000 "sun" 1.0 0 0 0 0 0 0 "earth" 0.000003 1.0 0 0 0 6.28 0 > out.dat
test.tex: test.dat test.gpi
	gnuplot test.gpi
solarsystem.o: solarsystem.cpp solarsystem.h planet.o vec3.o
	g++ -c ${FLAGG} solarsystem.cpp
clean:
	latexmk -c
	rm *.bbl *.run.xml
	rm *.o
	rm *.dat *.eps *-converted-to.pdf plot*.tex *.txt *.run.xml
