/*
LeetCode #12: Integer to Roman
https://leetcode.com/problems/integer-to-roman/
Example 1:
Input: 3
Output: "III"

Example 2:
Input: 4
Output: "IV"

Example 3:
Input: 9
Output: "IX"

Example 4:
Input: 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3

Example 5:
Input: 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4
*/

#include <bits/stdc++.h>

using namespace std;

struct RomanDigit {
	string single;
	string fiver;
};

RomanDigit RD[4] = {
	{"I", "V"}, //1-9
	{"X", "L"}, //10-99
	{"C", "D"}, //100-999
	{"M", "?"}  //1000-3999
};

string intToRoman(int num) {
	if (num < 1 || num > 3999) return ""; // out of range
	
	string result = "";
	int power = 0, i;
	while (num)
	{
		int digit = num % 10;

		if (digit >= 1 && digit <= 3)
			for (i = 1; i <= digit; i++)
				result = RD[power].single + result;
		else if (digit == 4)
			result = RD[power].single + RD[power].fiver + result;
		else if (digit >= 5 && digit <= 8)
		{
			for (i = 6; i <= digit; i++)
				result = RD[power].single + result;
			result = RD[power].fiver + result;
		}
		else if (digit == 9 && power < sizeof(RD)/sizeof(RomanDigit)-1)
			result = RD[power].single + RD[power+1].single + result;

		num /= 10;
		power++;
	}

	return result;
}

void check(int num, string expected) {
	string actual = intToRoman(num);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
  		 << num << " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check(3, "III");
	check(4, "IV");
	check(9, "IX");
	check(58, "LVIII");
	check(1888, "MDCCCLXXXVIII"); 
	check(1994, "MCMXCIV");
	check(2888, "MMDCCCLXXXVIII"); // the longest roman numeral
	check(3999, "MMMCMXCIX");
	check(0, ""); // out of range
	check(4000, ""); // out of range

	system("pause");
}
