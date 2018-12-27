/*
LeetCode 70. Climbing Stairs
https://leetcode.com/problems/climbing-stairs/

Input 1: 2
Output 1: 2

Input 2: 3
Output 2: 3
*/

#include <bits/stdc++.h>

using namespace std;

map<int, int> solutions;

int climbStairs(int n) {
	if (n <= 0) return 1;
	if (n == 1) return 1;
	if (solutions[n] > 0) return solutions[n];
	int result = climbStairs(n - 1) + climbStairs(n - 2);
	solutions[n] = result;
	return result;
}

void check(int n, int expected) {
	int actual = climbStairs(n);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check(2, 2);
	check(3, 3);
	check(4, 5);
	system("pause");
	return 0;
}
