#i/bin/bash
# Ben Wilichowski
# 1/30/2023
# This script is about bash conditionals

    declare statement=1;
    declare first="Oh, oh, oh, oh, oh";
    declare second=" Caught";
    declare third=" in";
    declare fourth=" a";
    declare fifth=" bad";
    declare sixth=" romance";
    declare -a thecount=($first $second $third $fourth $fifth $sixth);

if [ statement==1 ]
then
    for ((i=0; i< ${#thecount[@]}; i++))
        do
        echo  ${thecount[i]} 
        done
else
    echo "I guess im in a good romance";
fi


    



