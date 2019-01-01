/*
LeetCode 530. Minimum Absolute Difference in BST
https://leetcode.com/problems/minimum-absolute-difference-in-bst/
Input:
   1
	\
	 3
	/
   2

Output:
1
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

// In-Order traversal + vector, time complexity O(N), space complexity O(N)
int getMinimumDifference(TreeNode* root) {
	vector<int> v;
	inorderTraversalV(root, v);
	int result = INT32_MAX;
	for (int i = 0; i < v.size() - 1; i++)
		result = min(result, v[i + 1] - v[i]);
	return result;
}

void check(TreeNode* root, int expected) {
	getMinimumDifference(root);
	int actual = getMinimumDifference(root);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " ( " << expected << " / " << actual << ")" << endl;
}

int main()
{
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3, n2, NULL);
	TreeNode* ntree = new TreeNode(1, NULL, n3);
	check(ntree, 1);

	system("pause");
	return 0;
}
