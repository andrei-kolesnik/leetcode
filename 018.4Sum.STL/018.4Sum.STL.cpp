/*
18. 4Sum
https://leetcode.com/problems/4sum/
Input:
[1, 0, -1, 0, -2, 2]; target = 0
Output:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums, int target, int avoid) {
	vector<vector<int>> result;
	if (nums.size() < 3) return result; // bad array, not enough numbers for 3Sum
// 	sort(nums.begin(), nums.end()); // will be already sorted

	for (int i = 0; i < nums.size() - 2; i++) // for every number except for the last two
	{
		if (i == avoid) continue; // can't use it
		if (i > 0 && nums[i] == nums[i - 1]) continue; // same number as before, no need to check
		int l = i + 1, r = nums.size() - 1;
		while (l < r)
		{
			if (l == avoid) l++;
			if (r == avoid) r--;
			if (l >= r) break;
			int sum = nums[i] + nums[l] + nums[r];
			if (sum < target) l++;
			else if (sum > target) r--;
			else // bingo! but we are not done
			{
				vector<int> res;
				res.push_back(nums[i]);
				res.push_back(nums[l]);
				res.push_back(nums[r]);
				result.push_back(res);
				while (l < r && nums[l] == nums[l + 1]) l++;
				while (l < r && nums[r] == nums[r - 1]) r--;
				l++;
				r--;
			}
		}
	}
	return result;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
	vector<vector<int>> result;
	if (nums.size() < 4) return result; // bad array, not enough numbers for 4Sum
	
	map<vector<int>, int> results;
	sort(nums.begin(), nums.end()); // the algorithm only works if the array is sorted

	for (int i = 0; i < nums.size(); i++) // for every number
		for (auto ans : threeSum(nums, target - nums[i], i))
		{
			vector<int> res;
			res.push_back(nums[i]);
			for(auto a: ans) 
				res.push_back(a);
			sort(res.begin(), res.end());
			results[res]++;
		}
	
	for (auto it : results)
		result.push_back(it.first);
	return result;
}

void check(int nums[], int size, int target) {
	vector<int> v(nums, nums + size);
	cout << target << ":" << endl;
	for (auto ans : fourSum(v, target))
	{
		for_each(ans.begin(), ans.end(), [](int n) { cout << n << " "; }); //just to show that we could
		cout << endl;
	}
	cout << endl;
}

int main()
{
	int a1[] = { 1, 0, -1, 0, -2, 2 }; //target: 0
	check(a1, 6, 0);

	int a2[] = { -3, -1, 0, 2, 4, 5 }; //target: 0
	check(a2, 6, 1);

	system("pause");
	return 0;
}
