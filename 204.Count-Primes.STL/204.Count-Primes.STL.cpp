/*
LeetCode 204. Count Primes
https://leetcode.com/problems/count-primes/
Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

#include <bits/stdc++.h>

using namespace std;

int countPrimes(int n) {
	if (n < 2) return 0;
	vector<bool> Numb3rs(n, true); // could have used bitset, but it needs to know the size at the compile time
	Numb3rs[0] = Numb3rs[1] = false;
	for (int i = 2; i <= sqrt(n); i++)
		if (Numb3rs[i])
			for (int j = i * i; j < n; j += i) // "less than n", so n is not included
				Numb3rs[j] = false;
	return count(Numb3rs.begin(), Numb3rs.end(), true);
}

void check(int n, int expected) {
	int actual = countPrimes(n);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	check(0, 0);
	check(1, 0);
	check(2, 0);
	check(10, 4);
	check(97, 24);
	check(100, 25);
	system("pause");
	return 0;
}
