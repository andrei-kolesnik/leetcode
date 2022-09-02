"""
LeetCode #010: Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/

Example 1:
Input: s = "aa", p = "a"
Output: False
Explanation: "a" does not match the entire string "aa".

Example 2:
Input: s = "aa", p = "a*"
Output: True
Explanation: '*' means zero or more of the preceding element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".

Example 3:
Input: s = "ab", p = ".*"
Output: True
Explanation: ".*" means "zero or more (*) of any character (.)".
"""

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False for j in range(len(p) + 1)] for i in range(len(s) + 1)]
        dp[len(s)][len(p)] = True

        for i in range(len(s), -1, -1):
            for j in range(len(p) - 1, -1, -1):
                first_match = i < len(s) and (s[i] == p[j] or p[j] == '.')
                if j + 1 < len(p) and p[j + 1] == '*':
                    dp[i][j] = dp[i][j + 2] or (first_match and dp[i + 1][j])
                else:
                    dp[i][j] = first_match and dp[i + 1][j + 1]

        return dp[0][0]


def use_case(s: str, p: str, expected: bool):
    actual = Solution().isMatch(s, p)
    print('PASS' if actual == expected else 'FAIL', s, p, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case("abc", "abc", True)
    use_case("abc", "abc*", True)
    use_case("abc", "abd", False)
    use_case("abc", "a.c", True)
    use_case("aab", "c*a*b", True)
    use_case("aa", "*", False)
    use_case("aa", "a*", True)
    use_case("", "a*", True)
    use_case("a", "ab*", True)
    use_case("aaa", "a*a", True)
    use_case("aa", "a", False)
    use_case("ab", ".*", True)
    use_case("abcd", ".*", True)
    use_case("abcd", ".*d", True)
    use_case("abcde", ".*d", False)
    use_case("abcd", ".*de", False)
    use_case("abcd", ".*.", True)
    use_case("aab", "c*a*b", True)
    use_case("a", ".*.a*", True)
    use_case("a", ".*..a*", False)
    use_case("mississippi", "mis*is*p*.", False)
    use_case("aaaaaaaaaac", "a*a*a*a*a*a*a*a*a*a*c", True)
    use_case("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c", False)
    use_case("aaaaaaaaaaaaab", "a*.*a*.*a*.*a*.*a*.*c", False)
    use_case("aabbcaaaababacaccba", ".*bc*.*b*b*a*.bc*", False)
