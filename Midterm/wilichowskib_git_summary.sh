#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm


#Store file path into variable
File_path=$1
#echo "$File_path"

#check if arguments inputted are 0<t<1
if [ "$#" -eq 0 ]; then 
	echo "You done messed up, Ben. I need more arguments"
elif [ "$#" -gt 1 ]; then
    echo "Bro, thats too many arguments"
fi

#printing out each file within the midterm folder
for entry in `ls $File_path`; do
    #echo $entry
    file1=$File_path/$entry
    echo $file1
done

