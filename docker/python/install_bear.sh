mkdir Bear
git clone --depth 1 https://github.com/rizsotto/Bear.git ./Bear
cd Bear
cmake -DENABLE_UNIT_TESTS=OFF -DENABLE_FUNC_TESTS=OFF $BEAR_SOURCE_DIR
make all
make install
