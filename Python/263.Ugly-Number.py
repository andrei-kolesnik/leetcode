# LeetCode 263. Ugly Number
# https://leetcode.com/problems/ugly-number/
class Solution:
    def isUgly(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        while num > 1:
            if num % 2 == 0:
                num /= 2
            elif num % 3 == 0:
                num /= 3
            elif num % 5 == 0:
                num /= 5
            else:
                return False
        return True
        
sol = Solution()
print(sol.isUgly(0))
print(sol.isUgly(1))
print(sol.isUgly(6))
print(sol.isUgly(8))
print(sol.isUgly(14))
