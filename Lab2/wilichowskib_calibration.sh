#!/bin/bash
#Author: Ben Wilchowski
#Date: 2/27/2023
#Purpose: Bash script for calibrating data to start gene process

#not sure if summary file will get over written if I dont have a rm function, gotta test this
echo "How many genes are being analyzed?"
read gene_num
echo "You requested $gene_num genes."

rm outputsummary.txt
for (( i=0; i<7; i++ )) #need spaces for syntax

do
    #input the 6 arguments needed for function to run
    #executable, red, redbackground, green, greenbackground, file being wrote to, number of genes
    ./preproc_exe microarray/red_$i.dat microarray/red_background_$i.dat microarray/green_$i.dat microarray/green_background_$i.dat log_ratio_$i.dat $gene_num
    #^^ ^^ ^^whatever number is choosen will be written to that corresponding log file
   
    #put log_ratio_input.dat (which is the output of the preproccesing file) into the requested variabled file
    cat log_ratio_$i.dat > log_ratio_input.dat 
    echo "Time Point $i:" >> outputsummary.txt

    #run the clustering program, output to summary file
    
    (./kmean_exe log_ratio_input.dat) >> outputsummary.txt

    #copy files to corresponding time point file
    cp surpressed_genes.txt suppressed_genes_$i.txt #lol I spelled "suppressed" right this time...
    cp stationary_genes.txt stationary_genes_$i.txt
    cp expressed_genes.txt expressed_genes_$i.txt

    done

