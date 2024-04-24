# Devoir-Linux
DevoirLinux


---------------APACHE-------------

Download apache tar.gz, apr, apr-util
extraire apr et apr-util dans ./srclib/
.configure --prefix=usr/local/apache2 --with-included-apr
make
make install




---------------MySql---------------

Donwload mysql tar.gz
tar -xzvf mysql.tar.gz
cd mysql
mkdir build
cd build
cmake ..
make
make install



-------------------PHP-------------------
Download php
tar -xzvf php.tar.gz
cd php
sudo apt install -y pkg-config build-essential autoconf bison re2c \
                        libxml2-dev libsqlite3-dev
./buildconf
./configure
make
sudo make install
