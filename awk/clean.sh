#!/bin/sh -f

# shell script that runs sed to remove the majority of
# control characters from a lab output file
#
# the lab output file is given as a command argument
# 
# Note: this will not remove back space character and
# typing mistakes


if [[ $# == 1 ]]
then
   if [ -f $1 ]
   then
      sed -f /home/distribution/cnguyen/cis18b/clean.sed $1 > $1.cleaned;
      echo "Output file is" $1.cleaned
   else
      echo "Can't find file $1"
   fi
else
   echo "Usage: $0  filename"
fi
