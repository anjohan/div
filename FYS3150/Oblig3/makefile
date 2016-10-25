NAVN = Johansson_Anders_FYS3150_Oblig3
FLAGG = -O3 -Wall -std=c++11
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex earthsun.plt error.plt timetable.dat earthsunverlettest.dat earthsuneulertest.dat threebody.plt realthreebody.plt everything.plt perihelion.plt gitlog.pdf escape.plt
	latexmk -quiet -pdf ${NAVN}.tex
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
cpp_ui.x: cpp_ui.o
	g++ ${FLAGG} -o cpp_ui.x cpp_ui.o planet.o solarsystem.o
cpp_ui.o: cpp_ui.cpp solarsystem.o
	g++ -c ${FLAGG} cpp_ui.cpp
planet.o: planet.cpp planet.h
	g++ -c ${FLAGG} planet.cpp
solarsystem.o: solarsystem.cpp solarsystem.h planet.o
	g++ -c ${FLAGG} solarsystem.cpp
earthsun.plt: earthsuneuler.dat earthsunverlet.dat python_ui.py earthsun.gpi
	gnuplot earthsun.gpi
earthsuneuler.dat eartnsunverlet.dat: earthsun.sh cpp_ui.x python_ui.py
	./earthsun.sh
earthsuneulertest.dat: conservation.py earthsuneuler.dat
	python conservation.py earthsuneuler.dat > earthsuneulertest.dat
earthsunverlettest.dat: conservation.py earthsunverlet.dat
	python conservation.py earthsunverlet.dat > earthsunverlettest.dat
error.plt: error.dat error.gpi
	gnuplot error.gpi
error.dat: errorearthsun.sh cpp_ui.x
	bash errorearthsun.sh 2 7
timetable.dat: cpp_ui.x python_ui.py timetable.py
	python timetable.py 2 8
threebody.plt: threebody1.dat threebody.gpi
	gnuplot threebody.gpi
threebody1.dat: threebody.sh cpp_ui.x python_ui.py
	bash threebody.sh
realthreebody.plt: realthreebody.dat realthreebody.gpi
	gnuplot realthreebody.gpi
realthreebody.dat: realthreebody.sh cpp_ui.x python_ui.py
	bash realthreebody.sh
everything.plt: everything.dat everything.gpi
	gnuplot everything.gpi
everything.dat: everything.sh cpp_ui.x python_ui.py
	bash everything.sh
perihelion.plt: perihelion.gpi mercuryclassicperihelion.dat
	gnuplot perihelion.gpi
mercuryclassicperihelion.dat: perihelion.x
	./perihelion.x
perihelion.x: perihelion.cpp planet.o solarsystem.o
	g++ -o perihelion.x ${FLAGG} perihelion.cpp planet.o solarsystem.o
gitlog.pdf: ../github_activity.py
	python ../github_activity.py -d .. -o Oblig3/gitlog.pdf
escape.plt: escape.gpi escape4.dat
	gnuplot escape.gpi
escape4.dat: escape.sh python_ui.py cpp_ui.x
	bash escape.sh
edit:
	vim Johansson_Anders_FYS3150_Oblig3.tex makefile *.gpi *.sh *.h *.cpp *.py
clean:
	latexmk -c
	rm *.o *.x
	rm *.bbl
	rm *.run.xml
	rm *.plt gitlog.pdf
	rm *.dat *.eps *-converted-to.pdf
