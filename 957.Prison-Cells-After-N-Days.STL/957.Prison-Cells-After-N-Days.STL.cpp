/*
LeetCode 957. Prison Cells After N Days
https://leetcode.com/problems/prison-cells-after-n-days/

Input 1: cells = [0,1,0,1,1,0,0,1], N = 7
Output 1: [0,0,1,1,0,0,0,0]

Input 2: cells = [1,0,0,1,0,0,1,0], N = 1000000000
Output 2: [0,0,1,1,1,1,1,0]
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> prisonAfterNDays(vector<int>& cells, int N) {
	N = N % 14 + 14; //the trick in this problem is to detect the 14 day loop in the daily outcomes
	vector<int> result(cells);
	for (int d = 1; d <= N; d++)
	{
		cells = result;
		result[0] = 0;
		for (int i = 1; i < cells.size() - 1; i++)
			if (cells[i - 1] == cells[i + 1])
				result[i] = 1;
			else
				result[i] = 0;
		result[cells.size() - 1] = 0;
	}
	return result;
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	for (auto c : prisonAfterNDays(v, expected))
		cout << c << " ";
	cout << endl;
}

int main()
{
	int a1[] = { 0,1,0,1,1,0,0,1 }; //0,0,1,1,0,0,0,0
	check(a1, 8, 7);

	int a2[] = { 1,0,0,1,0,0,1,0 }; //0,1,1,0,1,1,1,0
	check(a2, 8, 1000000000);
	
	int a3[] = { 1,0,0,1,0,0,0,1 }; //0,1,1,0,1,1,1,0
	check(a3, 8, 826); //this is a good test case becase 826 % 14 = 0

	system("pause");
	return 0;
}

