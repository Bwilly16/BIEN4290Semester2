#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm

rm summary.txt
rm -rf ./MidtermData # This kind of thing gets those last ~8 pts
mkdir MidtermData
cp -r /lab/bien4290/midterm2023/* ./MidtermData



#cd Eye-Motion-Repair

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


#find total number of commits per file
#NEED SOME CHECK IF .git file exists, PROJECT1 does NOT have a git
for files in $(ls ./MidtermData)
do  
    if [[ "$files" == "Eye-Motion-Repair" ]]; then
        #echo "Eye match"
        cd Eye-Motion-Repair
        #if git file exitst
        TCommits=$(git rev-list --all --count)
        #else echo git file does not exist
        
        
    elif [[ "$files" == "Metricks_OCVL" ]]; then
        #echo "Met match"
        cd ../Metricks_OCVL
        #if git file exists
        TCommits1=$(git rev-list --all --count)
        #else echo git file does not exist
        

    elif [[ "$files" == "project1" ]]; then
        #echo "proj match"
        cd ../project1
        #if git file exists
        TCommits2=$(git rev-list --all --count)
        cd ..  
        #else echo git file does not exist
    fi

    #Echo out answers to summary file (part c)
    echo "Total commits in Eye-Motion-Repair: $TCommits" >> summary.txt
    echo "Total commits in Metricks_OCVL: $TCommits1" >> summary.txt
    echo "Total commits in project1: $TCommits2" >> summary.txt
done







