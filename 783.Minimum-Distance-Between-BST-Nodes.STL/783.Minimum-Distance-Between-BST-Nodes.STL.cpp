/*
LeetCode 783. Minimum Distance Between BST Nodes
https://leetcode.com/problems/minimum-distance-between-bst-nodes/
Input 1: root = [4,2,6,1,3,null,null]
Output 1: 1

Input 2: root = [1,0,48,null,null,12,49,null,null,null,null]
Output 2: 1
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

TreeNode* insertTree(TreeNode* root, int val) {
	if (!root) return new TreeNode(val);
	if (val < root->val)
		root->left = insertTree(root->left, val);
	else if (val > root->val)
		root->right = insertTree(root->right, val);
	return root;
}

void walkTree(TreeNode* root, vector<int> &v) {
	if (!root) return;
	walkTree(root->left, v);
	v.push_back(root->val);
	walkTree(root->right, v);
}

int minDiffInBST(TreeNode* root) {
	vector<int> v;
	walkTree(root, v);
	if (v.size() < 2) return 0;
	vector<int> diff(v.size());
	adjacent_difference(v.begin(), v.end(), diff.begin());
	return *min_element(diff.begin()+1, diff.end());
}

void check(int a[], int size, int expected) {
	TreeNode* root = NULL;
	root = insertTree(root, a[0]);
	for (int i = 1; i < size; i++)
		insertTree(root, a[i]);
	int actual = minDiffInBST(root);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 4,2,6,1,3 };
	check(a1, 5, 1);

	int a2[] = { 1,0,48,12,49 };
	check(a2, 5, 1);

	system("pause");
	return 0;
}
