#POST-DELIVERY UPDATE 2#
It turns out that I had only found one bug - after a new 60-hour run on HTCondor, the results are still weird (the expectation value of the absolute value of M is still negative). This is extremely depressing. As the results are correct for smaller values of L and N, the cause is probably still an overflow somewhere. Unfortunately, I do not currently have time to fix this issue.

#POST-DELIVERY UPDATE#
I found the bug which caused the errors in the large datasets for phase transitions. It turns out I had forgotten to change abs to fabs when I changed all the quantities from ints to doubles, causing an overflow in the energy and magnetic moment when the grid is large.

The new results will be added to the report as an appendix once the long runs are finished.

#FYS3150 Project 4#

##The report##
See `Johansson_Anders_FYS3150_Oblig4.pdf`.

Make the report using `make -j` (will take a few minutes).

##File structure##
See also `makefile`.

The main implementation is found in `ising.cpp` and `ising.h`. These files contain a function `ising` which sets everything up and runs the simulation while writing data to a specified file.

`multiplot.gpi` is a utility to plot the energy expectation value, heat capacity, magnetisation and magnetic susceptibility using gnuplot, see `plotanalysis.sh` for usage.

`plotphases.gpi` is used to plot the data from `phases.gpi`.

`2by2.cpp` runs the 2x2 simulation (in parallel using `<thread`).

`analysis.cpp` runs the 20x20 simulations (in parallel using `<thread>`).

`phases.cpp` is used to study the phase transitions (in parallel using `<thread>`).

`findcritical.py` analyses the data from a run of `phases.cpp`.

The `.imp` files are results of heavy simulations.
