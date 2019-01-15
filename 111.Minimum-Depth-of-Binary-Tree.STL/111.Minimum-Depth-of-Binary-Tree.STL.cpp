/*
LeetCode 111. Minimum Depth of Binary Tree
https://leetcode.com/problems/minimum-depth-of-binary-tree/

Input:
	3
   / \
  9  20
	/  \
   15   7

Output: 2
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

int minDepth(TreeNode* root) {
	if (!root) return 0;
	if (!root->left && !root->right) return 1;
	int result = INT32_MAX;
	if (root->left) result = minDepth(root->left);
	if (root->right) result = min(result, minDepth(root->right));
	return result + 1;
}

void check(TreeNode* root, int expected) {
	int actual = minDepth(root);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	TreeNode* n15 = new TreeNode(15);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n20 = new TreeNode(20, n15, n7);
	TreeNode* n9 = new TreeNode(9);
	TreeNode* ntree = new TreeNode(3, n9, n20);
	check(ntree, 2);

	system("pause");
	return 0;
}
