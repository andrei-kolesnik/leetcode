//LeetCode #13: Roman to Integer
//https://leetcode.com/problems/roman-to-integer/
//Example 1:
//Input: "III"
//Output : 3
//
//Example 2 :
//Input : "IV"
//Output : 4
//
//Example 3 :
//Input : "IX"
//Output : 9
//
//Example 4 :
//Input : "LVIII"
//Output : 58
//Explanation : L = 50, V = 5, III = 3.
//
//Example 5 :
//Input : "MCMXCIV"
//Output : 1994
//Explanation : M = 1000, CM = 900, XC = 90 and IV = 4.

#include <bits/stdc++.h>

using namespace std;

int romanToInt(string s) {
	if (s.length() == 0) return 0;
	int result = 0;
	switch (s[0])
	{
	case 'I': result = 1; break;
	case 'V': result = 5; break;
	case 'X': result = 10; break;
	case 'L': result = 50; break;
	case 'C': result = 100; break;
	case 'D': result = 500; break;
	case 'M': result = 1000; break;
	}
	int tail = romanToInt(s.substr(1));
	if (tail >= result * 4) return tail - result;
	return tail + result;
}

int main()
{
	cout << romanToInt("III") << endl; //3
	cout << romanToInt("IV") << endl; //4
	cout << romanToInt("IX") << endl; //9
	cout << romanToInt("LVIII") << endl; //58
	cout << romanToInt("MCMXCIV") << endl; //1994

	system("pause");
}
