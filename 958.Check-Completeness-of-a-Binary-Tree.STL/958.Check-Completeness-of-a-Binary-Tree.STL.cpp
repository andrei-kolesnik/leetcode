/*
LeetCode 958. Check Completeness of a Binary Tree
https://leetcode.com/problems/check-completeness-of-a-binary-tree/

Input 1: [1,2,3,4,5,6]
Output 1: true
Explanation 1: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.

Input 2: [1,2,3,4,5,null,7]
Output 2: false
Explanation 2: The node with value 7 isn't as far left as possible.
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

int node_count(TreeNode* root)
{
	if (!root) return 0;
	return 1 + node_count(root->left) + node_count(root->right);
}

bool isComplete(TreeNode* root, int count, int index) {
	if (!root) return true;
	// if the node index is greater or equal than the total node count, we have gaps in indexing, 
	// and therefore this is not a complete tree
	if (index >= count) return false; 
	return
		isComplete(root->left,  count, index * 2 + 1) &&
		isComplete(root->right, count, index * 2 + 2);
}

bool isCompleteTree(TreeNode* root) {
	return isComplete(root, node_count(root), 0);
}

void check(TreeNode* root, bool expected) {
	bool actual = isCompleteTree(root);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	TreeNode* m4 = new TreeNode(4);
	TreeNode* m5 = new TreeNode(5);
	TreeNode* m2 = new TreeNode(2, m4, m5);
	TreeNode* m6 = new TreeNode(6);
	TreeNode* m3 = new TreeNode(3, m6, NULL);
	TreeNode* root1 = new TreeNode(1, m2, m3);
	check(root1, true);

	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n2 = new TreeNode(2, n4, n5);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n3 = new TreeNode(3, NULL, n7);
	TreeNode* root2 = new TreeNode(1, n2, n3);
	check(root2, false);

	TreeNode* p5 = new TreeNode(5);
	TreeNode* p2 = new TreeNode(2, p5, NULL);
	TreeNode* p7 = new TreeNode(7);
	TreeNode* p8 = new TreeNode(8);
	TreeNode* p3 = new TreeNode(3, p7, p8);
	TreeNode* root3 = new TreeNode(1, p2, p3);
	check(root3, false);

	TreeNode* root = new TreeNode(1);
	check(root, true);

	check(NULL, true);

	system("pause");
	return 0;
}
