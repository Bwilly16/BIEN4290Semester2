#!/bin/bash

#command expansion
newpath="$(pwd)/bashybash"
echo $newpath


root=$(ls / | wc -w)
home=$(ls ~ | wc -w)

#command expansion
((app_to_ls = $root+$home))
((app_to_ls = $(ls / | wc -w)+(ls ~ | wc -w))
echo $app_to_ls

captains=("Picard", "Janeway", "Kirk")
echo ${captains[0]}