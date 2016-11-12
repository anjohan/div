gnuplot -e "outfile='randomanalysis.plt'; infile='analysis.dat'; N=1000000" multiplot.gpi &
gnuplot -e "outfile='orderedanalysis.plt'; infile='orderedanalysis.dat'; N=1000000" multiplot.gpi &
wait
