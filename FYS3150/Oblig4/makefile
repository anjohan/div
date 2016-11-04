NAVN = Johansson_Anders_FYS3150_Oblig4
FLAGG = -O3 -Wall -std=c++11
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex kilder.bib
	latexmk -quiet -pdf ${NAVN}.tex
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
