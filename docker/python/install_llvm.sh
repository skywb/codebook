mkdir llvm_src
cd llvm_src
wget  https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/llvm-13.0.0.src.tar.xz
mkdir llvm
tar xf ../llvm-13.0.0.src.tar.xz --strip-components 1 -C llvm/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/clang-13.0.0.src.tar.xz
mkdir clang
tar xf ../clang-13.0.0.src.tar.xz --strip-components 1 -C clang/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/libcxx-13.0.0.src.tar.xz
mkdir libcxx
tar xf ../libcxx-13.0.0.src.tar.xz --strip-components 1 -C libcxx/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/libcxxabi-13.0.0.src.tar.xz
mkdir libcxxabi
tar xf ../libcxxabi-13.0.0.src.tar.xz --strip-components 1 -C libcxxabi/
wget https://github.com/llvm/llvm-project/releases/download/llvmorg-13.0.0/clang-tools-extra-13.0.0.src.tar.xz
mkdir clang-tools-extra
tar xf ../clang-tools-extra-13.0.0.src.tar.xz --strip-components 1 -C clang-tools-extra/

# build
mkdir Release
cd Release
cmake ../llvm -DCMAKE_BUILD_TYPE=Release -DLLVM_ENABLE_PROJECTS="clang;libcxx;libcxxabi;clang-tools-extra;"
make -j$(nproc)
make install
# delete tmp and src files
cd ..
rm -rf llvm_src
