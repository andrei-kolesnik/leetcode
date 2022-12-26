"""
LeetCode #30: Substring with Concatenation of All Words
https://leetcode.com/problems/substring-with-concatenation-of-all-words/

Example 1:
Input: s = "barfoothefoobarman", words = ["foo","bar"]
Output: [0,9]

Example 2:
Input: s = "wordgoodgoodgoodbestword", words = ["word","good","best","word"]
Output: []

Example 3:
Input: s = "barfoofoobarthefoobarman", words = ["bar","foo","the"]
Output: [6,9,12]
"""
from typing import List


class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []

        word_len = len(words[0])
        num_of_words = len(words)
        all_words_len = num_of_words * word_len
        if len(s) < all_words_len:
            return result

        for i in range(0, len(s) - all_words_len + 1):
            window = s[i:i + all_words_len]
            counters = [word for word in words]
            chunks = [window[i * word_len:(i + 1) * word_len] for i in range(num_of_words)]
            for chunk in chunks:
                if chunk not in counters:
                    break
                counters.remove(chunk)
            else:
                result.append(i)

        return result


def use_case(s: str, words: List[str], expected: List[int]):
    actual = Solution().findSubstring(s, words)
    print('PASS' if actual == expected else 'FAIL', s, words, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case("barfoothefoobarman", ["foo", "bar"], [0, 9])
    use_case("wordgoodgoodgoodbestword",  ["word", "good", "best", "word"], [])
    use_case("barfoofoobarthefoobarman",  ["bar", "foo", "the"], [6, 9, 12])
    use_case("wordgoodgoodgoodbestword",  ["word", "good", "best", "good"], [8])
