/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Symmetric Tree.
Memory Usage: 14.9 MB, less than 99.64% of C++ online submissions for Symmetric Tree.
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        else return symmetricHelper(root->left, root->right);
    }
private:
    bool symmetricHelper(TreeNode* left, TreeNode* right){
        if (left && right){
            if (left->val != right->val) return false;
            return symmetricHelper(left->left, right->right) && symmetricHelper(left->right, right->left);
        }
        else if (left != right) return false;
        else return true;
    }
};
