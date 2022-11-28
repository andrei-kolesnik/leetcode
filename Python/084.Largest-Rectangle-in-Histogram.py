"""
LeetCode #084. Largest Rectangle in Histogram
https://leetcode.com/problems/largest-rectangle-in-histogram/

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10

Example 2:
Input: heights = [2,4]
Output: 4
"""

from typing import List

class RangeArea:
    def __init__(self):
        self.min = -1
        self.size = 0

    def add(self, x: int):
        self.min = x if self.min == -1 else min(self.min, x)
        self.size += 1

    def area(self):
        return self.min * self.size

    def __repr__(self):
        return f'{self.min} x {self.size}'

# O(n^2) - works correctly, but times out on large arrays
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:

        areas = [RangeArea() for _ in range(len(heights))]
        max_so_far = 0

        for i, height in enumerate(heights):
            for j in range(i + 1):
                areas[j].add(height)
                max_so_far = max(max_so_far, areas[j].area())

        return max_so_far


def use_case(heights: List[int], expected: int):
    actual = Solution().largestRectangleArea(heights)
    print('PASS' if actual == expected else 'FAIL', heights, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([2,1,5,6,2,3], 10)
    use_case([2,4], 4)
    # use_case([1 for _ in range(30000)], 30000)
