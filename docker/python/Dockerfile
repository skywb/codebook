FROM mirrors.tencent.com/todacc/tlinux3.1-64bit-gcc8.3.1:0.1.0
MAINTAINER skyrwang

workdir /tmp

RUN yum install -y cmake nodejs python2 python3 python3-devel git
RUN yum remove -y vim

# install vim8.2
COPY ./install_vim.sh ./
RUN  sh install_vim.sh 

# init terminal 256 color
copy bashrc bashrc
run cat bashrc >> ~/.bashrc

copy install_vim_config.sh ./
RUN bash install_vim_config.sh

RUN yum remove nodejs -y
RUN yum install npm -y
RUN npm install -g n
RUN n latest 
RUN npm uninstall n -y

run wget https://github.com/clangd/clangd/releases/download/snapshot_20211205/clangd-linux-snapshot_20211205.zip
run unzip clangd-linux-snapshot_20211205.zip
run cp clangd_snapshot_20211205/bin/clangd /usr/local/bin/

RUN vim +PlugInstall -c "qa"

# clean
run rm -rf /tmp/*

