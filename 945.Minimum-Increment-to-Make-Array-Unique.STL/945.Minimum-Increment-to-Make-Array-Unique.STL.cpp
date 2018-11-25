/*
LeetCode 945. Minimum Increment to Make Array Unique
https://leetcode.com/problems/minimum-increment-to-make-array-unique/

Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
Return the least number of moves to make every value in A unique.

Example 1:
Input: [1,2,2]
Output: 1
Explanation:  After 1 move, the array could be [1, 2, 3].

Example 2:
Input: [3,2,1,2,1,7]
Output: 6
Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
It can be shown with 5 or less moves that it is impossible for the array to have all unique values.

Note:
0 <= A.length <= 40000
0 <= A[i] < 40000
*/
#include <bits/stdc++.h>

using namespace std;

int minIncrementForUnique(vector<int>& A) {
	int result = 0;
	map<int, int> m;

	for (auto a : A) m[a]++;
	for (map<int, int>::iterator it = m.begin(); it != m.end(); ++it)
		if (it->second > 1)
		{
			m[it->first + 1] += it->second - 1;
			result += it->second - 1;
		}
	return result;
}

void check(int a[], int size, int expected) {
	vector<int> v(a, a + size);
	int actual = minIncrementForUnique(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 1,2,2 };
	check(a1, 3, 1);

	int a2[] = { 3,2,1,2,1,7 };
	check(a2, 6, 6);

	int a3[] = { 1,2,3,4,5,6 }; 
	check(a3, 6, 0);

	system("pause");
	return 0;
}
