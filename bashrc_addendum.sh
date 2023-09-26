alias o='rifle'
vann='abel:/work/users/anderhaf/anjohan/ccse2017/vannlag'
nano='abel:/work/users/anderhaf/anjohan/nanopillarer'
usc='usc:/staging/pv/ankitmis/Anders/nanopillarer'
fram='fram:/cluster/work/users/anderhaf/anjohan/nanopillarer'
alias atomify='/home/anders/atomify/build/src/atomify'
alias i3lock='i3lock -c 000000'
alias scrot='scrot -o -s -q 100 --freeze -z'

function scs {
    rm -rf /tmp/screenshot.*
    scrot -o -s -q 100 --freeze -z /tmp/screenshot.png
    xclip -selection clipboard -t image/png -i /tmp/screenshot.png
    convert /tmp/screenshot.png -quality 80 /tmp/screenshot.jpg
}


function t {
    nohup xfce4-terminal --hide-toolbar --hide-menubar --hide-scrollbar &> /dev/null & disown
}
export -f t

PATH=$PATH:$HOME/Downloads/ovito-basic-3.4.4-x86_64/bin:/home/anders/Downloads/ovito-pro-3.0.0-dev750-x86_64/bin
PATH=$PATH:~/Downloads/packmol:~/google
PATH=$PATH:~/Downloads/lammps/build:~/Downloads/mdtools
PATH=~/.local/bin:$PATH
export PATH

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/Downloads/lammps/src
#export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/miniconda3/lib # messes with ovito
export LD_LIBRARY_PATH=~/.local/lib:$LD_LIBRARY_PATH

PYTHONPATH=$PYTHONPATH:~/Downloads/lammps/tools/python/pizza:~/Downloads/ovito-3.0.0-dev606-x86_64/lib/ovito/plugins/python
PYTHONPATH=$PYTHONPATH:~/Downloads/mdtools
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

function fo {
    rifle $(find -name "$1" 2> /dev/null)
}
export -f fo

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

function _update_ps1() {
    PS1="$($HOME/Downloads/powerline-go-linux-amd64 -modules 'cwd,perms,git,jobs,exit,root' -error $?)"
    # VTE_PWD_THING="$(__vte_osc7)"
    # PS1="$PS1$VTE_PWD_THING"
}

if [ "$TERM" != "linux" ] && [ -f "$HOME/Downloads/powerline-go-linux-amd64" ]; then
	PROMPT_COMMAND="_update_ps1; $PROMPT_COMMAND"
fi

function brightness {
	max=$(sudo cat /sys/class/backlight/intel_backlight/max_brightness)
	frac=$1
	new=$(python -c "print(int($max*$frac))")
	sudo echo $new > /sys/class/backlight/intel_backlight/brightness
}
