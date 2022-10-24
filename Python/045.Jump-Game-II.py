"""
45. Jump Game II
https://leetcode.com/problems/jump-game-ii/

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2
"""
from typing import List


# O(n^2)
class Solution:
    def jump(self, nums: List[int]) -> int:
        n = len(nums)

        min_jumps = [n for _ in range(n)]
        min_jumps[n - 1] = 0

        for i in range(n - 2, -1, -1):
            if nums[i] > 0:
                min_jumps[i] = min([min_jumps[j] for j in range(i + 1, min(i + 1 + nums[i], n))]) + 1

        return min_jumps[0]


def use_case(nums: List[int], expected: int):
    actual = Solution().jump(nums)
    print('PASS' if actual == expected else 'FAIL', nums, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([0], 0)
    use_case([1], 0)
    use_case([2,1], 1)
    use_case([2,3,1,1,4], 2)
    use_case([2,3,0,1,4], 2)
