"""
LeetCode #226.Invert Binary Tree
https://leetcode.com/problems/invert-binary-tree/

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []
"""

from typing import Optional, List


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


# Helpers
def list_to_tree(items: List[int]) -> Optional[TreeNode]:
    n = len(items)
    if n == 0:
        return None

    def list_to_tree_from_index(index: int) -> Optional[TreeNode]:
        if n <= index or items[index] is None:
            return None

        return TreeNode(
            items[index],
            list_to_tree_from_index(2 * index + 1),
            list_to_tree_from_index(2 * index + 2)
        )

    return list_to_tree_from_index(0)


def tree_to_list(root: Optional[TreeNode]) -> List[int]:
    result = []

    def tree_to_list_by_levels(root: Optional[TreeNode], current_level: int, target_level: int) -> List[int]:
        if not root:
            return []
        if current_level == target_level:
            return [root.val]
        return \
            tree_to_list_by_levels(root.left, current_level + 1, target_level) + \
            tree_to_list_by_levels(root.right, current_level + 1, target_level)

    def tree_depth(root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        return max(tree_depth(root.left), tree_depth(root.right)) + 1

    for level in range(1, tree_depth(root) + 1):
        result.extend(tree_to_list_by_levels(root, 1, level))
    return result


# Solution
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return None
        return TreeNode(root.val, self.invertTree(root.right), self.invertTree(root.left))


# Tests
def use_case(tree_as_list: List[int], expected: List[int]):
    root = list_to_tree(tree_as_list)
    actual = tree_to_list(Solution().invertTree(root))
    print('PASS' if actual == expected else 'FAIL', tree_as_list, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([4,2,7,1,3,6,9], [4,7,2,9,6,3,1])
    use_case([2,1,3], [2,3,1])
    use_case([], [])
    use_case([1,2,3,4,5,6,7], [1,3,2,7,6,5,4])
