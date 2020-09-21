set -e -x
cd ~


#sudo apt install -y clang
sudo pacman -Syu clang

mkdir ~/.vim
cd ~/.vim
mkdir pack
cd pack
mkdir my-plugins
cd my-plugins
mkdir start
cd start
git clone https://github.com/maralla/completor.vim.git
git clone https://github.com/w0rp/ale.git
git clone https://github.com/majutsushi/tagbar.git
git clone https://github.com/airblade/vim-gitgutter.git
git clone https://github.com/vim-airline/vim-airline.git
