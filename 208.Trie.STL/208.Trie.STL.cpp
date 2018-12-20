/*
LeetCode 208. Implement Trie (Prefix Tree)
https://leetcode.com/problems/implement-trie-prefix-tree/

Example:
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // returns true
trie.search("app");     // returns false
trie.startsWith("app"); // returns true
trie.insert("app");
trie.search("app");     // returns true
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

	bool doSearch(string word, bool partial) {
		TrieNode* current = root;
		for (auto ch : word)
		{
			map<char, TrieNode*>::iterator it = current->letters.find(ch);
			if (it == current->letters.end())
				return false;
			else
				current = it->second;
		}
		return partial || current->WholeWord;
	}

public:
	/** Initialize your data structure here. */
	Trie() {
		root = new TrieNode();
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		TrieNode* current = root;
		for (auto ch: word)
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

	/** Returns if the word is in the trie. */
	bool search(string word) {
		return doSearch(word, false);
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		return doSearch(prefix, true);
	}
};

int main()
{
	Trie trie;
	cout << boolalpha;
	trie.insert("apple");
	cout << trie.search("apple") << endl;   // returns true
	cout << trie.search("app") << endl;     // returns false
	cout << trie.startsWith("app") << endl; // returns true
	trie.insert("app");
	cout << trie.search("app") << endl;     // returns true

	system("pause");
	return 0;
}
