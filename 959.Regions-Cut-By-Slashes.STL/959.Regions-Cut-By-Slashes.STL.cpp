/*
LeetCode 959. Regions Cut By Slashes
https://leetcode.com/problems/regions-cut-by-slashes/

Input 1:
[
  " /",
  "/ "
]
Output 1: 2

Input 2:
[
  " /",
  "  "
]
Output 2: 1

Input 3:
[
  "\\/",
  "/\\"
]
Output 3: 4

Input 4:
[
  "/\\",
  "\\/"
]
Output 4: 5

Input 5:
[
  "//",
  "/ "
]
Output 5: 3
*/
#include <bits/stdc++.h>

using namespace std;

const int NULLVAL = -1;

class DisjoinedSet {
private:
	vector<int> parents;
	vector<int> sizes;
	vector<int> items;
public:
	DisjoinedSet(int n) {
		parents.resize(n, NULLVAL);
		sizes.resize(n, 1);
	}
	int Find(int val) {
		if (parents[val] == NULLVAL)
			return val;
		return Find(parents[val]);
	}
	void Union(int val1, int val2)
	{
		if (val1 == NULLVAL || val2 == NULLVAL) return; // out of bounds
		int p1 = Find(val1);
		int p2 = Find(val2);
		if (p1 != p2)
		{
			sizes[p1] += sizes[p2];
			sizes[p2] = 0;
			parents[p2] = p1;
		}
	}
	void Print()
	{
		for (int i = 0; i < parents.size(); i++)
			cout << i << ": " << " " << parents[i] << " (" << sizes[i] << ")" << endl;
		cout << endl;
	}
	int Regions()
	{
		return count_if(parents.begin(), parents.end(), [](int i) { return i == -1 ? 1 : 0; });
	}
};

int subIndex(int i, int j, int N) {
	if (i == NULLVAL || j == NULLVAL) return NULLVAL;
	return ((i * N) + j) * 4;
}

int regionsBySlashes(vector<string>& grid) {
	int N = grid.size();
	if (N < 1) return 0;
	DisjoinedSet ds(N * N * 4); //each square will have four regions
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			char ch = grid[i][j];
			int ind = subIndex(i, j, N);

			int u = i > 0 ? subIndex(i - 1, j, N) + 2 : NULLVAL;
			int l = j > 0 ? subIndex(i, j - 1, N) + 1 : NULLVAL;
			int d = i < N - 1 ? subIndex(i + 1, j, N) : NULLVAL;
			int r = j < N - 1 ? subIndex(i, j + 1, N) + 3 : NULLVAL;

			switch (ch)
			{
			case ' ': 
				ds.Union(ind, ind + 1);
				ds.Union(ind, ind + 2);
				ds.Union(ind, ind + 3);
				break;
			case '/': 
				ds.Union(ind, ind + 3);
				ds.Union(ind + 1, ind + 2);
				break;
			case '\\': 
				ds.Union(ind, ind + 1);
				ds.Union(ind + 2, ind + 3);
				break;
			}
			ds.Union(ind, u);
			ds.Union(ind + 1, r);
			ds.Union(ind + 2, d);
			ds.Union(ind + 3, l);
		}
	//ds.Print();//debug print
	return ds.Regions();
}

void check(string slashes[], int size, int expected) {
	vector<string> v(slashes, slashes + size);
	int actual = regionsBySlashes(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	string a1[] = { " /", "/ "};
	check(a1, 2, 2);

	string a2[] = { " /", "  " };
	check(a2, 2, 1);

	string a3[] = { "\\/", "/\\" };
	check(a3, 2, 4);

	string a4[] = { "/\\", "\\/" };
	check(a4, 2, 5);

	string a5[] = { "//", "/ " };
	check(a5, 2, 3);

	system("pause");
	return 0;
}