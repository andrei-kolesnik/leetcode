<?php
/*
215. Kth Largest Element in an Array
https://leetcode.com/problems/kth-largest-element-in-an-array/

Input 1: [3,2,1,5,6,4] and k = 2
Output 1: 5

Input 2: [3,2,3,1,2,4,5,5,6] and k = 4
Output 2: 4
*/

function findKthLargest($nums, $k) {
    $heap = new SplMaxHeap();
    foreach ($nums as $value) 
        $heap->insert($value);
    $result = 0;
    for ($i = 0; $i < $k; $i++) 
        $result = $heap->extract();
    return $result;
}

echo findKthLargest([3,2,1,5,6,4], 2), "\n"; # 5
echo findKthLargest([3,2,3,1,2,4,5,5,6], 4), "\n";  # 4
