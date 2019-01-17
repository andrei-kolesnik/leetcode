<?php
/*
LettCode 1. Two Sum
https://leetcode.com/problems/two-sum/

Input: [2, 7, 11, 15], target = 9
Output: [0, 1]
*/
class Solution {
    function twoSum($nums, $target) {
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
}

$sol = new Solution();
$nums = array(2, 7, 11, 15); 
print_r($sol->twoSum($nums, 9));
?>