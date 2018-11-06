/*
LeetCode #3: Longest Substring Without Repeating Characters
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Example 1:
Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
*/

#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s) {
	int result = 0;
	map<char, int> M;

	for (int i = 0; i < s.size(); i++)
	{
		M.clear();
		int j = i;
		for (; j < s.size(); j++)
			if (++M[s[j]] > 1) break;
		result = max(result, j - i);
	}

	return result;
}

int main()
{
	cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
	cout << lengthOfLongestSubstring("bbbbb") << endl; // 1
	cout << lengthOfLongestSubstring("pwwkew") << endl; // 3
	cout << lengthOfLongestSubstring("") << endl; // 3
	cout << lengthOfLongestSubstring("abcdefghijklmnoprqstuvwxyz") << endl; // 3
	system("pause");
	return 0;
}
