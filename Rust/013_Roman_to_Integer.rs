/*
LeetCode #13: Roman to Integer
https://leetcode.com/problems/roman-to-integer/

Example 1:
Input: "III"
Output: 3

Example 2:
Input: "IV"
Output: 4

Example 3:
Input: "IX"
Output: 9

Example 4:
Input: "LVIII"
Output: 58
Explanation: L = 50, V = 5, III = 3.

Example 5:
Input: "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/

struct Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        if s.len() == 0 {
            return 0;
        }
        let result = match s.chars().nth(0).unwrap() {  
            'I' => 1,
            'V' => 5,
            'X' => 10,
            'L' => 50,
            'C' => 100,
            'D' => 500,
            'M' => 1000,
            _ => 0,
        };
        let tail = Self::roman_to_int(s.chars().skip(1).collect());
        if tail >= result * 4 {
            tail - result
        } else {
            tail + result
        }
    }
}

fn main() {
    assert_eq!(0, Solution::roman_to_int("".to_string()));
    assert_eq!(3, Solution::roman_to_int("III".to_string()));
    assert_eq!(4, Solution::roman_to_int("IV".to_string()));
    assert_eq!(9, Solution::roman_to_int("IX".to_string()));
    assert_eq!(58, Solution::roman_to_int("LVIII".to_string()));
    assert_eq!(1994, Solution::roman_to_int("MCMXCIV".to_string()));
}
