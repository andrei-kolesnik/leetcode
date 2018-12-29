/*
121. Best Time to Buy and Sell Stock
https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Input 1: [7,1,5,3,6,4]
Output 1: 5

Input 2: [7,6,4,3,1]
Output 2: 0
*/
#include <bits/stdc++.h>

using namespace std;

int maxProfit(vector<int>& prices) {
	if (prices.size() < 2) return 0;
	int min_so_far = INT32_MAX, result = 0;
	for (auto a : prices)
		if (a > min_so_far) result = max(result, a - min_so_far);
		else min_so_far = a;
	return result;
}

void check(int nums[], int size, int expected) {
	vector<int> v(nums, nums + size);
	int actual = maxProfit(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 7,1,5,3,6,4 };
	check(a1, 0, 0);
	check(a1, 1, 0);
	check(a1, 2, 0);
	check(a1, 3, 4);
	check(a1, 6, 5);

	int a2[] = { 7,6,4,3,1 };
	check(a2, 5, 0);

	system("pause");
	return 0;
}
