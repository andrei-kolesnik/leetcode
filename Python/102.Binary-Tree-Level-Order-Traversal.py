"""
LeetCode #102. Binary Tree Level Order Traversal
https://leetcode.com/problems/binary-tree-level-order-traversal/

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

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


# Solution
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        result = []

        def levelOrderByLevel(root: Optional[TreeNode], current_level: int, target_level: int) -> List[int]:
            if not root:
                return []
            if current_level == target_level:
                return [root.val]
            return \
                levelOrderByLevel(root.left, current_level + 1, target_level) + \
                levelOrderByLevel(root.right, current_level + 1, target_level)

        def treeDepth(root: Optional[TreeNode]) -> int:
            if not root:
                return 0
            return max(treeDepth(root.left), treeDepth(root.right)) + 1

        for level in range(1, treeDepth(root) + 1):
            result.append(levelOrderByLevel(root, 1, level))
        return result


# Tests
def use_case(tree_as_list: List[int], expected: List[List[int]]):
    root = list_to_tree(tree_as_list)
    actual = Solution().levelOrder(root)
    print('PASS' if actual == expected else 'FAIL', tree_as_list, actual, expected, sep=' : ')


if __name__ == '__main__':
    use_case([3,9,20,None,None,15,7], [[3],[9,20],[15,7]])
    use_case([1], [[1]])
    use_case([], [])
