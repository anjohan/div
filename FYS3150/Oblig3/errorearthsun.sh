n=10
touch error.dat
while [ $n -lt 1000001 ]; do
    python python_ui.py -m euler -f euler$n.dat -tn 1 -n $n -s -b earth 3E-6 1 0 0 0 6.28318530718 0
    python python_ui.py -m verlet -f verlet$n.dat -tn 1 -n $n -s -b earth 3E-6 1 0 0 0 6.28318530718 0
    sisteeuler=(`tail -n 1 euler$n.dat`)
    sisteverlet=(`tail -n 1 verlet$n.dat`)
    eulerx=${sisteeuler[7]}
    verletx=${sisteverlet[7]}
    eulery=${sisteeuler[8]}
    verlety=${sisteverlet[8]}
    echo $eulerx $eulery $verletx $verlety >> error.dat
    n=$[$n*10]
done
rm euler*.dat
rm verlet*.dat
