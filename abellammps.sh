module load intel
module load intelmpi.intel
git clone https://github.com/lammps/lammps
cd lammps/src
make yes-user-intel
rm compute_hexorder_atom.cpp
rm compute_hexorder_atom.h
make -j16 intel_cpu_intelmpi  
