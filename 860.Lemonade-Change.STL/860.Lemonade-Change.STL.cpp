/*
LeetCode 860. Lemonade Change
https://leetcode.com/problems/lemonade-change/
Input 1: [5,5,5,10,20]
Output 1: true

Input 2: [5,5,10]
Output 2: true

Input 3: [10,10]
Output 3: false

Input 4: [5,5,10,10,20]
Output 4: false
*/
#include <bits/stdc++.h>

using namespace std;

class LemonadeStand {
private:	
	map<int, int> CashRegister;
public:
	LemonadeStand() {}
	bool MakePayment(int bill)
	{
		if (bill < 5) return false;
		if (bill == 5) {
			CashRegister[bill]++;
			return true;
		}
		if (bill == 10) {
			if (CashRegister[5] >= 1)
			{
				CashRegister[10]++;
				CashRegister[5]--;
				return true;
			}
			return false;
		}
		if (bill == 20)
		{
			if (CashRegister[10] >= 1 && CashRegister[5] >= 1)
			{
				CashRegister[20]++;
				CashRegister[10]--;
				CashRegister[5]--;
				return true;
			}
			if (CashRegister[5] >= 3)
			{
				CashRegister[20]++;
				CashRegister[5]-=3;
				return true;
			}
			return false;
		}
	}
};

bool lemonadeChange(vector<int>& bills) {
	LemonadeStand ls;
	for (auto bill : bills)
		if (!ls.MakePayment(bill))
		return false;
	return true;
}

void check(int a[], int size, bool expected) {
	vector<int> v(a, a + size);
	bool actual = lemonadeChange(v);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 5,5,5,10,20 };
	check(a1, 5, true);

	int a2[] = { 5,5,10 };
	check(a2, 3, true);

	int a3[] = { 10,10 };
	check(a3, 2, false);

	int a4[] = { 5,5,10,10,20 };
	check(a4, 5, false);

	int a5[] = { 0 };
	check(a5, 0, true);

	int a6[] = { 5 };
	check(a6, 1, true);

	int a7[] = { 10 };
	check(a7, 1, false);

	system("pause");
	return 0;
}
