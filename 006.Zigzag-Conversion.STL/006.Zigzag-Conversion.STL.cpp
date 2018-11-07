/*
LeetCode #6: Zigzag Conversion
https://leetcode.com/problems/zigzag-conversion/
Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Explanation:
P   A   H   N
A P L S I I G
Y   I   R

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
*/

#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows) {
	if (!s.size() || !numRows) return "";
	if (numRows == 1 || numRows > s.size()) return s;

	vector<vector<char>> V(numRows);
	int numCols = s.size() / 2 + 1;
	for (auto &v : V)
		v.resize(numCols, ' ');

	int i = 0, j = 0, idir = 1, maxj = 0;
	for (char ch : s)
	{
		V[i][j] = ch;
//debug		cout << i << ":" << j << endl;
		i += idir;
		if (idir < 0) maxj = max(++j, maxj);
		if (i == 0) idir = 1;
		else if (i == numRows - 1) idir = -1;
	}

/*debug
	for (auto V1 : V)
	{
		for (auto v : V1)
			cout << v << " ";
		cout << endl;
	}
	cout << endl;	
*/
	stringstream ss;

	for (i = 0; i < numRows; i++)
		for (j = 0; j <= maxj; j++)
			if (V[i][j] != ' ') ss << V[i][j];

	return ss.str();
}

int main()
{
	string in = "PAYPALISHIRING";
	string out = convert(in, 3);
	assert(out == "PAHNAPLSIIGYIR");
	cout << in << " -> " << out << endl; // PAHNAPLSIIGYIR
	out = convert(in, 4);
	assert(out == "PINALSIGYAHRPI");
	cout << in << " -> " << out << endl; // PAHNAPLSIIGYIR
	system("pause");
	return 0;
}


