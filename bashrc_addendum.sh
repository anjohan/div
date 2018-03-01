alias o='rifle'
vann='abel:/work/users/anderhaf/anjohan/ccse2017/vannlag'
nano='abel:/work/users/anderhaf/anjohan/nanopillarer'
usc='usc:/staging/pv/ankitmis/Anders/nanopillarer'
fram='fram:/cluster/work/users/anderhaf/anjohan/nanopillarer'
alias atomify='/home/anders/atomify/build/src/atomify'
alias i3lock='i3lock -c 000000'

function t {
    nohup xfce4-terminal --hide-toolbar --hide-menubar --hide-scrollbar &> /dev/null & disown
}
export -f t

PATH=$PATH:~/Downloads/ovito-3.0.0-dev60-x86_64/bin
PATH=$PATH:~/Downloads/packmol:~/google
PATH=$PATH:~/Downloads/lammps/src
export PATH

LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Downloads/lammps/src
export LD_LIBRARY_PATH

PYTHONPATH=$PYTHONPATH:~/Downloads/lammps/tools/python/pizza:~/Downloads/ovito-3.0.0-dev60-x86_64/lib/ovito/plugins/python
PYTHONPATH=$PYTHONPATH:~/Downloads/lammps/python:~/fys4460-1
export PYTHONPATH

function ap {
    for fil in $(ls *.py)
    do
        echo "===================="
        echo $fil
        python $fil
        echo "===================="
    done
    read
}
export -f ap

function skrivut {
    # Krever:
    # - Kunne logge inn på ifi med 'ssh ifi' uten passord.
    #   - Legg til i .ssh/config:
    #       Host ifi
    #           HostName login.ifi.uio.no
    #           User brukernavn
    #   - Generer ssh-nøkkel: ssh-keygen (trykk enter mange ganger).
    #   - ssh-copy-id ifi
    # - Mappe ~/utskrift på ifi.
    # - Fil ~/utskrift.smb på ifi med innhold
    #       username=brukernavn
    #       password=passord
    # Bruk:
    #       skrivut FILNAVN [ARGUMENTER, se 'man pushprint' på ifi]
    # Eksempel (skrive ut ~/repo/report.pdf på CompPhys-printeren):
    #       skrivut ~/repo/report.pdf -P fys4
    fil=$1
    filnavn=$(basename $fil)
    shift
    scp $fil ifi:utskrift/
    ssh ifi pushprint $@ -A utskrift/.smb utskrift/$filnavn
}
export -f skrivut
