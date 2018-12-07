# LeetCode 31. Next Permutation
# https://leetcode.com/problems/next-permutation/
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1

class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # find the rightmost character in it, which is smaller than its next character ("first")
        first_pos = len(nums)-2
        found = False
        while first_pos >= 0: 
            if nums[first_pos] < nums[first_pos + 1]:
                first = nums[first_pos]
                found = True
                break
            else:
                first_pos -= 1
        # find the smallest character on right of "first", which is greater than "first" ("second")
        if found: 
            second_pos = first_pos + 1
            second = nums[second_pos]
            for i in range(first_pos+1, len(nums)):
                if first < nums[i] < second:
                    second_pos = i
                    second = nums[second_pos]
            # swap "first" and "second"
            nums[first_pos] = second 
            nums[second_pos] = first
        else: # need to reverse the whole list
            first_pos = -1

        # Sort the list (in non-decreasing order) after the "first"
        for i in range(first_pos+1, len(nums)-1):
            for j in range(i+1, len(nums)):
                if nums[i] > nums[j]:
                    swap = nums[i]
                    nums[i] = nums[j]
                    nums[j] = swap
        
#L = [1, 2, 3]
#L = [3, 2, 1]
#L = [1, 1, 5]
#L = [1, 2]
#L = [1, 3, 2]
L = ['D', 'C', 'F', 'E', 'B', 'A']
sol = Solution()        
sol.nextPermutation(L)
print(L)
