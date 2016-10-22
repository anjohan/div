for i in `seq $1 $2`; do
    n=$[10**$i]
touch error.dat
    python python_ui.py -m euler -f euler$n.dat -tn 1 -n $n -dn $n -b sun 1 0 0 0 0 0 0 -b earth 3E-6 1 0 0 0 6.28318530718 0 &
    python python_ui.py -m verlet -f verlet$n.dat -tn 1 -n $n -dn $n -b sun 1 0 0 0 0 0 0 -b earth 3E-6 1 0 0 0 6.28318530718 0 &
done
wait
for i in `seq $1 $2`; do
    n=$[10**$i]
    sisteeuler=(`tail -n 1 euler$n.dat`)
    sisteverlet=(`tail -n 1 verlet$n.dat`)
    eulerx=${sisteeuler[7]}
    verletx=${sisteverlet[7]}
    eulery=${sisteeuler[8]}
    verlety=${sisteverlet[8]}
    echo $n $eulerx $eulery $verletx $verlety >> error.dat
done
rm euler*.dat
rm verlet*.dat
