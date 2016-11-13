#FYS3150 Project 4#

##The report##
See `Johansson_Anders_FYS3150_Oblig4.pdf`.

Make the report using `make -j`.

##File structure##
The main implementation is found in `ising.cpp` and `ising.h`. These files contain a function `ising` which sets everything up and runs the simulation while writing data to a specified file.

`multiplot.gpi` is a utility to plot the energy expectation value, heat capacity, magnetisation and magnetic susceptibility using gnuplot, see `plotanalysis.sh` for usage.

`2by2.cpp` runs the 2x2 simulation (in parallel using `<thread`).

`analysis.cpp` runs the 20x20 simulations (in parallel using `<thread>`).
