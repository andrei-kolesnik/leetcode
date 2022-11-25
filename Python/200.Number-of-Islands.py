"""
LeetCode #200. Number of Islands
https://leetcode.com/problems/number-of-islands/

Example 1:
Input: grid = [
    ["1","1","1","1","0"],
    ["1","1","0","1","0"],
    ["1","1","0","0","0"],
    ["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
    ["1","1","0","0","0"],
    ["1","1","0","0","0"],
    ["0","0","1","0","0"],
    ["0","0","0","1","1"]
]
Output: 3
"""
from typing import List

class DisjoinedSet:
    def __init__(self):
        self.__ds = {}

    def findRoot(self, i: int) -> int:
        if self.__ds[i] == i:
            return i
        return self.findRoot(self.__ds[i])

    def add(self, i: int):
        self.__ds[i] = i

    def merge(self, i: int, j: int):
        i_root = self.findRoot(i)
        j_root = self.findRoot(j)
        if i_root == j_root:
            return
        self.__ds[i_root] = j_root
        return

    def count(self) -> int:
        return len(set([self.findRoot(i) for i in self.__ds.keys()]))

    def print(self):
        print(self.__ds)


class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        ds = DisjoinedSet()

        m = len(grid)
        n = len(grid[0])

        def isLand(i: int, j: int) -> bool:
            if 0 <= i < m and 0 <= j < n:
                return bool(int(grid[i][j]))
            else:
                return False

        def getIndex(i: int, j: int) -> int:
            return i * n + j

        for i in range(m):
            for j in range(n):
                if int(grid[i][j]):
                    index = getIndex(i, j)
                    ds.add(index)
                    if isLand(i - 1, j):
                        ds.merge(getIndex(i - 1, j), index)
                    if isLand(i, j - 1):
                        ds.merge(getIndex(i, j - 1), index)

        return ds.count()


# Tests
def use_case(grid: List[List[str]], expected: int):
    actual = Solution().numIslands(grid)
    print('PASS' if actual == expected else 'FAIL', grid, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([
        ["1"],
    ], 1)
    use_case([
        ["0"],
    ], 0)
    use_case([
        ["1", "1", "1"],
        ["0", "1", "0"],
        ["1", "1", "1"],
    ], 1)
    use_case([
        ["1","1","1","1","0"],
        ["1","1","0","1","0"],
        ["1","1","0","0","0"],
        ["0","0","0","0","0"],
    ], 1)
    use_case([
        ["1", "1", "0", "0", "0"],
        ["1", "1", "0", "0", "0"],
        ["0", "0", "1", "0", "0"],
        ["0", "0", "0", "1", "1"],
    ], 3)
