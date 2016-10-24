outfile=error.dat
if [ -f $outfile ]; then
    rm $outfile
fi
touch $outfile
for i in `seq $1 $2`; do
    n=$[10**$i]
    python python_ui.py -m euler -f euler$n.dat -tn 1 -n $n -dn $n -s -b earth 3E-6 1 0 0 0 6.28318530718 0 &
    python python_ui.py -m verlet -f verlet$n.dat -tn 1 -n $n -dn $n -s -b earth 3E-6 1 0 0 0 6.28318530718 0 &
done
wait
for i in `seq $1 $2`; do
    n=$[10**$i]
    sisteeuler=(`tail -n 2 euler$n.dat`)
    sisteverlet=(`tail -n 2 verlet$n.dat`)
    eulerx=${sisteeuler[7]}
    verletx=${sisteverlet[7]}
    eulery=${sisteeuler[8]}
    verlety=${sisteverlet[8]}
    echo $n $eulerx $eulery $verletx $verlety >> error.dat
done
