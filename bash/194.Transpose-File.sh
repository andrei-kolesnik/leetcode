#!/bin/bash
# Leetcode 194. Transpose File
# https://leetcode.com/problems/transpose-file/

LINES=`head -1 file-194.txt | awk '{ print NF;}'`
for (( i=1; i<=LINES; i++ )); do
  LINE=`cat file-194.txt | awk -v column=$i '{ printf "%s ", $column}'`
  echo "$LINE" | awk '$1=$1' # to suppress the trailing spaces; add "| cat -e" to verify
done