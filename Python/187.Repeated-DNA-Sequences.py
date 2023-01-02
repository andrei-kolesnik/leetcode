"""
LeetCode #187. Repeated DNA Sequences
https://leetcode.com/problems/repeated-dna-sequences/

Example 1:
Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]

Example 2:
Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
"""

from typing import List


class Solution:
    BASE = 31
    LARGE_PRIME = 1e15 + 37
    SEQUENCE_LENGTH = 10

    def char_val(self, char: str) -> int:
        return ord(char) - ord('A') + 1

    # O(n)
    def hash(self, s: str) -> int:
        result = 0
        power = 1
        for char in s[::-1]:
            result = (result + self.char_val(char) * power) % self.LARGE_PRIME
            power = (power * self.BASE) % self.LARGE_PRIME
        return int(result)

    # O(1)
    def rolling_hash(self, prev_s: str, prev_hash: int, next_char: str) -> int:
        return int(((prev_hash - self.char_val(prev_s[0]) * pow(self.BASE, len(prev_s) - 1)) * self.BASE + self.char_val(next_char)) % self.LARGE_PRIME)

    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        result = set()
        end = self.SEQUENCE_LENGTH
        dna_slice = s[0:end]
        slice_hash = self.hash(dna_slice)
        slice_hashes = {slice_hash}
        while end < len(s):
            slice_hash = self.rolling_hash(dna_slice, slice_hash, s[end])
            dna_slice = dna_slice[1:] + s[end]
            if slice_hash in slice_hashes:
                result.add(dna_slice)
            slice_hashes.add(slice_hash)
            end += 1
        return list(result)


def use_case(s: str, expected: List[str]):
    actual = Solution().findRepeatedDnaSequences(s)
    print('PASS' if actual == expected else 'FAIL', s, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT", ["AAAAACCCCC", "CCCCCAAAAA"])
    use_case("AAAAAAAAAAAAA", ["AAAAAAAAAA"])
    use_case("AAGATCCGTCCCCCCAAGATCCGTC", ["AAGATCCGTC"])
