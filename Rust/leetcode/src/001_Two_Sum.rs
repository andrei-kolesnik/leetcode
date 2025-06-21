/*
LeetCode 1. Two Sum
https://leetcode.com/problems/two-sum/

Input: [2, 7, 11, 15], target = 9
Output: [0, 1]
*/
use std::collections::HashMap;

struct Solution;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut map: HashMap<i32, i32> = HashMap::new();
        for (i, num) in nums.iter().enumerate() {
            if let Some(j) = map.get(&num) {
                return vec![*j, i as i32];
            }
            map.insert(target - num, i as i32);
        }
        vec![]
    }
}

fn main() {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1() {
        assert_eq!(vec![0, 1], Solution::two_sum(vec![2, 7, 11, 15], 9));
    }

    #[test]
    fn example_2() {
        assert_eq!(vec![1, 2], Solution::two_sum(vec![3, 2, 4], 6));
    }

    #[test]
    fn example_3() {
        assert_eq!(vec![0, 1], Solution::two_sum(vec![3, 3], 6));
    }
}
