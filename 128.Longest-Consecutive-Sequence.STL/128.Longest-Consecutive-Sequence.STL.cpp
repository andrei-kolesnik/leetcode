/*
LeetCode 128. Longest Consecutive Sequence
https://leetcode.com/problems/longest-consecutive-sequence/
Input: [100, 4, 200, 1, 3, 2]
Output: 4
*/
#include <bits/stdc++.h>

using namespace std;

struct UnionSet {
	int parent;
	int size;
	UnionSet(int p, int s) : parent(p), size(s) {}
};

class DisjointSet {
private:
	map<int, UnionSet*> Set;
public:
	int maxSize;
	DisjointSet() : maxSize(0) {}
	void Union(int val) {
		map<int, UnionSet*>::iterator it = Set.find(val);
		if (it != Set.end()) return; // we have already seen this number
		UnionSet* us = new UnionSet(val, 1);
		maxSize = max(maxSize, 1);
		Set[val] = us;
		it = Set.find(val + 1);
		if (it != Set.end()) // can be attached to the beginning of the existing set
		{
			it->second->parent = val;
			us->size = it->second->size + 1;
			maxSize = max(maxSize, us->size);
		}
		it = Set.find(--val);
		if (it != Set.end()) // can be attached to the end of the existing set
		{
			us->parent = val;
			while (it->second->parent != val)
			{
				val = it->second->parent;
				it = Set.find(val);
			}
			it->second->size += us->size;
			maxSize = max(maxSize, it->second->size);
		}
	}
};

int longestConsecutive(vector<int>& nums) {
	DisjointSet ds;
	for (auto n : nums)
		ds.Union(n);
	return ds.maxSize;
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = longestConsecutive(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 100, 4, 200, 1, 3, 2 };
	check(a1, 6, 4);

	int a2[] = { 1, 3, 5, 2, 4, 6 };
	check(a2, 6, 6);

	int a3[] = { 0 };
	check(a3, 1, 1);

	int a4[] = { 0 };
	check(a4, 0, 0);

	system("pause");
	return 0;
}
