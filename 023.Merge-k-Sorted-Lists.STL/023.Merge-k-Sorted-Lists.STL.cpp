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

// Version 1: straightforward heap-sort (n*k*log(n*k)), same as if the lists are not sorted
ListNode* mergeKLists1(vector<ListNode*>& lists) {
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

// Version 2: using vectors, taking advantage in the vectors being sorted (n*k*log(k))
struct ListData {
	int value;
	size_t list;
	size_t index;
	ListData(int v, size_t l, size_t i) : value(v), list(l), index(i) {}
};

class ListDataComparison
{
	bool reverse;
public:
	ListDataComparison(const bool& revparam = false)
	{
		reverse = revparam;
	}
	bool operator() (const ListData& lhs, const ListData&rhs) const
	{
		if (reverse) return (lhs.value < rhs.value);
		else return (lhs.value > rhs.value);
	}
};

void printV(const vector<int>& v)
{
	for (auto a: v)
		cout << setw(3) << right << a;
	cout << endl;
}

vector<int> mergeKLists2(vector<vector<int>>& lists) {
	vector<int> result;
	priority_queue<ListData, vector<ListData>, ListDataComparison> heap; 
	for (size_t i = 0; i < lists.size(); i++)
		if (lists[i].size() > 0)
			heap.emplace(lists[i][0], i, 0);

	while (!heap.empty())
	{
		ListData smallest = heap.top();
		result.push_back(smallest.value);
		heap.pop();
		if (smallest.index + 1 < lists[smallest.list].size())
			heap.emplace(lists[smallest.list][smallest.index+1], smallest.list, smallest.index + 1);
	}

	return result;
}

int main()
{
	// Version 1
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
	PrintList(mergeKLists1(lists));

	// Version 2
	int a1[] = { 1, 10, 11, 15 };
	vector<int> v1(a1, a1 + sizeof(a1) / sizeof(a1[0]));
	int a2[] = { 2,  4,  9, 14 };
	vector<int> v2(a2, a2 + sizeof(a2) / sizeof(a2[0]));
	int a3[] = { 5,  6,  8, 16 };
	vector<int> v3(a3, a3 + sizeof(a3) / sizeof(a3[0]));
	int a4[] = { 3,  7, 12, 13 };
	vector<int> v4(a4, a4 + sizeof(a4) / sizeof(a4[0]));
	vector<vector<int>> vv;
	vv.push_back(v1);
	vv.push_back(v2);
	vv.push_back(v3);
	vv.push_back(v4);
	printV(mergeKLists2(vv));

	system("pause");
	return 0;
}
