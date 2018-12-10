/*
LeetCode 23. Merge k Sorted Lists
https://leetcode.com/problems/merge-k-sorted-lists/
Input: 1->4->5,  1->3->4,  2->6
Output: 1->1->2->3->4->4->5->6
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

ListNode* mergeKLists(vector<ListNode*>& lists) {
	ListNode *result = NULL, *p = NULL;
	priority_queue<int, vector<int>, less<int>> heap; //default comparator: less -> max on top
// put all the queues elements into a max heap
	for (auto list : lists)
		while (list)
		{
			heap.push(list->val);
			list = list->next;
		}
// get the top (max) heap element and put it in the result queue, which will end up being sorted in the accending order
	while (!heap.empty())
	{
		p = new ListNode(heap.top()); heap.pop();
		p->next = result;
		result = p;
	}
	return result;
}

int main()
{
	ListNode *L1 = NULL, *L2 = NULL, *L3 = NULL;
	L1 = new ListNode(5);
	L1 = new ListNode(4, L1);
	L1 = new ListNode(1, L1);
	L2 = new ListNode(4);
	L2 = new ListNode(3, L2);
	L2 = new ListNode(1, L2);
	L3 = new ListNode(6);
	L3 = new ListNode(2, L3);
	vector<ListNode*> lists;
	lists.push_back(L1);
	lists.push_back(L2);
	lists.push_back(L3);

	PrintList(L1);
	PrintList(L2);
	PrintList(L3);
	PrintList(mergeKLists(lists));

	system("pause");
	return 0;
}
