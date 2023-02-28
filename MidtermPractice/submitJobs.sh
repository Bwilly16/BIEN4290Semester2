#!/bin/bash
#Author: Ben Wilichowski
#Date: 2/28/2023
#Purpose: Practice Midterm

rm condor.txt

echo "# of photons: $1"
num_phot=$1
if [[ -z $1 ]]; then 
	num_phot=1000000
	echo "You forgot an input, photons set to one million (1000000)"
fi


#set up for gantry angle
for gant in {60..90..15}
do
	for energy in {60..120..20}
	do 
		for diam in {4..10..2}
		do

		#set up loop to create every possible combination
		
		echo "Universe = vanilla" >> condor.txt
		echo "Executable = executable_name.exe" >> condor.txt
		echo "Arguments = $gant $energy $num_phot $diam" >> condor.txt
		echo "Log = logs/dor.log" >> condor.txt
		echo "Output = dor$ (Process).out" >> condor.txt
		echo "Error = dor$ (Process).error" >> condor.txt
		echo "getenv = True" >> condor.txt
		echo "should_transfer_files = Yes" >> condor.txt
		echo "when_to_transfer_output = ON_EXIT_OR_EVICT" >> condor.txt
		echo "transfer_input_files = spectrum$energy.dat" >> condor.txt
		echo "transfer_output_files = primary_out_${gant}_${diam}_${energy}.bin,scatter_${gant}_${diam}_${energy}.bin" >> condor.txt
		echo "on_exit_remove = (ExitCode == 0)" >> condor.txt
		echo "RequestCpus=1" >> condor.txt
		echo "Queue 1" >> condor.txt
		echo "" >> condor.txt 

		done
	done
done

