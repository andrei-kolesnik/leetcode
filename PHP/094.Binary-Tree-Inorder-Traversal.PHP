<?php
/*
94. Binary Tree Inorder Traversal
https://leetcode.com/problems/binary-tree-inorder-traversal/

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/
//Definition for a binary tree node.
class TreeNode {
   public $val = null;
   public $left = null;
   public $right = null;
   function __construct($value, $left = null, $right = null) { 
      $this->val = $value; 
      $this->left = $left; 
      $this->right = $right; 
   }
}

//Version 1: recursive
function inorderTraversalR($root) {
   $result = array();
   if (isset($root)) 
   {
      $result = inorderTraversalR($root->left);
      $result[] = $root->val;
      $result = array_merge($result, inorderTraversalR($root->right));
   }
   return $result;
}

$n4 = new TreeNode(4);
$n3 = new TreeNode(3, null, $n4);
$n6 = new TreeNode(6);
$n5 = new TreeNode(5, $n3, $n6);
$n2 = new TreeNode(2, null, $n5);
$n1 = new TreeNode(1, null, $n2);

print_r(inorderTraversalR($n1));
