# 215. Kth Largest Element in an Array
# https://leetcode.com/problems/kth-largest-element-in-an-array/

# Input 1: [3,2,1,5,6,4] and k = 2
# Output 1: 5

# Input 2: [3,2,3,1,2,4,5,5,6] and k = 4
# Output 2: 4

import heapq
class Solution:
    def findKthLargest(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        heapq.heapify(nums)
        return heapq.nlargest(k, nums)[-1]

sol = Solution()
print(sol.findKthLargest([3,2,1,5,6,4], 2)) # 5
print(sol.findKthLargest([3,2,3,1,2,4,5,5,6], 4)) # 4