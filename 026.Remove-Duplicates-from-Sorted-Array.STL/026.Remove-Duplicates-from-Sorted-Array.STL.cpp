/*
LeetCode 26. Remove Duplicates from Sorted Array (in place)
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Input 1: [1,1,2]
Output 1: [1,2]; len = 2

Input 2: [0,0,1,1,1,2,2,3,3,4]
Output 2: [0,1,2,3,4]; len = 5
*/
#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int result = nums.size();
	if (result < 2) return result;
	for (size_t i = 0; i < result - 1; i++)
		while (nums[i] == nums[i + 1] && i < result - 1)
		{
			for (size_t j = i + 1; j < result - 1; j++)
				nums[j] = nums[j + 1];
			result--;
		}
	return result;
}

void check(int a[], int size, int expected) {
	vector<int> v(a, a + size);
	int actual = removeDuplicates(v);

	for (int i = 0; i < size /*len*/; i++)
		cout << setw(3) << a[i];
	cout << endl;

	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int nums1[] = { 1, 1, 2 };
	check(nums1, 3, 2);

	int nums2[] = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
	check(nums2, 10, 5);

	int nums3[] = { 1, 1 };
	check(nums3, 2, 1);

	int nums4[] = { 1, 2, 2 };
	check(nums4, 3, 2);

	system("pause");
	return 0;
}
