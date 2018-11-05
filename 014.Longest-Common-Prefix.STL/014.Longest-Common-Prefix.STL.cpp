//Leetcode #14: Longest Common Prefix
//https://leetcode.com/problems/longest-common-prefix/
//Example 1:
//
//Input: ["flower", "flow", "flight"]
//Output : "fl"
//
//Example 2:
//
//Input : ["dog", "racecar", "car"]
//Output : ""
//Explanation : There is no common prefix among the input strings.

#include <bits/stdc++.h>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	if (strs.size() == 0) return "";

	string first = strs.back();
	strs.pop_back();

	while (first.length())
	{
		bool found = true;
		for (auto s : strs)
			if (s.find(first) != 0)
			{
				found = false;
				break;
			}
		if (found) return first;
		first.erase(first.end() - 1);
	}

	return first;
}

int main()
{
	vector<string> S;
	S.push_back("flower");
	S.push_back("flow");
	S.push_back("flight");
	cout << longestCommonPrefix(S) << endl; //fl

	S.clear();
	S.push_back("dog");
	S.push_back("racecar");
	S.push_back("car");
	cout << longestCommonPrefix(S) << endl; //""

	system("pause");
}
