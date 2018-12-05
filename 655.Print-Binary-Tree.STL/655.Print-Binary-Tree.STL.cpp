/*
LeetCode 655. Print Binary Tree
https://leetcode.com/problems/print-binary-tree/

Input 1:
	 1
	/
   2
Output 1:
[["", "1", ""],
 ["2", "", ""]]

Input 2:
	 1
	/ \
   2   3
	\
	 4
Output 2:
[["", "", "", "1", "", "", ""],
 ["", "2", "", "", "", "3", ""],
 ["", "", "4", "", "", "", ""]]

Input 3:
	  1
	 / \
	2   5
   /
  3
 /
4
Output 3:
[["",  "",  "", "",  "", "", "", "1", "",  "",  "",  "",  "", "", ""]
 ["",  "",  "", "2", "", "", "", "",  "",  "",  "",  "5", "", "", ""]
 ["",  "3", "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]
 ["4", "",  "", "",  "", "", "", "",  "",  "",  "",  "",  "", "", ""]]
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
	printLevel(root->left,  tree, depth, ident, level + 1);
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

int main()
{
	{
		TreeNode* m2 = new TreeNode(2);
		TreeNode* mtree = new TreeNode(1, m2, NULL);
		drawTree(mtree);
	}

	{
		TreeNode* n4 = new TreeNode(4);
		TreeNode* n2 = new TreeNode(2, NULL, n4);
		TreeNode* n3 = new TreeNode(3);
		TreeNode* ntree = new TreeNode(1, n2, n3);
		drawTree(ntree);
	}

	{
		TreeNode* p4 = new TreeNode(4);
		TreeNode* p3 = new TreeNode(3, p4, NULL);
		TreeNode* p2 = new TreeNode(2, p3, NULL);
		TreeNode* p5 = new TreeNode(5);
		TreeNode* ptree = new TreeNode(1, p2, p5);
		drawTree(ptree);
	}

	system("pause");
	return 0;
}
