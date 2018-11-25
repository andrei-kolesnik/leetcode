/*
LeetCode 946. Validate Stack Sequences
https://leetcode.com/problems/validate-stack-sequences/
Given two sequences pushed and popped with distinct values, return true if and only if this could have been the result of a sequence of push and pop operations on an initially empty stack.

Example 1:
Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4), pop() -> 4,
push(5), pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:
Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

Note:
0 <= pushed.length == popped.length <= 1000
0 <= pushed[i], popped[i] < 1000
pushed is a permutation of popped.
pushed and popped have distinct values.
*/
#include <bits/stdc++.h>

using namespace std;

bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
	if (pushed.size() != popped.size()) return false;
	if (pushed.size() == 0 && popped.size() == 0) return true;

	vector<int> stack;
	while (popped.size())
	{
		stack.push_back(popped.back());
		popped.erase(popped.end() - 1);
		while (stack.size() && stack.back() == pushed.back())
		{
			pushed.erase(pushed.end() - 1);
			stack.erase(stack.end() - 1);
		}
	}
	return (pushed.size() == 0 && popped.size() == 0 && stack.size() == 0);
}

void check(int pushed[], int popped[], int size, bool expected) {
	vector<int> pushedv(pushed, pushed + size);
	vector<int> poppedv(popped, popped + size);
	bool actual = validateStackSequences(pushedv, poppedv);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int pushed1[] = { 1, 2, 3, 4, 5 };
	int popped1[] = { 4, 5, 3, 2, 1 };
	check(pushed1, popped1, 5, true);

	int pushed2[] = { 1, 2, 3, 4, 5 };
	int popped2[] = { 4, 3, 5, 1, 2 };
	check(pushed2, popped2, 5, false);

	int pushed3[] = { 2, 1, 0 };
	int popped3[] = { 1, 2, 0 };
	check(pushed3, popped3, 3, true);

	int pushed4[] = { 1, 0, 3, 2 };
	int popped4[] = { 0, 1, 2, 3 };
	check(pushed4, popped4, 4, true);

	system("pause");
	return 0;
}
