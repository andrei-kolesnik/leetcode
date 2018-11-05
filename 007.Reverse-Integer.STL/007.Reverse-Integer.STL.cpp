//Leetcode #7: Reverse Integer
//https://leetcode.com/problems/reverse-integer/
//Example 1:
//
//Input: 123
//Output : 321
//
//Example 2 :
//
//Input : -123
//Output : -321
//
//Example 3 :
//
//Input : 120
//Output : 21

#include <bits/stdc++.h>

using namespace std;

int reverse(int x) {
	int result = 0;
	while (x)
	{
		int mod = x % 10;
		x = x / 10;
		long long new_result = long long(result) * 10 + mod; //submit with "long", not "long long"
		result = new_result;
		if (new_result != result) return 0; //to catch INT overflow
	}
	return result;
}

int main()
{
	cout << reverse(123) << endl;
	cout << reverse(-123) << endl;
	cout << reverse(120) << endl;
	cout << reverse(1534236469) << endl; //need 0, not 1056389759 //9646324351

	system("pause");
}
