/*
LeetCode 35. Search Insert Position
https://leetcode.com/problems/search-insert-position/

Input 1: [1,3,5,6], 5
Output 1: 2

Input 2: [1,3,5,6], 2
Output 2: 1

Input 3: [1,3,5,6], 7
Output 3: 4

Input 4: [1,3,5,6], 0
Output 4: 0
*/
#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
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
	return left;
}

void check(int nums[], int size, int target, int expected) {
	int actual = searchInsert(nums, size, target);
	printf("%s (%d / %d)\n", actual == expected ? "PASS" : "FAIL", expected, actual);
}

int main()
{
	int arr[] = { 1,3,5,6 };
	check(arr, 4, 5, 2);
	check(arr, 4, 2, 1);
	check(arr, 4, 7, 4);
	check(arr, 4, 0, 0);

	getchar(); // pause the program
	return 0;
}
