# LeetCode 17. Letter Combinations of a Phone Number
# https://leetcode.com/problems/letter-combinations-of-a-phone-number/
class Solution:
    phoneLetters = {
            '1': '',
            '2': 'abc',
            '3': 'def',
            '4': 'ghi',
            '5': 'jkl',
            '6': 'mno',
            '7': 'pqrs',
            '8': 'tuv',
            '9': 'wxyz',
            '0': ''
        }
    
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        if len(digits) == 0:
            return []
        if len(digits) == 1:
            return [c for c in self.phoneLetters[digits]]
        head_list = self.phoneLetters[digits[0]]
        tail_list = self.letterCombinations(digits[1:])
        return [h+t for h in head_list for t in tail_list]

input = '23'
sol = Solution()
print (sol.letterCombinations(input))
# ['ad', 'ae', 'af', 'bd', 'be', 'bf', 'cd', 'ce', 'cf']
