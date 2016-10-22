# Offentlig

```
usage: python_ui.py [-h] [-f FILENAME] [-m {euler,verlet}] [-t0 T0] [-tn TN]
                    [-n N] [-dn DN] [-s]
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
  -s, --sun             Add a sun with position and velocity such that the
                        center of mass is in origo and stationary.
  -b name mass(solar masses) x y z vx vy vz, --body name mass(solar masses) x y z vx vy vz
                        Add a body (one -b for each body).
```
