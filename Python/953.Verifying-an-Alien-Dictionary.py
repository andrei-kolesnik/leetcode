import functools

class Solution:
    _order = ''
    
    def compare(self, item1, item2):
        for i in range(min(len(item1), len(item2))):
            k1 = self._order.find(item1[i])
            k2 = self._order.find(item2[i])
            if k1 < k2:
                return -1
            if k1 > k2:
                return 1
        if len(item1) < len(item2):
            return -1
        if len(item1) > len(item2):
            return 1
        return 0
    
    def isAlienSorted(self, words, order):
        """
        :type words: List[str]
        :type order: str
        :rtype: bool
        """
        self._order = order
        return sorted(words, key = functools.cmp_to_key(self.compare)) == words
         

sol = Solution()
print(sol.isAlienSorted(["hello","leetcode"], "hlabcdefgijkmnopqrstuvwxyz")) # True
print(sol.isAlienSorted(["word","world","row"], "worldabcefghijkmnpqstuvxyz")) # False
print(sol.isAlienSorted(["apple","app"], "abcdefghijklmnopqrstuvwxyz")) # False
print(sol.isAlienSorted(["kuvp","q"], "ngxlkthsjuoqcpavbfdermiywz")) # True
