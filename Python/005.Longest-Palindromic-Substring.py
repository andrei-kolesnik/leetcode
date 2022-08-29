"""
LeetCode #5: Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Example 1:
Input: "babad"
Output: "bab" / "aba"

Example 2:
Input: "cbbd"
Output: "bb"
"""

"""
Submittable part of the solution
Version 1: Recursive; correct, but will time out; O(n) = 2^n 
"""
class SolutionRecursive:
    def longestPalindrome(self, s: str) -> str:
        longest = self.isPalindrome(s)
        if longest > 0:
            return s

        sub1 = self.longestPalindrome(s[1:])
        sub2 = self.longestPalindrome(s[0:-1])

        if len(sub1) > len(sub2):
            return sub1
        if len(sub2) > len(sub1):
            return sub2
        if len(sub1) > 0:
            return sub1  # or sub2
        return ""

    def isPalindrome(self, s: str) -> int:
        if len(s) <= 1:
            return len(s)
        if s[0] == s[-1]:
            sub = self.isPalindrome(s[1:-1])
            if sub:
                return sub + 2
            return 0
        return 0


"""
Version 2: Single pass with check from the middle in both directions; O(n) = n^2 
"""
from math import floor, ceil


class Solution:
    def longestPalindrome(self, s: str) -> str:
        result = ""
        for i in [x * 0.5 for x in range(0, 2 * len(s) - 1)]:
            left = floor(i)
            right = ceil(i)
            new_result = ""
            while True:
                if left < 0 or right >= len(s):
                    break
                if s[left] == s[right]:
                    new_result = s[left:right+1]
                    left -= 1
                    right += 1
                else:
                    break
            if len(new_result) > len(result):
                result = new_result

        return result

"""
Runnable part, helpers, and tests
"""
def use_case(given: str, expected: str):
    actual = Solution().longestPalindrome(given)
    print('PASS' if actual == expected else 'FAIL', ':', given, actual)


if __name__ == '__main__':
    use_case("", "")
    use_case("a", "a")
    use_case("cBBd", "BB")
    use_case("cAAdBBBe", "BBB")
    use_case("cAAAdBBe", "AAA")
    use_case("BABAd", "BAB")  # "ABA" is also correct
    use_case("cbBDADB", "BDADB")
    use_case("abcdefghijklmnoprqstuvwxyz", "a")
    use_case("ABCDEFGHIJKLMNOPRQSTUVWXYZYXWVUTSQRPONMLKJIHGFEDCBA", "ABCDEFGHIJKLMNOPRQSTUVWXYZYXWVUTSQRPONMLKJIHGFEDCBA")
