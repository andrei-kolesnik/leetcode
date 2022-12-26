"""
LeetCode #470. Implement Rand10() Using Rand7()
https://leetcode.com/problems/implement-rand10-using-rand7/

Example 1:
Input: n = 1
Output: [2]

Example 2:
Input: n = 2
Output: [2,8]

Example 3:
Input: n = 3
Output: [3,8,10]
"""

from collections import Counter, OrderedDict
from random import randint

# The rand7() API is already defined for you.
def rand7() -> int:
    return randint(1, 7)


class Solution:
    def rand10(self) -> int:
        while True:
            x = rand7()
            y = rand7()
            ord_number = x + 7 * (y - 1)
            if ord_number <= 40:
                return ord_number % 10 + 1


def use_case(number_of_samples: int):
    results = [Solution().rand10() for _ in range(number_of_samples)]
    counts = dict(Counter(results))
    print('PASS' if 1 <= all(results) <= 10 else 'FAIL', number_of_samples, OrderedDict(sorted(counts.items())), sep=' : ')


if __name__ == '__main__':
    use_case(1)
    use_case(2)
    use_case(3)
    use_case(10000)
