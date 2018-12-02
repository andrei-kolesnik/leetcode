/*
LeetCode 948. Bag of Tokens
https://leetcode.com/problems/bag-of-tokens/

You have an initial power P, an initial score of 0 points, and a bag of tokens.

Each token can be used at most once, has a value token[i], and has potentially two ways to use it.

If we have at least token[i] power, we may play the token face up, losing token[i] power, and gaining 1 point.
If we have at least 1 point, we may play the token face down, gaining token[i] power, and losing 1 point.
Return the largest number of points we can have after playing any number of tokens.

Example 1:
Input: tokens = [100], P = 50
Output: 0

Example 2:
Input: tokens = [100,200], P = 150
Output: 1
cccccc
Example 3:
Input: tokens = [100,200,300,400], P = 200
Output: 2

Note:
tokens.length <= 1000
0 <= tokens[i] < 10000
0 <= P < 10000
*/

#include <bits/stdc++.h>

using namespace std;

struct score
{
	int pwr;
	int pts;
};

int bagOfTokensScore(vector<int>& tokens, int P) { 
	score sc{P, 0};
	sort(tokens.begin(), tokens.end());

//	cout << "0:" << setw(3) << sc.pwr << " " << sc.pts << endl;
	int toks = tokens.size(), left = 0, right = toks - 1;
	while (left <= right)
	{
		if (tokens[left] <= sc.pwr) // use the least expensive token for a point if we can
		{
			sc.pwr -= tokens[left];
			sc.pts++;
			left++;
		}
		else if (sc.pts) // otherwise use a point to get the maximum power token
		{
			sc.pwr += tokens[right];
			sc.pts--;
			right--;
		}
		else break;
//		cout << "1:" << setw(3) << sc.pwr << " " << sc.pts << " " << setw(3) << endl;
	}
		
	right++;
	while (right < toks) //use all the power we have left to get points
	{
		if (tokens[right] <= sc.pwr)
		{
			sc.pwr -= tokens[right];
			sc.pts++;
			right++;
		}
		else break;
//		cout << "2:" << setw(3) << sc.pwr << " " << sc.pts << " " << setw(3) << endl;
	}
//	cout << "3:" << setw(3) << sc.pwr << " " << sc.pts << " " << setw(3) << endl;
	return sc.pts;
}

void check(int tokens[], int size, int power, int expected) {
	vector<int> tokensv(tokens, tokens + size);
	int actual = bagOfTokensScore(tokensv, power);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 100 };
	check(a1, 1, 50, 0);

	int a2[] = { 100, 200 };
	check(a2, 2, 150, 1);

	int a3[] = { 100,200,300,400 }; 
	check(a3, 4, 200, 2);

	int a4[] = { 81,91,31 };
	check(a4, 3, 73, 1);

	system("pause");
	return 0;
}
