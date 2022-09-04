"""
LeetCode #062. Unique Paths
https://leetcode.com/problems/unique-paths/

Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
"""


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        grid = [[0 for j in range(n)] for i in range(m)] * m
        grid[0][0] = 1

        for i in range(m):
            for j in range(n):
                if j > 0:
                    grid[i][j] += grid[i][j - 1]
                if i > 0:
                    grid[i][j] += grid[i - 1][j]

        # for i in range(m):
        #     print(grid[i], sep=' ', end=None)

        return grid[m - 1][n - 1]


def use_case(m: int, n: int, expected: int):
    actual = Solution().uniquePaths(m, n)
    print('PASS' if actual == expected else 'FAIL', m, n, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case(3, 7, 28)
    use_case(3, 2, 3)
