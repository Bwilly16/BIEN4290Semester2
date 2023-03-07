#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm

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
        echo "Eye match"
        cd Eye-Motion-Repair
        TCommits=$(git rev-list --all --count)
        echo "Total commits in Eye-Motion-Repair: $TCommits"
    fi

    if [[ "$files" == "Metricks_OCVL" ]]; then
        echo "Met match"
        cd ../Metricks_OCVL
        TCommits=$(git rev-list --all --count)
        echo "Total commits in Metricks_OCVL: $TCommits"
    fi

    if [[ "$files" == "project1" ]]; then
        echo "proj match"
        cd ../project1
        TCommits=$(git rev-list --all --count)
        echo "Total commits in project1: $TCommits"

    fi
done


#TCommits=$(git rev-list --all --count)
#echo $TCommits




