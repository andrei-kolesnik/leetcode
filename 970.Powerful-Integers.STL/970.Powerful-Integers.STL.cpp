/*
LeetCode 970. Powerful Integers
https://leetcode.com/problems/powerful-integers/

Input 1: x = 2, y = 3, bound = 10
Output 1: [2,3,4,5,7,9,10]

Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
*/

#include <bits/stdc++.h>

using namespace std;

double logbase(double a, double base)
{
	if (base <= 1) return 0;
	return log(a) / log(base);
}

vector<int> powerfulIntegers(int x, int y, int bound) {
	vector<int> result;
	vector<int> X;
	for (int i = 0; i <= logbase(bound, x); i++)
		X.push_back(pow(x, i));
	vector<int> Y;
	for (int i = 0; i <= logbase(bound, y); i++)
		Y.push_back(pow(y, i));
	map<int, int> ans;
	for (auto x : X)
		for (auto y : Y)
			ans[x + y]++;
	for (auto a : ans)
		if (a.first <= bound)
			result.push_back(a.first);
	return result;
}

void check(int x, int y, int bound) {
	vector<int> v = powerfulIntegers(x, y, bound);
	for (auto a : v) cout << a << " ";
	cout << endl;
}

int main()
{
	check(2, 3, 10);
	check(3, 5, 15);
	check(1, 1, 0);

	system("pause");
	return 0;
}
