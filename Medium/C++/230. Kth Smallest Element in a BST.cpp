/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

Note:
You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
*/


class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        kthhelper(root, k); return value;
    }
private:
    int count = 0;
    int value = 0;
    void kthhelper(TreeNode* root,const int& k){
        if (!root || count == k) return;
        
        kthhelper(root->left, k);
        ++count; if (count == k) value = root->val;
        kthhelper(root->right, k);
    }
};
