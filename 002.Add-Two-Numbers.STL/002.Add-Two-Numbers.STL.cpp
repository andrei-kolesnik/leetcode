/* 
LeetCode #2: Add Two Numbers
https://leetcode.com/problems/add-two-numbers/

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
*/

#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
	ListNode(int x, ListNode* p) : val(x), next(p) {}
};

void PrintList(ListNode* l)
{
	ListNode* p = l;
	while (p)
	{
		cout << p->val << (p->next ? " -> " : "");
		p = p->next;
	}
	cout << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *result = NULL, *end = NULL, *p;
	int pass = 0, x1, x2, sum;
	while (1)
	{
		if (!l1)
		{
			if (!l2) break;
			x1 = 0;
			x2 = l2->val;
			l2 = l2->next;
		}
		else 
		{
			x1 = l1->val;
			l1 = l1->next;
			if (!l2) x2 = 0;
			else
			{
				x2 = l2->val;
				l2 = l2->next;
			}
		}
		sum = x1 + x2 + pass;
		p = new ListNode(sum % 10);
		pass = sum / 10;
		if (!result) end = result = p;
		else end->next = p;
		end = p;
	}

	if (pass)
	{
		p = new ListNode(pass);
		end->next = p;
	}

	return result;
}

int main()
{
	ListNode *L1 = NULL, *L2 = NULL;

	L1 = new ListNode(3);
	L1 = new ListNode(4, L1);
	L1 = new ListNode(2, L1);
	L2 = new ListNode(4);
	L2 = new ListNode(6, L2);
	L2 = new ListNode(5, L2);

	PrintList(L1);
	PrintList(L2);
	PrintList(addTwoNumbers(L1, L2)); // 7 -> 0 -> 8

	L1 = new ListNode(5);
	L2 = new ListNode(5);

	PrintList(L1);
	PrintList(L2);
	PrintList(addTwoNumbers(L1, L2)); // 0 -> 1

	L1 = new ListNode(1);
	L2 = new ListNode(9);
	L2 = new ListNode(9, L2);
	PrintList(L1);
	PrintList(L2);
	PrintList(addTwoNumbers(L1, L2)); // 0 -> 0 -> 1

	system("pause");
	return 0;
}
