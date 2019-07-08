#!/bin/bash
# LettCode 193. Valid Phone Numbers
# https://leetcode.com/problems/valid-phone-numbers/

# Version 1: awk
awk '/^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$/' file.txt

# Version 2: grep
grep -E '^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt
