/*
LeetCode# 11: Container With Most Water
https://leetcode.com/problems/container-with-most-water/

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

#include <bits/stdc++.h>

using namespace std;

//Version 1: O(n^2)
int maxArea(vector<int>& height) {
	int result = 0;

	for (int i = 0; i < height.size() - 1; i++)
		for (int j = i + 1; j < height.size(); j++)
		{
			int area = (j - i) * (min(height[i], height[j]));
			result = max(area, result);
		}

	return result;
}

/*
//Version 2: O(n) (as suggested on the site)
int maxArea2(vector<int>& height) {
	int result = 0, l = 0, r = height.size() - 1;
	while (l < r) {
		result = max(result, min(height[l], height[r]) * (r - l));
		if (height[l] < height[r])
			l++;
		else
			r--;
	}
	return result;
}
*/

int main()
{
	int a[] = { 1,8,6,2,5,4,8,3,7 };
	vector<int> av(a, a + sizeof(a) / sizeof(a[0]));

	cout << maxArea(av) << endl; // 49
	system("pause");
	return 0;
}