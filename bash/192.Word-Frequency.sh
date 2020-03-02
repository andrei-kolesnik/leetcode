#!/bin/bash
# Leetcode 192. Word Frequency
# https://leetcode.com/problems/word-frequency/

cat words.txt | tr -s ' ' '\n' | sort | uniq -c | sort -r | awk '{print $2,$1}'
