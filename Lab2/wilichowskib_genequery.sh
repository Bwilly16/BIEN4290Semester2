#!/bin/bash
#Ben Wilichowski
#Date: 2/27/2023
#Purpose: to get current status of desired gene name

echo "What type of gene do you wanna analyze?"
read gene_type
echo "You want to analyze $gene_type"
echo " "


for (( i=0; i<7; i++ )) #correct forloop format
do 
    #look for specific gene within each file
    echo "For Time Point $i"


    if grep -q $gene_type suppressed_genes_$i.txt; then #using -q to output only the echoed phrase, kept outputting the variable name too
    echo "Supressed"
    echo " " #simplest way to print a new line
    fi

    if grep -q $gene_type stationary_genes_$i.txt; then
    echo "Stationary"
    echo " "
    fi

    if grep -q $gene_type expressed_genes_$i.txt; then
    echo "Expressed"
    echo " "
    fi
   
done