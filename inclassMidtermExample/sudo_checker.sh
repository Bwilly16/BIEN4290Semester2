#!/bin/bash

rm -rf ./authdata #this kind of thing gets those last ~8 pts
mkdir authdata

cp /var/log/auth.log* ./authdata/

gzip -dk ./authdata/*.gz #unzips them all

rm ./authdata/*.gz

for file in $(ls ./authdata) #goes through each file in the directory
do
    echo "parsing $file..."
    cat ./authdata/${file} | grep "user NOT in sudoers" | cut -f4 -d: | uniq |xargs #removes white space from user name and only prints out unique users
done





