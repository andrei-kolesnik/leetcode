"""
LeetCode #063. Unique Paths II
https://leetcode.com/problems/unique-paths-ii/

Example 1:
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2

Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
"""
from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        try:
            m = len(obstacleGrid)
            n = len(obstacleGrid[0])
            grid = [[0 for j in range(n)] for i in range(m)]
            grid[0][0] = 0 if obstacleGrid[0][0] else 1
        except IndexError:
            return 0

        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j]:
                    continue
                if j > 0 and not obstacleGrid[i][j - 1]:
                    grid[i][j] += grid[i][j - 1]
                if i > 0 and not obstacleGrid[i - 1][j]:
                    grid[i][j] += grid[i - 1][j]

        # for i in range(m):
        #     print(obstacleGrid[i], sep=' ', end=None)
        # print()
        # for i in range(m):
        #     print(grid[i], sep=' ', end=None)

        return grid[m - 1][n - 1]


def use_case(obstacleGrid: List[List[int]], expected: int):
    actual = Solution().uniquePathsWithObstacles(obstacleGrid)
    print('PASS' if actual == expected else 'FAIL', actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([], 0)
    use_case([[1]], 0)
    use_case([[0]], 1)
    use_case([[1,0],[0,0]], 0)
    use_case([[0,0],[0,1]], 0)
    use_case([[0,1],[0,0]], 1)
    use_case([[0,0,0],[0,1,0],[0,0,0]], 2)
