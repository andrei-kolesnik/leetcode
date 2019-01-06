/*
LeetCode 971. Flip Binary Tree To Match Preorder Traversal
https://leetcode.com/problems/flip-binary-tree-to-match-preorder-traversal/

Input 1: root = [1,2], voyage = [2,1]
Output 1: [-1]

Input 2: root = [1,2,3], voyage = [1,3,2]
Output 2: [1]

Input 3: root = [1,2,3], voyage = [1,2,3]
Output 3: []
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

bool doFlipMatchVoyage(TreeNode* root, vector<int>& voyage, vector<int>& result) {
	if (!root) return true;
	if (voyage.empty()) return false;
	if (root->val != voyage.front()) return false;
	voyage.erase(voyage.begin());
	if (root->left && root->right)
		if (root->left->val != voyage.front())
		{
			result.push_back(root->val);
			TreeNode* swap = root->left;
			root->left = root->right;
			root->right = swap;
		}
	return doFlipMatchVoyage(root->left, voyage, result) &&
		doFlipMatchVoyage(root->right, voyage, result);
}

vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage) {
	vector<int> result;
	if (!doFlipMatchVoyage(root, voyage, result))
	{
		result.clear();
		result.push_back(-1);
	}
	return result;
}

void check(TreeNode* root, int v[], int size) {
	vector<int> voyage(v, v + size);
	for (auto a : flipMatchVoyage(root, voyage))
		cout << a << " ";
	cout << endl;
}

int main()
{
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* ntree = new TreeNode(1, n2, n3);
	int a1[] = { 1, 3, 2 };
	check(ntree, a1, 3);

	system("pause");
	return 0;
}
