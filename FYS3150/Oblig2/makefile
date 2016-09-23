NAVN = Johansson_Anders_FYS3150_Oblig2
FLAGG = -O3 -Wall
all: pdf
pdf: ${NAVN}.pdf
${NAVN}.pdf: ${NAVN}.tex ${NAVN}.bcf
	pdflatex -shell-escape ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
${NAVN}.bcf: kilder.bib ${NAVN}.tex
	pdflatex -shell-escape ${NAVN}.tex
	biber ${NAVN}
read: ${NAVN}.pdf
	evince ${NAVN}.pdf &
edit:
	gvim -p ${NAVN}.tex makefile *.cpp
clean:
	rm b.tex b_spesiell.tex *.log *.out *.aux *.o *.dat *.eps *-converted-to.pdf *.x *.toc *.bcf *.bbl *.blg *.run.xml
	rm -rf _minted-${NAVN}
