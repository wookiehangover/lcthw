#! /bin/bash

cd /tmp

curl -L -O http://download.nextag.com/apache//apr/apr-1.4.5.tar.gz

tar -xzvf apr-1.4.5.tar.gz
cd apr-1.4.5

./configure
make
sudo make install

cd /tmp
rm -rf apr-1.4.5 arp-1.4.5.tar.gz

curl -L -O http://download.nextag.com/apache//apr/apr-util-1.3.12.tar.gz

tar -xzvf apr-util-1.3.12.tar.gz
cd apr-util-1.3.12

./configure --with-apr=/usr/local/apr

make
sudo make install

cd /tmp
rm -rf apr-utl-1.3.12* apr-1.4.5*
