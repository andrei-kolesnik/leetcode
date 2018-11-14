/*
LeetCode #010: Regular Expression Matching
https://leetcode.com/problems/regular-expression-matching/
*/

#include <bits/stdc++.h>

using namespace std;

/* Version 1: recursion; works, but is slow
bool isMatch(string s, string p) {
	if (p.empty()) return s.empty(); // ""|"" - good; "abc"|"" - bad
	if (p[0] == '*') return false; // a pattern cannot start with "*"
	if (p.size() > 1 && p[1] == '*')
	{
		if (isMatch(s, p.substr(2))) return true; // ""|"a*" - good; if "{x}"|"{y}" is good, "{x}"|"{y}a*" is also good
		while (!s.empty())
		{
			if (s[0] == p[0] || p[0] == '.')
			{
				if (isMatch(s.substr(1), p)) return true;
				s.erase(s.begin());
			}
			else return false;
		}
	}
	if (s.empty()) return false;

	if (s[0] == p[0] || p[0] == '.') return isMatch(s.substr(1), p.substr(1));
	else return false;
}
*/

//Version 2: Dynamic programming / Overlapping subproblems / Bottom-up approach
bool isMatch(string s, string p) {
	vector<vector<bool>> dp(s.length()+1);
	for (int i = 0; i < dp.size(); i++)
		dp[i].resize(p.length()+1, false);
	dp[s.length()][p.length()] = true;
	for (int i = s.length(); i >= 0; i--)
		for (int j = p.length() - 1; j >= 0; j--)
		{
			bool first_match = i < s.length() && (s[i] == p[j] || p[j] == '.');
			if (j + 1 < p.length() && p[j + 1] == '*')
				dp[i][j] = dp[i][j + 2] || first_match && dp[i + 1][j];
			else
				dp[i][j] = first_match && dp[i + 1][j + 1];
		}

/* if we are curious about what's in the dp array
	cout << noboolalpha;
	for (int i = 0; i < s.length() + 1; i++)
	{
		for (int j = 0; j < p.length() + 1; j++)
			cout << dp[i][j] << " ";
		cout << endl;
	}
*/

	return dp[0][0];
}

void doMatch(string s, string p, bool expected) {
	bool actual = isMatch(s, p);
	cout << boolalpha;
	cout << s << " | " << p << " (" << expected << "/" << actual << ") " 
		<< (actual == expected ? "PASS" : "FAIL") << endl;
}

int main()
{
	cout << boolalpha;
	doMatch("abc", "abc", true);
	doMatch("abc", "abd", false);
	doMatch("abc", "a.c", true);
	doMatch("aab", "c*a*b", true);
	doMatch("aa", "*", false);
	doMatch("aa", "a*", true);
	doMatch("", "a*", true);
	doMatch("a", "ab*", true);
	doMatch("aaa", "a*a", true);
	doMatch("aa", "a", false);
	doMatch("ab", ".*", true);
	doMatch("abcd", ".*", true);
	doMatch("abcd", ".*d", true);
	doMatch("abcde", ".*d", false);
	doMatch("abcd", ".*de", false);
	doMatch("abcd", ".*.", true);
	doMatch("aab", "c*a*b", true);
	doMatch("a", ".*.a*", true);
	doMatch("a", ".*..a*", false);
	doMatch("mississippi", "mis*is*p*.", false);
	doMatch("aaaaaaaaaac", "a*a*a*a*a*a*a*a*a*a*c", true);
	doMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c", false);//timeout for recursion
	doMatch("aaaaaaaaaaaaab", "a*.*a*.*a*.*a*.*a*.*c", false);//timeout for recursion
	doMatch("aabbcaaaababacaccba", ".*bc*.*b*b*a*.bc*", false);//timeout for recursion

	system("pause");
}
