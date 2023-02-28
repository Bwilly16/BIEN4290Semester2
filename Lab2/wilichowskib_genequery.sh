#!/bin/bash
#Ben Wilichowski
#Date: 2/27/2023
#Purpose: to get current status of desired gene name

echo "What is the name of the desired gene?"
read gene_type
echo "You want to look for $gene_type"
echo " "


for (( i=0; i<7; i++ )) #correct forloop format
do 
    #look for specific gene within each file
    echo "For Time Point $i"


    if grep -q $gene_type suppressed_genes_$i.txt; then #using -q to output only the echoed phrase, kept outputting the variable name too
    echo "Suppressed"
    echo " " #simplest way to print a new line
    

    elif grep -q $gene_type stationary_genes_$i.txt; then
    echo "Stationary"
    echo " "
    

    elif grep -q $gene_type expressed_genes_$i.txt; then
    echo "Expressed"
    echo " "
    

    else echo "$gene_type does not exist anywhere..."
    fi
done