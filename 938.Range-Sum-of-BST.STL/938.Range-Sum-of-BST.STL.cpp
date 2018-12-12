/*
LeetCode 938. Range Sum of BST
https://leetcode.com/problems/range-sum-of-bst/
Input 1: root = [10,5,15,3,7,null,18], L = 7, R = 15
Output 1: 32

Input 2: root = [10,5,15,3,7,13,18,1,null,6], L = 6, R = 10
Output 2: 23
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

int rangeSumBST(TreeNode* root, int L, int R) {
	int result = 0;
	if (!root) return result;
	if (root->val >= L && root->val <= R) result = root->val;
	if (root->val > L) result += rangeSumBST(root->left, L, R);
	if (root->val < R) result += rangeSumBST(root->right, L, R);
	return result;
}

void check(int a[], int size, int L, int R, int expected) {
	TreeNode* root = NULL;
	root = insertTree(root, a[0]);
	for (int i = 1; i < size; i++)
		insertTree(root, a[i]);
	int actual = rangeSumBST(root, L, R);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	int a1[] = { 10,5,15,3,7,18 };
	check(a1, 6, 7, 15, 32);

	int a2[] = { 10,5,15,3,7,13,18,1,6 };
	check(a2, 9, 6, 10, 23);

	system("pause");
	return 0;
}
