/*
LeetCode #5: Longest Palindromic Substring
https://leetcode.com/problems/longest-palindromic-substring/

Example 1:
Input: "babad"
Output: "bab" / "aba"

Example 2:
Input: "cbbd"
Output: "bb"
*/

#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) 
{
	if (!s.size()) return "";
	string result(1, s[0]);
	int i, j, left, right, middle;
	for (i = 0; i < s.size(); i++)
	{
		for (j = 2; j <= s.size() - i; j++)
		{
			bool OK = true;
			for (middle = 0, left = i, right = i + j - 1; 
				 middle < j/2; 
				 left++, right--, middle++)
				if (s[left] != s[right])
				{
					OK = false;
					break;
				}
			if (OK && j > result.size())
				result = s.substr(i, j);
		}
	}
	return result;
}

int main()
{
	cout << longestPalindrome("babad") << endl; // bab / aba
	cout << longestPalindrome("cbbd") << endl; // bb
	cout << longestPalindrome("") << endl; // ""
	cout << longestPalindrome("a") << endl; // a
	cout << longestPalindrome("abcdefghijklmnoprqstuvwxyz") << endl; // a
	cout << longestPalindrome("abcdefghijklmnoprqstuvwxyzyxwvutsqrponmlkjihgfedcba") << endl; // abcdefghijklmnoprqstuvwxyzyxwvutsrqponmlkjihgfedcba
	system("pause");
	return 0;
}
