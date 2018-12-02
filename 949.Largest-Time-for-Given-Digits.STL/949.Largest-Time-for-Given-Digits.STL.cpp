/*
LeetCode 949. Largest Time for Given Digits
https://leetcode.com/problems/largest-time-for-given-digits/

Given an array of 4 digits, return the largest 24 hour time that can be made.

The smallest 24 hour time is 00:00, and the largest is 23:59.  
Starting from 00:00, a time is larger if more time has elapsed since midnight.

Return the answer as a string of length 5.  If no valid time can be made, return an empty string.

Example 1:
Input: [1,2,3,4]
Output: "23:41"

Example 2:
Input: [5,5,5,5]
Output: ""

Note:
A.length == 4
0 <= A[i] <= 9
*/

#include <bits/stdc++.h>

using namespace std;

string largestTimeFromDigits(vector<int>& A) {
	stringstream ss;

	map<int, int> digits;
	for (auto a : A)
		digits[a]++;

	for (int h1 = 2; h1 >= 0; h1--)
		for (int h2 = (h1 == 2 ? 3 : 9); h2 >= 0; h2--)
			for (int m1 = 5; m1 >= 0; m1--)
				for (int m2 = 9; m2 >= 0; m2--)
				{
					map<int, int> result(digits);
					if (result[h1])
					{
						result[h1]--;
						if (result[h2])
						{
							result[h2]--;
							if (result[m1])
							{
								result[m1]--;
								if (result[m2])
								{
									ss << setw(1) << h1 << h2 << ":" << m1 << m2;
									return ss.str();
								}
							}
						}
					}
				}
	return "";
}

void check(int a[], int size, string expected) {
	vector<int> av(a, a + size);
	string actual = largestTimeFromDigits(av);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 1,2,3,4 };
	check(a1, 4, "23:41");

	int a2[] = { 5,5,5,5 };
	check(a2, 4, "");

	int a3[] = { 0,4,0,0 };
	check(a3, 4, "04:00");

	system("pause");
	return 0;
}

