<?php
/*
LettCode 219. Contains Duplicate II
https://leetcode.com/problems/contains-duplicate-ii/

Input 1: nums = [1,2,3,1], k = 3
Output 1: true

Input 2: nums = [1,0,1,1], k = 1
Output 2: true

Input 3: nums = [1,2,3,1,2,3], k = 2
Output 3: false*/

/**
 * @param Integer[] $nums
 * @param Integer $k
 * @return Boolean
 */
function containsNearbyDuplicate($nums, $k) {
    $nums_map = array();
    foreach ($nums as $index => $num) {
        if (isset($nums_map[$num]))
            if ($index - $nums_map[$num] <= $k)
                return true;
        $nums_map[$num] = $index;
    }
    return false;
}

echo var_export(containsNearbyDuplicate([1,2,3,1], 3)), "\n"; // true
echo var_export(containsNearbyDuplicate([1,0,1,1], 1)), "\n"; // true
echo var_export(containsNearbyDuplicate([1,2,3,1,2,3], 2)), "\n"; // false
