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
Correct, but will time out
"""
class Solution:
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
Runnable part, helpers, and tests
"""
def use_case(input: str, expected: str):
    actual = Solution().longestPalindrome(input)
    print('PASS' if actual == expected else 'FAIL', ':', input, actual)


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
