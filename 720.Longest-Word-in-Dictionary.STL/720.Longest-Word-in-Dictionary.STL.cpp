/*
LeetCode 720. Longest Word in Dictionary
https://leetcode.com/problems/longest-word-in-dictionary/
Input 1: ["w","wo","wor","worl", "world"]
Output 1: "world"

Input 2: ["a", "banana", "app", "appl", "ap", "apply", "apple"]
Output 2: "apple" ( < "apply")
*/
#include <bits/stdc++.h>

using namespace std;

class Trie {
private:
	struct TrieNode {
		map<char, TrieNode*> letters;
		bool WholeWord;
		TrieNode() : WholeWord(false) {}
	};
	TrieNode* root;

	string doLongest(TrieNode* p) {
		string result = "";
		for (auto letter : p->letters)
			if (letter.second->WholeWord)
			{
				string new_result = letter.first + doLongest(letter.second);
				if (new_result.size() > result.size() ||
					new_result.size() == result.size() && new_result < result)
					result = new_result;
			}
		return result;
	}

	void doPrint(TrieNode* p, string prefix = "") {
		if (!p) return;
		for (auto letter : p->letters)
		{
			if (letter.second->WholeWord)
				cout << prefix << letter.first << endl;
			doPrint(letter.second, prefix + letter.first);
		}
	}

public:
	Trie() { root = new TrieNode(); }

	/* Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* current = root;
		for (auto ch : word)
		{
			map<char, TrieNode*>::iterator it = current->letters.find(ch);
			if (it == current->letters.end())
			{
				TrieNode* p = new TrieNode();
				current->letters[ch] = p;
				current = p;
			}
			else
				current = it->second;
		}
		current->WholeWord = true;
	}

	/* find the longest chain of words */
	string longest() {
		return doLongest(root);
	}

	/* Print all the words */
	void print() {
		doPrint(root, "");
	}
};

string longestWord(vector<string>& words) {
	Trie trie;
	for (auto word: words)
		trie.insert(word);
	trie.print();
	return trie.longest();
}

void check(const char** a, int size, string expected)
{
	vector<string> av;
	for (size_t i = 0; i < size; i++)
		av.push_back(a[i]);
	string actual = longestWord(av);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	const char* a1[] = {"w", "wo", "wor", "worl", "world"};
	check(a1, 0, ""); // empty test case
	check(a1, 1, "w"); // trivial test case
	check(a1, 5, "world"); // straighforward test case

	const char* a2[] = { "a", "banana", "app", "appl", "ap", "apply", "apple" };
	check(a2, 7, "apple"); // test case with two possible answers

	system("pause");
	return 0;
}
