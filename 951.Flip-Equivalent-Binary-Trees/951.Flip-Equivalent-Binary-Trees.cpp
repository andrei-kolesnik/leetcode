/*
LeetCode 951. Flip Equivalent Binary Trees
https://leetcode.com/problems/flip-equivalent-binary-trees/

For a binary tree T, we can define a flip operation as follows: 
choose any node, and swap the left and right child subtrees.

A binary tree X is flip equivalent to a binary tree Y if and only if 
we can make X equal to Y after some number of flip operations.

Write a function that determines whether two binary trees are flip equivalent.  
The trees are given by root nodes root1 and root2.

Input: 
root1 = [1, 2, 3, 4, 5, 6, null, null, null, 7, 8]
root2 = [1, 3, 2, null, 6, 4, 5, null, null, null, null, 8, 7]

Output : true

Explanation : We flipped at nodes with values 1, 3, and 5.
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

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
	if (!root1 && !root2) return true;
	if (root1 && !root2) return false;
	if (!root1 && root2) return false;
	if (root1->val == root2->val)
	{
		TreeNode *new_left1 = NULL;
		TreeNode *new_right1 = NULL;
		if (root1->left && root1->right)
		{
			if (root1->left->val <= root1->right->val)
			{
				new_left1 = root1->left;
				new_right1 = root1->right;
			}
			else
			{
				new_left1 = root1->right;
				new_right1 = root1->left;
			}
		}
		else if (root1->left)
			new_left1 = root1->left;
		else
			new_left1 = root1->right;

		TreeNode *new_left2 = NULL;
		TreeNode *new_right2 = NULL;
		if (root2->left && root2->right)
		{
			if (root2->left->val <= root2->right->val)
			{
				new_left2 = root2->left;
				new_right2 = root2->right;
			}
			else
			{
				new_left2 = root2->right;
				new_right2 = root2->left;
			}
		}
		else if (root2->left)
			new_left2 = root2->left;
		else
			new_left2 = root2->right;

		return flipEquiv(new_left1, new_left2) && flipEquiv(new_right1, new_right2);
	}
	else return false;
}

int main()
{
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n5 = new TreeNode(5, n7, n8);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n2 = new TreeNode(2, n4, n5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n3 = new TreeNode(3, n6, NULL);
	TreeNode* root1 = new TreeNode(1, n2, n3);

	TreeNode* m7 = new TreeNode(7);
	TreeNode* m8 = new TreeNode(8);
	TreeNode* m5 = new TreeNode(5, m8, m7);
	TreeNode* m4 = new TreeNode(4);
	TreeNode* m2 = new TreeNode(2, m4, m5);
	TreeNode* m6 = new TreeNode(6);
	TreeNode* m3 = new TreeNode(3, NULL, m6);
	TreeNode* root2 = new TreeNode(1, m3, m2);

	cout << boolalpha;
	cout << flipEquiv(root1, root2) << endl;

	system("pause");
	return 0;
}
