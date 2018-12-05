/*
LeetCode 538. Convert BST to Greater Tree
https://leetcode.com/problems/convert-bst-to-greater-tree/

Input: The root of a Binary Search Tree like this:
			  5
			/   \
		   2     13

Output: The root of a Greater Tree like this:
			 18
			/   \
		  20     13
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

int depth(TreeNode* root)
{
	if (!root) return 0;
	return max(depth(root->left), depth(root->right)) + 1;
}

void printLevel(TreeNode* root, vector<vector<string>> &tree, int depth, int ident, int level)
{
	if (level < 0 || !root) return;
	int w = pow(2, depth - level) - 1;
	tree[level][ident + w / 2] = to_string(root->val);
	printLevel(root->left, tree, depth, ident, level + 1);
	printLevel(root->right, tree, depth, ident + w / 2 + 1, level + 1);
}

vector<vector<string>> printTree(TreeNode* root) {
	int d = depth(root);
	int w = pow(2, d) - 1;
	vector<vector<string>> result;
	for (int i = 0; i < d; i++)
	{
		vector<string> v(w);
		result.push_back(v);
	}

	printLevel(root, result, d, 0, 0);

	return result;
}

void drawTree(TreeNode* root) {
	vector<vector<string>> res = printTree(root);
	for (auto row : res)
	{
		for (auto node : row)
			cout << (node.size() > 0 ? node : " ");
		cout << endl;
	}
	cout << endl;
}

void to_stack(TreeNode* root, stack<int> &st)
{
	if (!root) return;
	to_stack(root->left, st);
	st.push(root->val);
	to_stack(root->right, st);
}

void from_stack(TreeNode* root, stack<int> &st) {
	if (!root) return;
	from_stack(root->right, st);
	root->val = st.top();
	st.pop();
	if (st.size()) st.top() += root->val;
	from_stack(root->left, st);
}

TreeNode* convertBST(TreeNode* root) {
	stack<int> nodes;
	to_stack(root, nodes);
	from_stack(root, nodes);
	return root;
}

int main()
{
	TreeNode* m2 = new TreeNode(2);
	TreeNode* m3 = new TreeNode(13);
	TreeNode* root = new TreeNode(5, m2, m3);

	drawTree(root);
	convertBST(root);
	drawTree(root);

	system("pause");
	return 0;
}
