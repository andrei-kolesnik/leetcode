"""
LeetCode #496. Next Greater Element I
https://leetcode.com/problems/next-greater-element-i/

Example 1:
Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
Output: [-1,3,-1]

Example 2:
Input: nums1 = [2,4], nums2 = [1,2,3,4]
Output: [3,-1]
"""

from typing import List

# Using the Monotonic Stack: O(m+n)
class Solution:
    def nextGreaterElement(self, nums1: List[int], nums2: List[int]) -> List[int]:
        d = {x:-1 for x in nums1}
        stack = []

        for x in nums2:
            while stack and stack[-1] <= x:
                y = stack.pop()
                if y in d:
                    d[y] = x
            stack.append(x)

        return list(d.values())


# Tests
def use_case(nums1: List[int], nums2: List[int], expected: List[int]):
    actual = Solution().nextGreaterElement(nums1, nums2)
    print('PASS' if actual == expected else 'FAIL', nums1, nums2, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([4,1,2], [1,3,4,2], [-1,3,-1])
    use_case([2,4], [1,2,3,4], [3,-1])
