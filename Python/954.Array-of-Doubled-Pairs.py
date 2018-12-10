# LeetCode 954. Array of Doubled Pairs
# https://leetcode.com/problems/array-of-doubled-pairs/

# the verison with list; works, but too slow
# see the version with map in C++
class Solution:
    def canReorderDoubled(self, A):
        """
        :type A: List[int]
        :rtype: bool
        """
        Ap = sorted([abs(a) for a in A])
        while len(Ap) > 0:
            bi = Ap[0]
            b2i = bi * 2
            Ap.remove(bi)
            if b2i not in Ap:
                return False
            Ap.remove(b2i)
        return True

sol = Solution()
print(sol.canReorderDoubled([3,1,3,6]))
print(sol.canReorderDoubled([2,1,2,6]))
print(sol.canReorderDoubled([4,-2,2,-4]))
print(sol.canReorderDoubled([1,2,4,16,8,4]))
print(sol.canReorderDoubled([1,2,4,8]))
