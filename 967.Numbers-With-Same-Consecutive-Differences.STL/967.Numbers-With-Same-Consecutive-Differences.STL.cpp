/*
LeetCode 967. Numbers With Same Consecutive Differences
https://leetcode.com/problems/numbers-with-same-consecutive-differences/
Input 1: N = 3, K = 7
Output 1: [181,292,707,818,929]

Input 2: N = 2, K = 1
Output 2: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]
*/
#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
	struct TrieNode {
		map<int, TrieNode*> digits;
	};
	TrieNode* root;
	int N;

	void buildLevel(TrieNode* root, int N, int K, int D, bool bypass = false) {
		if (!root) return;
		if (!N) return;
		if (D - K >= 0 || D + K <= 9 || bypass)
		{
			root->digits[D] = new TrieNode;
			if (D - K >= 0)
				buildLevel(root->digits[D], N - 1, K, D - K);
			if (D + K <= 9)
				buildLevel(root->digits[D], N - 1, K, D + K);
		}
	}

	void doGetResult(TrieNode* p, int n, string prefix, vector<int>& result) {
		if (!p) return;
		for (auto digit : p->digits)
		{
			string new_prefix = prefix;
			new_prefix.push_back(digit.first + '0');
			if (n == 1)
				result.push_back(atoi(new_prefix.c_str()));
			else
				doGetResult(digit.second, n - 1, new_prefix, result);
		}
	}

public:
	Trie(int N, int K) : N(N) {
		root = new TrieNode;
		for (int i = (N == 1 ? 0 : 1); i <= 9; i++)
			buildLevel(root, N, K, i, true);
	}

	void getResult(vector<int>& result) {
		doGetResult(root, N, "", result);
	}
};

vector<int> numsSameConsecDiff(int N, int K) {
	vector<int> result;
	Trie trie(N, K);
	trie.getResult(result);
	return result;
}

void check(int N, int K) {
	for (auto a : numsSameConsecDiff(N, K))
		cout << a << " ";
	cout << endl;
}

int main() {
	check(1, 0);
	check(2, 0);
	check(3, 0);
	check(1, 6);
	check(2, 1);
	check(3, 7);
	system("pause");
	return 0;
}
