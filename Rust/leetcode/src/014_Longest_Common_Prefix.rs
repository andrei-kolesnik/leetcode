// Leetcode #14: Longest Common Prefix
// https://leetcode.com/problems/longest-common-prefix/
// Example 1:
//
// Input: ["flower", "flow", "flight"]
// Output : "fl"
//
// Example 2:
//
// Input : ["dog", "racecar", "car"]
// Output : ""
// Explanation: There is no common prefix among the input strings.

struct Solution;

impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        if strs.is_empty() {
            return String::new();
        }

        let mut result = strs[0].clone();
        if strs.len() == 1 {
            return result;
        }

        while result.len() > 0 {
            if strs.iter().all(|s| s.starts_with(&result)) {
                return result;
            }
            result.pop();
        }

        result
    }
}

fn main() {}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example_1() {
        assert_eq!(
            String::from("fl"),
            Solution::longest_common_prefix(
                vec![
                    String::from("flower"),
                    String::from("flow"),
                    String::from("flight"),
                ]
            )
        );
    }

    #[test]
    fn example_2() {
        assert_eq!(
            String::from(""),
            Solution::longest_common_prefix(
                vec![
                    String::from("dog"),
                    String::from("racecar"),
                    String::from("car"),
                ]
            )
        );
    }

    #[test]
    fn test_empty_strs() {
        assert_eq!(String::from(""), Solution::longest_common_prefix(vec![]));
    }

    #[test]
    fn test_one_str() {
        assert_eq!(String::from("car"), Solution::longest_common_prefix(vec![String::from("car")]));
    }
}