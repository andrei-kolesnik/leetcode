"""
1306. Jump Game III
https://leetcode.com/problems/jump-game-iii/

Example 1:
Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true

Example 2:
Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true

Example 3:
Input: arr = [3,0,2,1,2], start = 2
Output: false
"""
from typing import List

class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        self._n = len(arr)
        self._arr = arr
        self._visited = [0 for _ in range(self._n)]
        return self._canReach(start=start)

    def _canReach(self, start: int) -> bool:
        if start < 0 or start >= self._n:
            return False
        if self._arr[start] == 0:
            return True
        if self._visited[start] == 1:
            return False
        self._visited[start] = 1
        return self._canReach(start - self._arr[start]) or self._canReach(start + self._arr[start])


def use_case(nums: List[int], start: int, expected: bool):
    actual = Solution().canReach(nums, start)
    print('PASS' if actual == expected else 'FAIL', nums, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([4,2,3,0,3,1,2], 3, True)
    use_case([4,2,3,0,3,1,2], 5, True)
    use_case([4,2,3,0,3,1,2], 0, True)
    use_case([3,0,2,1,2], 2, False)
    use_case([0,3,0,6,3,3,4],6, True)
