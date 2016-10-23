masses=(0.001 0.01 1)
for m_jupiter in ${masses[*]}; do
    python python_ui.py -f threebody$m_jupiter.dat --fixedsun -tn 15 -n 100000000 -dn 10000 -b earth 3E-6 1 0 0 0 6.28 0 -b jupiter $m_jupiter 0 5.204 0 -2.77 0 0 &
done
wait
