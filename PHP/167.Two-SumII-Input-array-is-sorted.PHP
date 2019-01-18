<?php
/*
LettCode 167. Two Sum II - Input array is sorted
https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

Input: [2, 7, 11, 15], target = 9
Output: [1, 2] (not zero-based)
*/
function twoSum($nums, $target) {
    $result = array();
    $left = 0; 
    $right = count($nums) - 1;
    while ($left < $right)
    {
        $sum = $nums[$left] + $nums[$right];
        if ($sum == $target)
        {
            $result[0] = $left+1;
            $result[1] = $right+1;
            return $result;
        }
        if ($sum < $target) $left++;
        else $right--;
    }
    return $result;
}

$nums = array(2, 7, 11, 15); 
print_r(twoSum($nums, 9));
?>