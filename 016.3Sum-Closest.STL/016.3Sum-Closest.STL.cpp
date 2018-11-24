/*
LeetCode #16: 3Sum Closest
https://leetcode.com/problems/3sum/

Example Input 1:
nums = [-1, 2, 1, -4]
target = 1

Output 1:
2 (-1, 2, 1)
*/

#include <bits/stdc++.h>

using namespace std;

int threeSumClosest(vector<int>& nums, int target) {
	if (nums.size() < 3) return 0; // bad array, not enough numbers for 3Sum
	int result = target >= 0 ? INT32_MAX : INT32_MIN; // the farthest we can be from the target considering its sign

	sort(nums.begin(), nums.end()); // the algorithm only works if the array is sorted

	for (int i = 0; i < nums.size() - 2; i++) // for every number except for the last two
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue; // same number as before, no need to check
		int l = i + 1, r = nums.size() - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (abs(sum - target) < abs(result - target)) result = sum; // we found something better than before
			if (sum < target) l++;
			else if (sum > target) r--;
			else return target; // bingo! and we are done
		}
	}

	return result;
}

void check(int nums[], int size, int target, int expected) {
	vector<int> v(nums, nums + size);
	int actual = threeSumClosest(v, target);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { -1, 2, 1, -4 }; //target: 1; result: 2
	check(a1, 4, 1, 2);
	
	int a2[] = { -3, -2, -5, 3, -4 }; //target: - 1; result: -2
	check(a2, 5, -1, -2);

	int a3[] = { 0, 1, 2 }; //target: 0; result: 3
	check(a3, 3, 0, 3);

	system("pause");
	return 0;
}
