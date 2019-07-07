#!/bin/bash
# LettCode 195. Tenth Line
# https://leetcode.com/problems/tenth-line/

# Version 1: awk
awk 'NR==10 {print;}' file.txt

# Version 2: sed
sed -n '10p' file.txt

# Version 3: cat / head / tail
c=`cat file.txt | wc -l`
if [[ $c -gt 9 ]];then
  head -10 file.txt | tail -1
fi