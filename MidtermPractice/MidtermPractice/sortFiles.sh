#!/bin/bash
#Author: Ben Wilichowski
#Date: 2/28/2023
#Purpose: Practice Midterm 2023

#take in command line argument for number of files
echo "Script Name: $0"
echo "$# arguments"

if [ "$#" -eq 0 ]; then 
	echo "You done messed up, Ben. I need more arguments"
else
	list=( "$@" )
fi


#trying to get all arguments into differnt indexes of an array

echo ${list[0]}
echo ${list[1]}
echo ${list[2]}
echo ${list[3]}

#test to get end of file extension
#FILE=$1
#echo "${FILE##*.}"
