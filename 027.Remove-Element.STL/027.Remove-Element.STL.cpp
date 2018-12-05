/*
LeetCode 27. Remove Element
https://leetcode.com/problems/remove-element/

Input 1: = [3,2,2,3], val = 3
Output 1: = [2, 2], len = 2

Input 2 = [0,1,2,2,3,0,4,2], val = 2
Output 2: [0, 1, 3, 0, 4] (in any order), len = 5
*/

#include <bits/stdc++.h>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	int size = nums.size();
	if (!size) return 0;
	for (size_t i = 0; i < size - 1; i++)
		for (size_t j = i + 1; j < size; j++)
			if (nums[i] == val)
			{
				nums[i] = nums[j];
				nums[j] = val;
			}
	int result = size;
	while (result > 0 && nums[result-1] == val)
		result--;
	return result;
}

void check(int a[], int size, int val, int expected) {
	vector<int> v(a, a + size);
	int actual = removeElement(v, val);

	for (int i = 0; i < size /*len*/; i++)
		cout << setw(3) << v[i];
	cout << endl;

	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int nums1[] = { 3,2,2,3 };
	check(nums1, 4, 2, 2);

	int nums2[] = { 0,1,2,2,3,0,4,2 };
	check(nums2, 8, 2, 5);

	int nums3[] = { 1, 1 };
	check(nums3, 2, 1, 0);

	int nums4[] = { 1 };
	check(nums4, 1, 1, 0);

	system("pause");
	return 0;
}
