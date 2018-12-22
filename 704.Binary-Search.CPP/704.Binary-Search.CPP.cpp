/*
LeetCode 704. Binary Search
https://leetcode.com/problems/binary-search/
Input 1: nums = [-1,0,3,5,9,12], target = 9
Output 1: 4

Input 2: nums = [-1,0,3,5,9,12], target = 2
Output 2: -1
*/
#include <stdio.h>

int search(int* nums, int numsSize, int target) {
	int left = 0, right = numsSize - 1, middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (target < nums[middle])
			right = middle - 1;
		else if (target > nums[middle])
			left = middle + 1;
		else
			return middle;
	}
	return -1;
}

void check(int nums[], int size, int target, int expected) {
	int actual = search(nums, size, target);
	printf("%s (%d / %d)\n", actual == expected ? "PASS" : "FAIL", expected, actual);
}

int main()
{
	int arr[] = { -1,0,3,5,9,12 };
	check(arr, 6, 9, 4);
	check(arr, 6, 2, -1);

	int arr1[] = { 1 };
	check(arr1, 0, 1, -1);
	check(arr1, 1, 1, 0);
	check(arr1, 1, 2, -1);

	int arr2[] = { 1, 2 };
	check(arr2, 2, 1, 0);
	check(arr2, 2, 2, 1);
	check(arr2, 2, 3, -1);

	int arr3[] = { 1, 2, 3 };
	check(arr3, 3, 2, 1);
	check(arr3, 3, 3, 2);
	check(arr3, 3, 4, -1);

	getchar(); // pause the program
	return 0;
}
