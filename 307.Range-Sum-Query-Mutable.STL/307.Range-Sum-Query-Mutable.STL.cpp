/*
LeetCode 307. Range Sum Query - Mutable
https://leetcode.com/problems/range-sum-query-mutable/

Input 1:
nums = [1, 3, 5]
sumRange(0, 2) -> 9
update(1, 2)
sumRange(0, 2) -> 8

Input 2:
nums = [9, -8]
update(0, 3)
sumRange(1, 1) -> -8
sumRange(0, 1) -> -5
update(1, -3)
sumRange(0, 1) -> 0
*/

#include <bits/stdc++.h>

using namespace std;

class NumArray {
private:
	vector<int> stree, original;
	int size, height, st_size;
	int middle(int left, int right) { 
		return left + (right - left) / 2; 
		// better than (right + left) / 2 because of possible INT overflow
	} 

	int buildTree(int left, int right, int ind) {
		if (left == right)
			stree[ind] = original[left];
		else
		{
			int mid = middle(left, right);
			stree[ind] = buildTree(left, mid, ind * 2 + 1) +
				buildTree(mid + 1, right, ind * 2 + 2);
		}
		return stree[ind];
	}

	int calcSumRange(int left, int right, int i, int j, int ind) {
		if (i <= left && j >= right) // range is inside
			return stree[ind];
		if (right < i || left > j) // range is outside
			return 0;
		int mid = middle(left, right);
		return calcSumRange(left, mid, i, j, ind * 2 + 1) +
			   calcSumRange(mid + 1, right, i, j, ind * 2 + 2);
	}

	void updateTree(int left, int right, int i, int diff, int ind) {
		if (i < left || i > right)	return; 
		stree[ind] += diff;
		if (left != right)
		{
			int mid = middle(left, right);
			updateTree(left, mid, i, diff, 2 * ind + 1);
			updateTree(mid + 1, right, i, diff, 2 * ind + 2);
		}
	}

public:
	NumArray(vector<int> nums) {
		size = nums.size();
		if (size < 1) return;
		height = (int)ceil(log2(size));
		st_size = 2 * (int)pow(2, height) - 1;
		original = nums;
		stree.resize(st_size, 0);
		buildTree(0, size - 1, 0);
	}

	void update(int i, int val) {
		if (i < 0 || i >= size) return; // invalid input
		int diff = val - original[i];
		original[i] = val;
		updateTree(0, size - 1, i, diff, 0);
	}

	int sumRange(int i, int j) {
		if (i > j || i < 0 || j >= size) return 0; // invalid input
		return calcSumRange(0, size - 1, i, j, 0);
	}

	void print() {
		for (size_t i = 0; i < stree.size(); i++)
			cout << i << ": " << stree[i] << endl;;
		cout << endl;
	}
};

int main()
{
// Input 1
	int a1[] = { 1, 3, 5 };
	vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));

	NumArray obj1(v1);
	obj1.print();
	cout << obj1.sumRange(0, 2) << endl; // -> 9
	obj1.update(1, 2);
	cout << obj1.sumRange(0, 2) << endl; // -> 8
	obj1.print();

// Input 2
	int a2[] = { 9, -8 };
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));

	NumArray obj2(v2);
	obj2.print();
	obj2.update(0, 3);
	cout << obj2.sumRange(1, 1) << endl; // -> - 8
	cout << obj2.sumRange(0, 1) << endl; // -> - 5
	obj2.update(1, -3);
	cout << obj2.sumRange(0, 1) << endl; // -> 0
	obj2.print();

	system("pause");
	return 0;
}
