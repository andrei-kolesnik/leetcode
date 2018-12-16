/*
LeetCode 53. Maximum Subarray
https://leetcode.com/problems/maximum-subarray/

Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
*/
#include <bits/stdc++.h>

using namespace std;

// Version 1: dynamic programming, O(n^2)
int maxSubArray(vector<int>& nums) {
	int N = nums.size(), result = INT32_MIN;
	for (int i = 0; i < N; i++)
	{
		int num = nums[i];
		result = max(result, num);
		for (int j = i + 1; j < N; j++)
		{
			num = num + nums[j];
			result = max(result, num);
		}
	}
	return result;
}

// Version 2: scanning, O(n)
// http://akira.ruc.dk/~keld/teaching/algoritmedesign_f07/Artikler/05/Bentley84.pdf
int maxSubArray2(vector<int>& nums) {
	int maxSoFar = nums[0], maxEndHere = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		maxEndHere = max(maxEndHere + nums[i], nums[i]);
		maxSoFar = max(maxSoFar, maxEndHere);
	}
	return maxSoFar;
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = maxSubArray2(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { -2,1,-3,4,-1,2,1,-5,4 };
	check(a1, 9, 6);

	system("pause");
	return 0;
}
