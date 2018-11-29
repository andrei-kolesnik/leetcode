/*
LeetCode 19. Remove Nth Node From End of List
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Input:
1->2->3->4->5
n = 2.
Output:
1->2->3->5
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

ListNode* removeNthFromEnd(ListNode* head, int n) {
	if (n <= 0 || !head) return head; //just in case they try to trick us
	ListNode *result = head, *current = head, *prev = head;
	for (int i = 0; i < n - 1; i++)
	{
		if (!current) return head; // if Nth element does not exists, just return the unchanged list
		current = current->next;
	}
	while (current->next)
	{
		current = current->next;
		prev = result;
		result = result->next;
	}
	if (result == head)
		head = head->next;
	else
		prev->next = result->next;
	delete result;
	return head;
}

int main()
{
	ListNode *L1 = NULL;
	L1 = new ListNode(5);
	L1 = new ListNode(4, L1);
	L1 = new ListNode(3, L1);
	L1 = new ListNode(2, L1);
	L1 = new ListNode(1, L1);

	PrintList(L1);
	PrintList(removeNthFromEnd(L1, 2)); //1->2->3->5

	system("pause");
	return 0;
}
