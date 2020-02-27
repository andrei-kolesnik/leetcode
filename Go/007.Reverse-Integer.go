package main

/*
Leetcode #7: Reverse Integer
https://leetcode.com/problems/reverse-integer/
Example 1:

Input: 123
Output : 321

Example 2 :

Input : -123
Output : -321

Example 3 :

Input : 120
Output : 21
*/

import "fmt"

func reverse(x int) int {
	var result int32 = 0
	for ; x != 0; x = x / 10 {
		mod := x % 10
		var new_result int64 = int64(result)*10 + int64(mod)
		result = int32(new_result)
		if int64(result) != new_result { // check for overflow
			return 0
		}
	}
	return int(result)
}

func main() {
	fmt.Println(reverse(123))        // 321
	fmt.Println(reverse(-123))       // -321
	fmt.Println(reverse(120))        // 21
	fmt.Println(reverse(1534236469)) // 0, not 1056389759 or 9646324351
}
