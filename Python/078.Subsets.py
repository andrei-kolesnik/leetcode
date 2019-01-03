# LeetCode 78. Subsets
# https://leetcode.com/problems/subsets/

# Input: nums = [1, 2, 3]
# Output:
# [
#     [3],
#     [1],
#     [2],
#     [1, 2, 3],
#     [1, 3],
#     [2, 3],
#     [1, 2],
#     []
# ]

class Solution:
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        results = []
        for i in range(2 ** len(nums)):
            result = []
            mask = i
            ind = 0
            while mask > 0:
                if mask & 1 > 0:
                    result.append(nums[ind])
                ind += 1
                mask >>= 1
            results.append(result)
        return results

sol = Solution()
print(sol.subsets([]))
print(sol.subsets([1]))
print(sol.subsets([1, 2, 3]))
