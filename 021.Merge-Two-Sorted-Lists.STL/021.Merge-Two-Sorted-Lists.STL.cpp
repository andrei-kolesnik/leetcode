//Leetcode #21: Merge Two Sorted Lists
//https://leetcode.com/problems/merge-two-sorted-lists/
//Input: 
//1->2->4, 1->3->4
//Output: 
//1->1->2->3->4->4

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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
	ListNode *result = NULL, *end = NULL, *p = NULL, **l;
	while (l1 || l2)
	{
		if (!l1) l = &l2;
		else if (!l2) l = &l1;
		else l = l2->val < l1->val ? &l2 : &l1;
		p = new ListNode((*l)->val);
		*l = (*l)->next;
		if (!result) end = result = p;
		else end->next = p;
		end = p;
	}

	return result;
}

int main()
{
	ListNode *L1 = NULL, *L2 = NULL;
	L1 = new ListNode(4);
	L1 = new ListNode(2, L1);
	L1 = new ListNode(1, L1);
	L2 = new ListNode(2);
	L2 = new ListNode(1, L2);
	L2 = new ListNode(1, L2);

	PrintList(L1);
	PrintList(L2);
	PrintList(mergeTwoLists(L1, L2));

	system("pause");
	return 0;
}
