/*
LeetCode 101. Symmetric Tree
https://leetcode.com/problems/symmetric-tree/

Input 1: [1,2,2,3,4,4,3]
	1
   / \
  2   2
 / \ / \
3  4 4  3
Output 1: True

Input 2: [1,2,2,null,3,null,3]
	1
   / \
  2   2
   \   \
   3    3
Output 2: False
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

int height(TreeNode* root) {
	if (!root) return 0;
	return max(height(root->left), height(root->right)) + 1;
}

void getLevel(TreeNode* root, int level, deque<int>& deq) {
	if (level == 1) 
		deq.push_back(root ? root->val : INT32_MAX);
	else if (!root) return;
	else {
		getLevel(root->left, level - 1, deq);
		getLevel(root->right, level - 1, deq);
	}
}

bool isSymmetric(TreeNode* root) {
	int h = height(root);
	for (int i = 2; i <= h; i++)
	{
		deque<int> deq;
		getLevel(root, i, deq);
		while (!deq.empty()) 
		{
			if (deq.front() != deq.back()) 
				return false;
			deq.pop_front();
			deq.pop_back();
		}
	}
	return true;
}

void check(TreeNode* root, bool expected) {
	bool actual = isSymmetric(root);
	cout << boolalpha;
	cout << (actual == expected ? "PASS" : "FAIL") << " "
		<< " (" << expected << " / " << actual << ")" << endl;
}

int main() {
	TreeNode* n31 = new TreeNode(3);
	TreeNode* n41 = new TreeNode(4);
	TreeNode* n21 = new TreeNode(2, n31, n41);
	TreeNode* n42 = new TreeNode(4);
	TreeNode* n32 = new TreeNode(3);
	TreeNode* n22 = new TreeNode(2, n42, n32);
	TreeNode* tree1 = new TreeNode(1, n21, n22);
	check(tree1, true);

	TreeNode* m31 = new TreeNode(3);
	TreeNode* m21 = new TreeNode(2, NULL, m31);
	TreeNode* m32 = new TreeNode(3);
	TreeNode* m22 = new TreeNode(2, NULL, m32);
	TreeNode* tree2 = new TreeNode(1, m21, m22);
	check(tree2, false);

	system("pause");
	return 0;
}
