/*
LeetCode 94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/

Input: [1,null,2,3]
   1
	\
	 2
	/
   3

Output: [1,3,2]
*/
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	TreeNode(int x, TreeNode *l, TreeNode *r) : val(x), left(l), right(r) {}
};

void inorderTraversalV(TreeNode* root, vector<int>& v) {
	if (!root) return;
	inorderTraversalV(root->left, v);
	v.push_back(root->val);
	inorderTraversalV(root->right, v);
}

//Version 1: recursive
vector<int> inorderTraversalR(TreeNode* root) {
	vector<int> v;
	inorderTraversalV(root, v);
	return v;
}

//Version 2: iterative
vector<int> inorderTraversalI(TreeNode* root) {
	vector<int> v;
	if (!root) return v;
	stack<TreeNode*>st;
	TreeNode* p = root;
	while (p || !st.empty())
	{
		while (p)
		{
			st.push(p);
			p = p->left;
		}
		p = st.top();
		st.pop();
		v.push_back(p->val);
		p = p->right;
	}
	return v;
}

void check(TreeNode* root) {
	for (auto a : inorderTraversalR(root))
		cout << a << " ";
	cout << endl;
	for (auto a : inorderTraversalI(root))
		cout << a << " ";
	cout << endl;
}

int main()
{
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(2, n3, NULL);
	TreeNode* ntree = new TreeNode(1, NULL, n2);
	check(ntree);

	system("pause");
return 0;
}
