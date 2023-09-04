"""
LeetCode #274. H-Index
https://leetcode.com/problems/h-index/

definition of h-index on Wikipedia: https:/en.wikipedia.org/wiki/H-index

Example 1:
Input: citations = [3,0,6,1,5]
Output: 3

Input: citations = [1,3,1]
Output: 1
"""

from typing import List


class Solution:
    def hIndex(self, citations: List[int]) -> int:
        n = len(citations)
        citation_counts = [0] * n
        for i in range(0, n):
            if citations[i]:
                citation_counts[min(citations[i], n) - 1] += 1

        for i in range(n - 2, -1, -1):
            citation_counts[i] += citation_counts[i + 1]

        for i in range(n - 1, -1, -1):
            if citation_counts[i] >= i + 1:
                return i + 1

        return 0

# Tests
def use_case(citations: List[int], expected: int):
    actual = Solution().hIndex(citations)
    print('PASS' if actual == expected else 'FAIL', citations, actual, expected, sep=' : ')

if __name__ == '__main__':
    use_case([0], 0)
    use_case([1], 1)
    use_case([1, 1], 1)
    use_case([2, 2], 2)
    use_case([3,0,6,1,5], 3)
    use_case([1,3,1], 1)
