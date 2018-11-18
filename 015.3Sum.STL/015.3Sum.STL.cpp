/*
LeetCode #15: 3Sum.STL
https://leetcode.com/problems/3sum/
Example Input:
[-1, 0, 1, 2, -1, -4],
Output:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <bits/stdc++.h>

using namespace std;

//Version 1: brute force; too slow
/*
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;

	if (nums.size() < 3) return result;

	for (int i = 0; i < nums.size() - 2; i++)
		for (int j = i + 1; j < nums.size() - 1; j++)
			for (int k = j + 1; k < nums.size(); k++)
			{
				if (nums[i] + nums[j] + nums[k] == 0)
				{
					vector<int> res;
					res.push_back(nums[i]);
					if (nums[j] < nums[i])
						res.insert(res.begin(), nums[j]);
					else
						res.push_back(nums[j]);
					if (nums[k] < res[0])
						res.insert(res.begin(), nums[k]);
					else if (nums[k] > res[1])
						res.push_back(nums[k]);
					else
						res.insert(res.begin()+1, nums[k]);

					bool found = false;
					for (auto triple : result)
						if (triple[0] == res[0] && triple[1] == res[1] && triple[2] == res[2])
						{
							found = true;
							break;
						}
					if (!found)
						result.push_back(res);
				}
			}

	return result;
}
*/
//Version 2: two pointers
vector<vector<int>> threeSum(vector<int>& nums) {
	vector<vector<int>> result;
	if (nums.size() < 3) return result;

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 2; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1]) continue; // same as before, no need to check
		int l = i + 1, r = nums.size() - 1;
		while (l < r)
		{
			int sum = nums[i] + nums[l] + nums[r];
			if (sum < 0) l++;
			else if (sum > 0) r--;
			else {
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


int main()
{
	int a[] = { -1, 0, 1, 2, -1, -4 };
//	int a[] = { -3, -3, -2, -2, -1, -1, -1, 0, 0, 0, 1, 1, 1, 1, 2, 2, 3, 3 };
//	int a[] = { 12, 0, 3, -14, 5, -11, 11, -5, -2, -1, 6, -7, -10, 1, 4, 1, 1, 9, -3, 6, -15, 0, 6, 1, 6, -12, 3, 7, 11, -6, -8, 0, 9, 3, -7, -1, 7, -10, 1, 13, -4, -7, -9, -7, 9, 3, 1, -13, -3, 13, 8, -11, -9, -8, -3, 4, -13, 7, -11, 5, -14, -4, -9, 10, 6, -9, -6, -9, -12, 11, -11, -9, 11, -5, 0, -3, 13, -14, -1, -13, 7, -7, 14, 5, 0, -4, -6, -6, -11, -2, 14, -10, 2, 12, 8, -7, -11, -13, -9, 14, 5, -5, -9, 1, -2, 6, 5, -12, -1, -10, -9, -9, -10, 12, 11 };
	vector<int> av(a, a + sizeof(a) / sizeof(a[0]));

	for (auto ans : threeSum(av))
	{
		for_each(ans.begin(), ans.end(), [](int n) { cout << n << " "; }); //just to show that we could
		cout << endl;
	}

	system("pause");
	return 0;
}