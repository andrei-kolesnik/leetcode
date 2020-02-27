package main

import "fmt"

/*
LeetCode 1. Two Sum
https://leetcode.com/problems/two-sum/

Input: [2, 7, 11, 15], target = 9
Output: [0, 1]
*/

// Version 1: brute force; O(N^2) time, O(1) space
func twoSumBruteForce(nums []int, target int) []int {
	for i := 0; i < len(nums)-1; i++ {
		for j := i + 1; j < len(nums); j++ {
			if nums[i]+nums[j] == target {
				return []int{i, j}
			}
		}
	}
	return []int{}
}

// Version 2: hash; O(N) time, O(N) space
func twoSumHash(nums []int, target int) []int {
	hash := make(map[int]int, len(nums))
	for i, n := range nums {
		if supp, ok := hash[n]; ok {
			return []int{supp, i}
		} else {
			hash[target-n] = i
		}
	}
	return []int{}
}

func main() {
	target := 9
	nums := []int{2, 7, 11, 15}
	fmt.Println(twoSumBruteForce(nums, target))
	fmt.Println(twoSumHash(nums, target))
}
