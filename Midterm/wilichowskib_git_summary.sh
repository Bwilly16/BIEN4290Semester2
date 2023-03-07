#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm

#remove folder each run 
rm -rf MidtermData 

#Make folder
mkdir MidtermData

#copy contents
cp -r $1 ./MidtermData

#Store file path into variable
File_path=$1
#echo "$File_path"

#check if arguments inputted are 0<t<1
if [ "$#" -eq 0 ]; then 
	echo "You done messed up, Ben. I need more arguments"
elif [ "$#" -gt 1 ]; then
    echo "Bro, thats too many arguments"
fi

c=0
for file in $(ls ./MidtermData/midterm2023/)
do
	#echo "Looking at $file..." 
    list[$c]=$file
    c=$(expr $c + 1)
    
done

for i in $list
do
    echo ${list[*]}
    Total=./MidtermData/midterm2023/${list[2]} | git rev-list --all --count
    echo $Total
    
done




