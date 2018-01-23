#
# ~/.bashrc
#

# If not running interactively, don't do anything
[[ $- != *i* ]] && return

alias o='rifle'
vann='abel:/work/users/anderhaf/anjohan/ccse2017/vannlag'
nano='abel:/work/users/anderhaf/anjohan/nanopillarer'
usc='usc:/staging/pv/ankitmis/Anders/nanopillarer'
fram='fram:/cluster/work/users/anderhaf/anjohan/nanopillarer'
alias atomify='/home/anders/atomify/build/src/atomify'

function t {
    nohup xfce4-terminal --hide-toolbar --hide-menubar --hide-scrollbar &> /dev/null & disown
}
export -f t

PATH=$PATH:~/Downloads/ovito-3.0.0-dev60-x86_64/bin
PATH=$PATH:~/Downloads/packmol
PYTHONPATH=$PYTHONPATH:~/Downloads/ovito-3.0.0-dev60-x86_64/lib/ovito/plugins/python

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


alias ls='ls --color=auto'
PS1='[\u@\h \W]\$ '
# >>> BEGIN ADDED BY CNCHI INSTALLER
BROWSER=/usr/bin/firefox
EDITOR=/usr/bin/vim
# <<< END ADDED BY CNCHI INSTALLER
