#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm

rm summary.txt
rm gitlog.txt
rm date.txt
rm ConvertDate.txt
rm SortedDate.txt

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
        Date=$(git log)
        #else echo git file does not exist
        
        
    elif [[ "$files" == "Metricks_OCVL" ]]; then
        #echo "Met match"
        cd ../Metricks_OCVL
        #if git file exists
        TCommits1=$(git rev-list --all --count)
        Date1=$(git log)
        #else echo git file does not exist
        

    elif [[ "$files" == "project1" ]]; then
        #echo "proj match"
        cd ../project1
        #if git file exists
        TCommits2=$(git rev-list --all --count)
        Date2=$(git log)
        cd ..  
        #else echo git file does not exist
    fi

    #Echo out answers to summary file (part c)
    echo "Total commits in Eye-Motion-Repair: $TCommits" >> summary.txt
    echo "Total commits in Metricks_OCVL: $TCommits1" >> summary.txt
    echo "Total commits in project1: $TCommits2" >> summary.txt


    #Echoing the log file to be able to parse for dates
    echo "Git log for Eye-Motion-Repair" >> gitlog.txt
    echo "$Date" >> gitlog.txt

    echo "Git log for Metricks" >> gitlog.txt
    echo "$Date1" >> gitlog.txt

    #for my sanity I am not gonna do this since it doesnt have a git file
    #echo "Git log for project1" >> gitlog.txt
    #echo $Date >> gitlog.txt

done

readthefile="./gitlog.txt"
cat $readthefile | while read LINE; 
do
    #myDate=$(echo $LINE | cut -f4 -d:)
    myDate=$(echo $LINE | grep "Date:" | cut -d ' ' -f 3-6)  #prints only columns 2-6, without the date text and the weird end character
    
    echo $myDate >> date.txt
    
    #echo $myDate >> date.txt
    sed -i '/^$/d' date.txt #removes blank lines from date file

done

#Converted my dates
readanother="./date.txt"
cat $readanother | while read line;
do 
    ConvertDate=$(date -d "$line" +%s)
    echo $ConvertDate >> ConvertDate.txt
done

#Sorted my dates 
sorted=$(sort -rn ConvertDate.txt)
echo -e "$sorted" >> SortedDate.txt



#Figure out the min, avg, max, between commits in days, hours, minutes, and seconds.

    
#cat ./gitlog.txt | grep "Date" | xa













#while loop with while read line, convert each line to all seconds
#current line minus previous, set to variable, do the same till end






