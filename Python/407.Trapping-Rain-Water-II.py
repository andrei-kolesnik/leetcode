"""
LeetCode #407. Trapping Rain Water II
https://leetcode.com/problems/trapping-rain-water-ii/

Example 1:
Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
Output: 4

Example 2:
Input: heightMap = [[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]]
Output: 10
"""
from typing import List


class Solution:
    def trapRainWater(self, heightMap: List[List[int]]) -> int:
        n = len(heightMap)
        if not n:
            return 0
        m = len(heightMap[0])
        if not m:
            return 0

        water_so_far = 0

        return water_so_far


def use_case(heightMap: List[List[int]], expected: int):
    actual = Solution().trapRainWater(heightMap)
    print('PASS' if actual == expected else 'FAIL', heightMap, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([], 0)
    use_case([[]], 0)
    use_case([[0]], 0)
    use_case([[1]], 0)
    use_case([[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]], 4)
    use_case([[3,3,3,3,3],[3,2,2,2,3],[3,2,1,2,3],[3,2,2,2,3],[3,3,3,3,3]], 10)
