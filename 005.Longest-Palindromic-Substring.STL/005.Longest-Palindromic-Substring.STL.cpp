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
	int start, end, left, right, middle;
	for (start = 0; start < s.size(); start++)
	{
		for (end = 2; end <= s.size() - start; end++)
		{
			bool OK = true;
			for (middle = 0, left = start, right = start + end - 1; 
				 middle < end/2; 
				 left++, right--, middle++)
				if (s[left] != s[right])
				{
					OK = false;
					break;
				}
			if (OK && end > result.size())
				result = s.substr(start, end);
		}
	}
	return result;
}

void check(string s, string expected)
{
	string actual = longestPalindrome(s);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check("", "");
	check("a", "a");
	check("cbbd", "bb");
	check("babad", "bab"); // "aba" is also correct
	check("cbbdadb", "bdadb");
	check("abcdefghijklmnoprqstuvwxyz", "a");
	check("abcdefghijklmnoprqstuvwxyzyxwvutsqrponmlkjihgfedcba", "abcdefghijklmnoprqstuvwxyzyxwvutsqrponmlkjihgfedcba");
	system("pause");
	return 0;
}
