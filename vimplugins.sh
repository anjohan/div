set -e -x
cd ~
wget https://raw.githubusercontent.com/Valloric/ycmd/master/cpp/ycm/.ycm_extra_conf.py -O ~/.ycm_extra_conf.py


sudo pacman -Syu clang

mkdir ~/.vim
cd ~/.vim
mkdir pack
cd pack
mkdir my-plugins
cd my-plugins
mkdir start
cd start
git clone https://github.com/Valloric/YouCompleteMe.git
cd YouCompleteMe
git submodule update --init --recursive
./install.py --clang-completer --system-libclang
cd ..
git clone https://github.com/scrooloose/syntastic.git
git clone https://github.com/majutsushi/tagbar.git
git clone https://github.com/airblade/vim-gitgutter.git
git clone https://github.com/vim-airline/vim-airline.git
