set -e -x
cd ~
wget https://github.com/Valloric/ycmd/blob/master/cpp/ycm/.ycm_extra_conf.py

cd .vim
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
