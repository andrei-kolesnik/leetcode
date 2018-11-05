//LeetCode #9: Palindrome Number
//https://leetcode.com/problems/palindrome-number/

//Example 1:
//Input: 121
//Output : true
//
//Example 2:
//Input : -121
//Output : false
//Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//
//Example 3:
//Input : 10
//Output : false
//Explanation : Reads 01 from right to left.Therefore it is not a palindrome.

#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
	int result = 0;
	while (x)
	{
		int mod = x % 10;
		x = x / 10;
		result = result * 10 + mod;
	}
	return result;
}

bool isPalindrome(int x) {
	if (x >= 0)
		if (x == reverse(x))
			return true;
	return false;
}

int main()
{
	cout << boolalpha;
	cout << isPalindrome(121) << endl; //true
	cout << isPalindrome(-121) << endl; //false
	cout << isPalindrome(10) << endl; //false

	system("pause");
	return 0;
}
