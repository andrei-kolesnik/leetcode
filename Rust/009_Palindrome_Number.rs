/*
 LeetCode #9: Palindrome Number
 https://leetcode.com/problems/palindrome-number/
 Constraints:
 -2^31 <= x <= 2^31 - 1

 Example 1:
 Input: 121
 Output: true
 Explanation: 121 reads as 121 from left to right and from right to left.

 Example 2:
 Input: -121
 Output: false
 Explanation: From left to right, it reads - 121. From right to left, it becomes 121-. Therefore, it is not a palindrome.

 Example 3:
 Input: 10
 Output: false
 Explanation: Reads 01 from right to left. Therefore, it is not a palindrome.
*/

struct Solution;

impl Solution {
    pub fn reverse(mut x: i32) -> i32 {
        let mut reversed: i32 = 0;
        while x != 0 {
            // Handle potential overflow
            if let Some(safely_reversed) =
                reversed.checked_mul(10).and_then(|r| r.checked_add(x % 10))
            {
                reversed = safely_reversed;
                x /= 10;
            } else {
                return 0;
            }
        }
        reversed
    }

    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 { false } else { x == Self::reverse(x) }
    }
}

fn main() {
    assert_eq!(true, Solution::is_palindrome(121));
    assert_eq!(false, Solution::is_palindrome(-121));
    assert_eq!(false, Solution::is_palindrome(10));
    assert_eq!(true, Solution::is_palindrome(0));
    assert_eq!(false, Solution::is_palindrome(i32::MAX)); // 2^31-1 = 2_147_483_647
    assert_eq!(false, Solution::is_palindrome(i32::MIN)); // -2^31 = -2_147_483_648
}
