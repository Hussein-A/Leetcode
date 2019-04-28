/*
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's value 
equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.

Runtime: 60 ms, faster than 91.78% of C++ online submissions for Search in a Binary Search Tree.
Memory Usage: 29.3 MB, less than 60.34% of C++ online submissions for Search in a Binary Search Tree.
*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, const int& val) {
        if (!root) return NULL;
        
        if (root->val == val) return root;
        else if (root->val < val) return searchBST(root->right, val);
        else return searchBST(root->left, val);
    }
};
