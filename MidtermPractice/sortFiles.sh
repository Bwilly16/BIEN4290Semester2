#!/bin/bash
#Author: Ben Wilichowski
#Date: 2/28/2023
#Purpose: Practice Midterm 2023

#take in command line argument for number of files
echo "Script Name: $0"
echo "$# arguments"
num=$#

if [ "$#" -eq 0 ]; then 
	echo "You done messed up, Ben. I need more arguments"
else
	#should store all arguments after argument 0
	list=( "$@" )
fi

#Test to make sure all arguments went into my array
##echo ${list[0]}
##echo ${list[1]}
##echo ${list[2]}
##echo ${list[3]}

#Setting up if 
for (( c=0; c<=$num; c++ ))
do	
	if [ "${list[$c]##*.}" == "sh" ]; then
		#print to proper directory
		echo "good file"
	else
		echo "bad file"
	fi
done
#test to get end of file extension
#FILE=$1
#echo "${FILE##*.}"
