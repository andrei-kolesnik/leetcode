/*
LeetCode #8: String to Integer (atoi)
https://leetcode.com/problems/string-to-integer-atoi/
Example 1:
Input: "42"
Output: 42

Example 2:
Input: "   -42"
Output: -42
Explanation: The first non-whitespace character is '-', which is the minus sign.
			 Then take as many numerical digits as possible, which gets 42.

Example 3:
Input: "4193 with words"
Output: 4193
Explanation: Conversion stops at digit '3' as the next character is not a numerical digit.

Example 4:
Input: "words and 987"
Output: 0
Explanation: The first non-whitespace character is 'w', which is not a numerical
			 digit or a +/- sign. Therefore no valid conversion could be performed.

Example 5:
Input: "-91283472332"
Output: -2147483648
Explanation: The number "-91283472332" is out of the range of a 32-bit signed integer.
			 Thefore INT_MIN (-2^31) is returned.
*/

#include <bits/stdc++.h>

using namespace std;

int myAtoi(string str) {
	int result = 0;
	long long real_result = 0;
	int sign = 1;

	while (str[0] == ' ') str.erase(str.begin());

	if (str[0] == '-')
	{
		sign = -1;
		str.erase(str.begin());
	}
	else if (str[0] == '+')
		str.erase(str.begin());

	while (str.length() > 0)
	{
		char ch = str[0];
		if (!(ch >= '0' && ch <= '9')) break;
		real_result = real_result * 10 + int(ch - '0');
		
		if (sign == 1 && real_result >= long long(INT_MAX)) return INT_MAX;
		if (sign == -1 && real_result >= long long(INT_MAX)+1) return INT_MIN;

		result = int(real_result);

		str.erase(str.begin());
	}

	return result * sign;
}

int main()
{
	cout << myAtoi("42") << endl; //42
	cout << myAtoi(" +42") << endl; //42
	cout << myAtoi("-+1") << endl; //0
	cout << myAtoi("-0012a42") << endl; //-12
	cout << myAtoi("   -42") << endl; //-42
	cout << myAtoi(" --42") << endl; //0
	cout << myAtoi("4193 with words") << endl; //4193
	cout << myAtoi("0") << endl; //0
	cout << myAtoi("-0") << endl; //0
	cout << myAtoi("words and 987") << endl; //0
	cout << myAtoi("2147483647") << endl; //2147483647
	cout << myAtoi("-2147483647") << endl; //2147483647
	cout << myAtoi("2147483648") << endl; //2147483647 (overflow)
	cout << myAtoi("-2147483648") << endl; //-2147483648
	cout << myAtoi("2147483649") << endl; //2147483647 (overflow)
	cout << myAtoi("-2147483649") << endl; //-2147483648 (overflow)
	cout << myAtoi("91283472332") << endl; //2147483647 (overflow)
	cout << myAtoi("-91283472332") << endl; //-2147483648 (overflow)

	system("pause");
}
