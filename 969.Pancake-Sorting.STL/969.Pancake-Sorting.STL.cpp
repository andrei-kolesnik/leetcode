/*
LeetCode 969. Pancake Sorting
https://leetcode.com/problems/pancake-sorting/

Input 1: [3,2,4,1]
Output 1: [4,2,4,3]

Input 2: [1,2,3]
Output 2: [] // already sorted; [3, 3] is also OK
*/
#include <bits/stdc++.h>

using namespace std;

void print(vector<int>& A) {
	for (auto a : A) cout << a << " ";
	cout << endl;
}

bool sorted(vector<int>& A) {
	for (int i = 0; i < A.size() - 1; i++)
		if (A[i + 1] < A[i]) return false;
	return true;
}

void pancakeFlip(vector<int>& A, int k, vector<int> &result) {
	result.push_back(k);
	k--;
	for (int i = 0; i <= k / 2; i++)
	{
		int swap = A[i];
		A[i] = A[k - i];
		A[k - i] = swap;
	}
	print(A);
}

vector<int> pancakeSort(vector<int>& A) {
	vector<int> result;
	int N = A.size();
	while (!sorted(A))
	{
		vector<int>::iterator max_it = max_element(A.begin(), A.begin() + N);
		int dist = distance(A.begin(), max_it);
		if (dist < N - 1)
		{
			if (dist > 0)
				pancakeFlip(A, dist + 1, result);
			pancakeFlip(A, N, result);
		}
		N--;
	}
	return result;
}

void check(int nums[], int size) {
	vector<int> v(nums, nums + size);
	vector<int> ans = pancakeSort(v);
	cout << "Answer: ";
	for (auto a : ans) cout << a << " ";
	cout << endl;
}

int main()
{
	int a1[] = { 3,2,4,1 };
	check(a1, 4);

	int a2[] = { 1,2,3 };
	check(a2, 3);

	system("pause");
	return 0;
}
