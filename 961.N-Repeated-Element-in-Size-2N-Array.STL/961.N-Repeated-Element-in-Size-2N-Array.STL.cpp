/*
LeetCode 961. N-Repeated Element in Size 2N Array
https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
Input 1: [1,2,3,3]
Output 1: 3

Input 2: [2,1,2,5,3,2]
Output 2: 2

Input 3: [5,1,5,2,5,3,5,4]
Output 3: 5
*/
#include <bits/stdc++.h>

using namespace std;

int repeatedNTimes(vector<int>& A) {
	map<int, int> M;
	for (auto a : A)
		M[a]++;
	for (auto m : M)
		if (m.second == A.size() / 2)
			return m.first;
	return 0;
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = repeatedNTimes(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 1,2,3,3 };
	check(a1, 4, 3);

	int a2[] = { 2,1,2,5,3,2 };
	check(a2, 6, 2);

	int a3[] = { 5,1,5,2,5,3,5,4 };
	check(a3, 8, 5);

	system("pause");
	return 0;
}
