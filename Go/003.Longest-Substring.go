package main

/*
LeetCode #3: Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
*/
import (
	"fmt"
	"math"
)

func lengthOfLongestSubstring(s string) int {
	result := 0

	for i := 0; i < len(s); i++ {
		hash := make(map[byte]int)
		for j := i; j < len(s); j++ {
			hash[s[j]]++
			if hash[s[j]] > 1 {
				break
			} else {
				result = int(math.Max(float64(result), float64(j-i+1)))
			}
		}
	}

	return result
}

func check(s string, expected int) {
	actual := lengthOfLongestSubstring(s)
	result := "FAIL"
	if actual == expected {
		result = "PASS"
	}
	fmt.Printf("%s (%d / %d)\n", result, expected, actual)
}

func main() {
	check("abcabcbb", 3)
	check("bbbbb", 1)
	check("pwwkew", 3)
	check("", 0)
	check("abcdefghijklmnoprqstuvwxyz", 26)
}
