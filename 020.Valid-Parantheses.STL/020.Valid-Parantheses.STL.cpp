//Leetcode #20: Valid Parantheses
//https://leetcode.com/problems/valid-parentheses/
//Example 1:
//Input: "()"
//Output : true
//
//Example 2 :
//Input : "()[]{}"
//Output : true
//
//Example 3 :
//Input : "(]"
//Output : false
//
//Example 4 :
//Input : "([)]"
//Output : false
//
//Example 5 :
//Input : "{[]}"
//Output : true

#include <bits/stdc++.h>

using namespace std;

bool isValid(string s)
{
	stack<char> St;
	for (auto ch : s)
	{
		switch (ch)
		{
		case '(': case '[': case '{': St.push(ch); break;
		case ')': if (!St.size() || St.top() != '(') return false; else St.pop(); break;
		case ']': if (!St.size() || St.top() != '[') return false; else St.pop(); break;
		case '}': if (!St.size() || St.top() != '{') return false; else St.pop(); break;
		default: return false;
		}
	}
	return !St.size();
}

int main()
{
	cout << boolalpha;
	cout << isValid("()") << endl; //true
	cout << isValid("()[]{}") << endl; //true
	cout << isValid("(]") << endl; //false
	cout << isValid("([)]") << endl; //false
	cout << isValid("{[]}") << endl; //true
	cout << isValid("[") << endl; //false
	cout << isValid("]") << endl; //false

	system("pause");
}
