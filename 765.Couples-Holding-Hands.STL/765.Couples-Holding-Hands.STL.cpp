/*
LeetCode 765. Couples Holding Hands
https://leetcode.com/problems/couples-holding-hands/
Input 1: row = [0, 2, 1, 3]
Output 1: 1

Input 2: row = [3, 2, 0, 1]
Output 2: 0
*/
#include <bits/stdc++.h>

using namespace std;

const int NULLVAL = -1;

class DisjoinedSet {
private:
	vector<int> parent;
	vector<int> sizes;
	vector<int> pairs;
public:
	DisjoinedSet(int n) {
		parent.resize(n/2, NULLVAL);
		sizes.resize(n/2, 1);
		pairs.resize(n, NULLVAL);
	}
	void Add(int ind, int val) {
		pairs[val] = ind;
	}
	int Pair(int ind) { return pairs[ind]; }
	int Find(int val) {
		if (parent[val] == NULLVAL)
			return val;
		return Find(parent[val]);
	}
	void Union(int val1, int val2)
	{
		int p1 = Find(val1);
		int p2 = Find(val2);
		if (p1 != p2)
		{
			sizes[p2] += sizes[p1];
			sizes[p1] = 0;
			parent[p1] = p2;
		}
	}
	//void Print(vector<int>& row)
	//{
	//	for (int i = 0; i < parent.size(); i++)
	//		cout << i << ": " << " " << parent[i] << " (" << sizes[i] << ")" << endl;
	//	cout << endl;
	//}
	int Swaps()
	{
		int result = 0;
		for (auto s : sizes)
			if (s > 1)
				result += s - 1;
		return result;
	}
};

int minSwapsCouples(vector<int>& row) {
	DisjoinedSet ds(row.size());
	for (int i = 0; i < row.size(); i++)
		ds.Add(i/2, row[i]);
		
	for (int i = 0; i < row.size(); i += 2)
	{
		int p1 = ds.Pair(i);
		int p2 = ds.Pair(i+1);
		int i1 = ds.Find(p1);
		int i2 = ds.Find(p2);
		if (i1 != i2)
			ds.Union(i1, i2);
	}
	//ds.Print(row);
	return ds.Swaps();
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = minSwapsCouples(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 0, 2, 1, 3 };
	check(a1, 4, 1);

	int a2[] = { 3, 2, 0, 1 };
	check(a2, 4, 0);

	int a3[] = { 1, 2, 3, 4, 5, 0 };
	check(a3, 6, 2);

	system("pause");
	return 0;
}

