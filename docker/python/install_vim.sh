git clone --depth 1 -b v8.2.1052 https://github.com/vim/vim.git
# 到vim目录下
cd vim
./configure --with-features=huge \
  --enable-multibyte \
  --enable-pythoninterp \
  --enable-python3interp \
  --with-python-config-dir=/usr/lib64/python2.7/config/ \
  --with-python3-config-dir=/usr/lib64/python3.6/config-3.6m-x86_64-linux-gnu \
  --prefix=/usr/local/

make -j
make install

