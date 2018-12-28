/*
LeetCode 198. House Robber
https://leetcode.com/problems/house-robber/

Input 1: [1,2,3,1]
Output 1: 4

Input 2: [2,7,9,3,1]
Output 2: 12
*/

#include <bits/stdc++.h>

using namespace std;

map<int, int> solutions;

int robInd(vector<int>& nums, int n)
{
	if (n < 0) return 0;
	if (n == 0) return nums[0];
	if (solutions.find(n) != solutions.end()) return solutions[n];
	int result = max(robInd(nums, n - 1), nums[n] + robInd(nums, n - 2));
	solutions[n] = result;
	return result;
}

int rob(vector<int>& nums) {
	if (!nums.size()) return 0;
	solutions.clear();
	return robInd(nums, nums.size() - 1);
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = rob(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 1,2,3,1 };
	check(a1, 0, 0);
	check(a1, 1, 1);
	check(a1, 2, 2);
	check(a1, 3, 4);
	check(a1, 4, 4);

	int a2[] = { 2,7,9,3,1 };
	check(a2, 5, 12);

	int a3[] = { 10,2,3,10 };
	check(a3, 4, 20);

	int a4[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	check(a4, 100, 0);

	system("pause");
	return 0;
}
