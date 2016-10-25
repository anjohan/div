velocities=( 4 6.28 7 8.8 8.9 10 )
n=100000000
for v in ${velocities[*]}; do
    python python_ui.py -m verlet -f escape$v.dat -tn 200 -n $n -dn $[ $n/10000 ] -s -b earth 3E-6 1 0 0 0 $v 0 &
done
wait
