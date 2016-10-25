The pdf should be complete, so there is no need to do any compiling.

## To do everything:
```
make -j
```
Note that this will take forever (i.e. several minutes), as all simulations are rerun.

Dependencies:
* g++
* Python 2.7
* texlive with latexmk
* bash
* gnuplot 5.0

## User interface (only works for non-relativistic simulation)
### Example
```
python python_ui.py -m verlet -f earthsunverlet.dat -tn 1 -n 1000 -s -b earth 3E-6 1 0 0 0 6.28 0
```
Simulates for one year with 1000 data points, using the verlet method. Data is saved do earthsunverlet.dat.

The earth is set to begin at (1,0,0) with velocity (0,6.28,0), and a sun is placed such that the center of mass is in (0,0,0) and stationary.

### Documentation `python python_ui.py -h`
```
usage: python_ui.py [-h] [-f FILENAME] [-m {euler,verlet}] [-t0 T0] [-tn TN]
                    [-n N] [-dn DN] [--fixedsun] [-s]
                    [-b name masssolar masses x y z vx vy vz]

User-friendly interface for simulating the solar system.

optional arguments:
  -h, --help            show this help message and exit
  -f FILENAME, --filename FILENAME
                        Name of file in which to store calculated data.
  -m {euler,verlet}, --method {euler,verlet}
                        Numerical method to be used for simulation.
  -t0 T0, --initial_time T0
                        Start time for the simulation.
  -tn TN, --final_time TN
                        Final time for the simulation.
  -n N, --integration_points N
                        Number of integration points.
  -dn DN, --write_interval DN
                        Write data to file at every dn'th point.
  --fixedsun            Fix a sun at origo.
  -s, --sun             Add a sun with position and velocity such that the
                        center of mass is in origo and stationary (or fixed at
                        origo if --fixedsun is used).
  -b name mass(solar masses) x y z vx vy vz, --body name mass(solar masses) x y z vx vy vz
                        Add a body (one -b for each body).
```
