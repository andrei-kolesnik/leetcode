/*
LeetCode 962. Maximum Width Ramp
https://leetcode.com/problems/maximum-width-ramp/
Input 1: [6,0,8,2,1,5]
Output 1: 4
Explanation 1:
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.

Input 2: [9,8,1,0,1,9,4,0,4,1]
Output 2: 7
Explanation 2:
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
*/
#include <bits/stdc++.h>

using namespace std;

int maxWidthRampBrute(vector<int>& A) {
	int result = 0;
	for (int i = 0; i < A.size() - 1; i++)
		for (int j = i + 1; j < A.size(); j++)
			if (A[i] <= A[j])
				result = max(j - i, result);
	return result;
}

int maxWidthRamp(vector<int>& A) {
	int result = 0, N = A.size();
	vector<pair<int, int>> V;
	for (int i = 0; i < N; i++) {
		if (V.empty() || V.back().first > A[i])
			V.push_back({ A[i], i });
		else
			for (auto p : V)
				if (p.first <= A[i])
					result = max(result, i - p.second);
		//using STL:
		//result = max(result, i - lower_bound(V.begin(), V.end(), make_pair(A[i], INT32_MAX),
		//greater<pair<int, int>>())->second);
	}
	return result;
}

void check(int nums[], int size) {
	vector<int> v(nums, nums + size);
	int actual = maxWidthRamp(v);
	int expected = maxWidthRampBrute(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 6,0,8,2,1,5 };
	check(a1, 6); //4

	int a2[] = { 9,8,1,0,1,9,4,0,4,1 };
	check(a2, 10); //7

	int a3[] = { 6, 0, 8, 2, 1, 5 };
	check(a3, 6); //4

	int a4[] = { 6, 5, 4, 3, 2, 1 };
	check(a4, 6); //0

	int a5[] = { 2, 2, 1 };
	check(a5, 3); //1

	int a6[] = { 4, 2, 3, 1 };
	check(a6, 4); //1

	int a7[] = { 10, 10, 10, 7, 1, 6, 2, 1, 7 };
	check(a7, 9); //5

	int a8[] = { 1, 2, 1 };
	check(a8, 3); //2

	system("pause");
	return 0;
}
