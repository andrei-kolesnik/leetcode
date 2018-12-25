/*
LeetCode 125. Valid Palindrome
https://leetcode.com/problems/valid-palindrome/

Input 1: "A man, a plan, a canal: Panama"
Output 1: true

Input 2: "race a car"
Output 2: false
*/
#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s) {
	stringstream ss;
	for (auto ch : s)
		if (isalnum(ch))
			ss << char(tolower(ch));
	string new_s = ss.str();
	int left = 0, right = new_s.size() - 1;
	while (left < right)
		if (new_s[left++] != new_s[right--])
			return false;
	return true;
}

void check(string s, bool expected)
{
	bool actual = isPalindrome(s);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check("", true);
	check("A", true);
	check("Aa", true);
	check("AbBa", true);
	check("bABa", false);
	check("0P", false);
	check("A man, a plan, a canal: Panama", true);
	check("race a car", false);

	system("pause");
	return 0;
}
