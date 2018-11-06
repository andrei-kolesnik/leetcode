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

string longestPalindrome(string s) {

	if (!s.size()) return "";
	string result = s.substr(0, 1);

	int i, j, k, l, m;
	for (i = 0; i < s.size(); i++)
	{
		string found = "";
		for (j = 2; j <= s.size() - i; j++)
		{
			bool OK = true;
			for (m = 0, k = i, l = i + j - 1; m < j/2; k++, l--, m++)
				if (s[k] != s[l])
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
