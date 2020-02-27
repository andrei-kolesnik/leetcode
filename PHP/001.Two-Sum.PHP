<?php
/*
LeetCode 1. Two Sum
https://leetcode.com/problems/two-sum/

Input: [2, 7, 11, 15], target = 9
Output: [0, 1]
*/
// Version 1: brute force; O(N^2) time, O(1) space
function twoSumBruteForce($nums, $target) {
    $result = array();
    for($i = 0; $i < count($nums) - 1; $i++)
        for($j = $i + 1; $j < count($nums); $j++)
            if($nums[$i] + $nums[$j] == $target)    
            {
                $result[0] = $i;
                $result[1] = $j;
                return $result;
            }
    return $result;
}

// Version 2: hash; O(N) time, O(N) space
function twoSumHash($nums, $target) {
    $result = array();
    $map = array();
    for($i = 0; $i < count($nums); $i++)
    {
        if(isset($map[$nums[$i]]))    
        {
            $result[0] = $map[$nums[$i]];
            $result[1] = $i;
            return $result;
        }
        else 
            $map[$target - $nums[$i]] = $i;
    }
    return $result;
}

$nums = array(2, 7, 11, 15); 
print_r(twoSumBruteForce($nums, 9));
print_r(twoSumHash($nums, 9));
?>
