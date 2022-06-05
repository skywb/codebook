cd ~
rm -rf .vim 
mkdir .vim
git clone --depth 1 https://github.com/skywb/vim-config.git ./.vim
ln -s .vim/vimrc ./.vimrc

