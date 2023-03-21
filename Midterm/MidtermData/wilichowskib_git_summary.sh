#!/bin/bash
#Author: Ben Wilichowski
#Date: 3/07/2023
#Purpose: Git Midterm
#final time done: 10:44 pm YAY :(((


#Remove all created files each run
rm summary.txt
rm gitlogEYE.txt
rm dateEYE.txt
rm ConvertDateEYE.txt
rm SortedDateEYE.txt
rm differenceEYES.txt

rm gitlogMETRICKS.txt
rm dateMETRICKS.txt
rm ConvertDateMETRICKS.txt
rm SortedDateMETRICKS.txt
rm differenceMETRICKS.txt

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
    echo "Git log for Eye-Motion-Repair" >> gitlogEYE.txt
    echo "$Date" >> gitlogEYE.txt

    echo "Git log for Metricks" >> gitlogMETRICKS.txt
    echo "$Date1" >> gitlogMETRICKS.txt

    #for my sanity I am not gonna do this since it doesnt have a git file
    #echo "Git log for project1" >> gitlog.txt
    #echo $Date >> gitlog.txt

done

#Get dates for the EYE file
readthefile="./gitlogEYE.txt"
cat $readthefile | while read LINE; 
do
    #myDate=$(echo $LINE | cut -f4 -d:)
    myDate=$(echo $LINE | grep "Date:" | cut -d ' ' -f 3-6)  #prints only columns 2-6, without the date text and the weird end character
    
    echo $myDate >> dateEYE.txt
    
    #echo $myDate >> date.txt
    sed -i '/^$/d' dateEYE.txt #removes blank lines from date file

done


#get dates for the metricks file
readthefile="./gitlogMETRICKS.txt"
cat $readthefile | while read LINE; 
do
    #myDate=$(echo $LINE | cut -f4 -d:)
    myDate=$(echo $LINE | grep "Date:" | cut -d ' ' -f 3-6)  #prints only columns 2-6, without the date text and the weird end character
    
    echo $myDate >> dateMETRICKS.txt
    
    #echo $myDate >> date.txt
    sed -i '/^$/d' dateMETRICKS.txt #removes blank lines from date file
done

#Converted my dates for EYE
readanother="./dateEYE.txt"
cat $readanother | while read line;
do 
    ConvertDate=$(date -d "$line" +%s)
    echo $ConvertDate >> ConvertDateEYE.txt
done

#Sorted my dates for EYE
sorted=$(sort -rn ConvertDateEYE.txt)
echo -e "$sorted" >> SortedDateEYE.txt



#Converted my dates for METRICKS
readanother1="./dateMETRICKS.txt"
cat $readanother1 | while read line;
do 
    ConvertDate1=$(date -d "$line" +%s)
    echo $ConvertDate1 >> ConvertDateMETRICKS.txt
done

#Sorted my dates for METRICKS
sorted1=$(sort -rn ConvertDateMETRICKS.txt)
echo -e "$sorted1" >> SortedDateMETRICKS.txt


#Figure out the min, avg, max, between commits in days, hours, minutes, and seconds.

#for max EYES
max=$(cut -f1 -d"," SortedDateEYE.txt | head -1)
ConvertMax=$(date -d@$max -u +'%Y-%m-%d %H:%M:%S') 
echo "[EYES] Most recent day a commit was made: "$ConvertMax"" >> summary.txt

#for min EYES
min=$(cut -f1 -d"," SortedDateEYE.txt | tail -1)
ConvertMin=$(date -d@$min -u +'%Y-%m-%d %H:%M:%S')
echo "[EYES] Earliest day a commit was made: "$ConvertMin"" >> summary.txt


#for max METRICKS
max1=$(cut -f1 -d"," SortedDateMETRICKS.txt | head -1)
#ConvertMax1=$(date -d@$max1 -u + '%H:%M:%S') 
ConvertMax1=$(date -d@$max1 -u +'%Y-%m-%d %H:%M:%S') 
echo "[METRICKS] Most recent day a commit was made: "$ConvertMax1"" >> summary.txt

#for min METRICKS
min1=$(cut -f1 -d"," SortedDateMETRICKS.txt | tail -1)
ConvertMin1=$(date -d@$min1 -u +'%Y-%m-%d %H:%M:%S')
echo "[METRICKS] Earliest day a commit was made: "$ConvertMin1"" >> summary.txt



#Finding average for EYES
prev=0
readavg="./SortedDateEYE.txt"
cat $readavg | while read line;
do 
    difference=$(($prev-$line))
    echo "$difference" >> differenceEYES.txt
    prev=$line
    
done
#removing max and min values
    fixed=$(sed -i '1d' differenceEYES.txt)
    fixed1=$(sed -i '16d' differenceEYES.txt)
    echo "$fixed" >> differenceEYES.txt
    echo "$fixed1" >> differenceEYES.txt


#Finding average METRICKS
prev=0
count=0
readavg="./SortedDateMETRICKS.txt"
cat $readavg | while read line;
do 
    difference=$(($prev-$line))
    echo "$difference" >> differenceMETRICKS.txt
    prev=$line
done

#removing max and min values
fixed=$(sed -i '1d' differenceMETRICKS.txt)
fixedlow=$(sed -i '113d' differenceMETRICKS.txt)
echo "$fixed" >> differenceMETRICKS.txt
echo "$fixedlow" >> differenceMETRICKS.txt



#for max EYES
max2=$(cut -f1 -d"," differenceEYES.txt | head -1)
Convert2=$(date -d@$max2 -u +'%Y-%m-%d %H:%M:%S') 
echo "[EYES] Greatest time inbetween commits: "$Convert2"" >> summary.txt

ineedsleep=$(cut -f1 -d"," differenceEYES.txt | sort -n | tail -1)
sleepconvert=$(date -d@$ineedsleep -u +'%Y-%m-%d %H:%M:%S')
echo "[EYES] Smallest time inbetween commits: "$sleepconvert"" >> summary.txt

#finding average
total=0
readdif="./differenceEYES.txt"
cat $readdif | while read line;
do
    total=$(($line+$total))  
done
    avg=$(($total/$TCommits1))
    Convertavg=$(date -d@$avg -u +'%Y-%m-%d %H:%M:%S')
    echo "[EYES] The average time between commits is: "$Convertavg"" 
    echo "[EYES] The average time between commits is: "$Convertavg"" >> summary.txt


#finding max and converting it
max23=$(cut -f1 -d"," differenceMETRICKS.txt | head -1)
Convert23=$(date -d@$max23 -u +'%Y-%m-%d %H:%M:%S') 
echo "[METRICKS] Greatest time inbetween commits: "$Convert23"" >> summary.txt

testmin=$(cut -f1 -d"," differenceMETRICKS.txt | sort -n | tail -1)
testconvert=$(date -d@$testmin -u +'%Y-%m-%d %H:%M:%S')
echo "[METRICKS] Smalles time inbetween commits: "$testconvert"" >> summary.txt

#finding average
total=0
readdif="./differenceMETRICKS.txt"
cat $readdif | while read line;
do
    total=$(($line+$total))
done
    avg=$(($total/$TCommits1))
    Convertavg=$(date -d@$avg -u +'%Y-%m-%d %H:%M:%S')
    echo "[METRICKS] The average time between commits is: "$Convertavg"" >> summary.txt






