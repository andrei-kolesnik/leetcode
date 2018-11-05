//https://leetcode.com/problems/generate-parentheses/
//Sample Input:
//3
//
//Sample Output:
//"()()()"
//"()(())"
//"(())()"
//"(()())"
//"((()))"

#include <bits/stdc++.h>

using namespace std;

#define LEFT '('
#define RIGHT ')'

void generateParenthesisRec(string str, vector<string> &V, int left, int right, int level)
{
	if (!left)
	{
		if (!right)
		{
			V.push_back(str);
			return;
		}
		V.push_back(str.append(right, RIGHT));
		return;
	}
	if (level > 0)
		generateParenthesisRec(str + RIGHT, V, left, right - 1, level - 1);
	generateParenthesisRec(str + LEFT, V, left - 1, right, level + 1);
}

vector<string> generateParenthesis(int n) {
	vector<string> result;
	if (n > 0) generateParenthesisRec("", result, n, n, 0);
	return result;
}

int main()
{
	vector<string> V = generateParenthesis(3);
	for (auto v : V)
		cout << v << endl;
	system("pause");
	return 0;
}