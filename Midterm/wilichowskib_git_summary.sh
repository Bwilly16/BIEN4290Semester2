#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm


#Store file path into variable
File_path=$1
echo "$File_path"
echo " "

#check if arguments inputted are 0<t<1
if [ "$#" -eq 0 ]; then 
	echo "You done messed up, Ben. I need more arguments"
elif [ "$#" -gt 1 ]; then
    echo "Bro, thats too many arguments"
fi

c=0
for file in $(ls $File_path)
do
	echo "Looking at $file..." 
    
    
done




