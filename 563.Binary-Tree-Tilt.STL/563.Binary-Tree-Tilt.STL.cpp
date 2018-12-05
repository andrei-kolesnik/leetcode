/*
LeetCode 563. Binary Tree Tilt
https://leetcode.com/problems/binary-tree-tilt/
Input:
		 1
	   /   \
	  2     3
Output: 1
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

int Sum(TreeNode* root) {
	if (!root) return 0;
	return root->val + Sum(root->left) + Sum(root->right);
}

int Tilt(TreeNode* root)
{
	if (!root) return 0;
	return abs(Sum(root->left) - Sum(root->right));
}

int findTilt(TreeNode* root) {
	if (!root) return 0;
	return Tilt(root) + findTilt(root->left) + findTilt(root->right);
}

int main()
{
	TreeNode* m2 = new TreeNode(2);
	TreeNode* m3 = new TreeNode(3);
	TreeNode* root = new TreeNode(1, m2, m3);

	cout << findTilt(root) << endl;

	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n5 = new TreeNode(5, n7, n8);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(2, n4, n5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n3 = new TreeNode(3, n6, NULL);
	TreeNode* root2 = new TreeNode(1, n2, n3);

	cout << findTilt(root2) << endl;

	system("pause");
	return 0;
}
