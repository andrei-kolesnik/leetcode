<?php
/*
LettCode 217. Contains Duplicate
https://leetcode.com/problems/contains-duplicate/

Input 1: [1,2,3,1]
Output 1: true

Input 2: [1,2,3,4]
Output 2: false

Input 3: [1,1,1,3,3,4,3,2,4,2]
Output 3: true
*/

/**
 * @param Integer[] $nums
 * @return Boolean
 */
function containsDuplicate($nums) {
    $nums_map = array();
    foreach ($nums as $num) {
        if (isset($nums_map[$num]))
            return true;
        $nums_map[$num] = 1;
    }
    return false;
}

echo var_export(containsDuplicate([1,2,3,1])), "\n"; // true
echo var_export(containsDuplicate([1,2,3,4])), "\n"; // false
echo var_export(containsDuplicate([1,1,1,3,3,4,3,2,4,2])), "\n"; // true
echo var_export(containsDuplicate([])), "\n"; // false
echo var_export(containsDuplicate([1,1])), "\n"; // true
