NAVN = Johansson_Anders_FYS3150_Oblig3
FLAGG = -O3 -Wall -std=c++11
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex
	latexmk -f -pdf ${NAVN}.tex
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
clean:
	latexmk -c
	rm *.bbl *.run.xml
	#rm *.dat *.eps *-converted-to.pdf plot*.tex *.txt *.run.xml
