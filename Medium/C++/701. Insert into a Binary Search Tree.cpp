/*
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. 
You can return any of them.

Runtime: 96 ms, faster than 96.46% of C++ online submissions for Insert into a Binary Search Tree.
Memory Usage: 33 MB, less than 80.65% of C++ online submissions for Insert into a Binary Search Tree.
*/

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, const int& val) {
        //empty case
        if (!root) return new TreeNode{val};
        
        if (root->val < val){
            if (root->right) insertIntoBST(root->right, val);
            else root->right = new TreeNode{val};
        }
        else {
            if (root->left) insertIntoBST(root->left, val);
            else root->left = new TreeNode{val};
        }
        return root;
    }
};
