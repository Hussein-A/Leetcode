/*
Given two binary trees and imagine that when you put one of them to cover the other, 
some nodes of the two trees are overlapped while the others are not.
You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as 
the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

Runtime: 40 ms, faster than 98.46% of C++ online submissions for Merge Two Binary Trees.
Memory Usage: 13.8 MB, less than 99.21% of C++ online submissions for Merge Two Binary Trees.
*/

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 && t2) t1->val += t2->val;
        else if (!t1 && !t2) return NULL;
        else {return t1 == NULL ? t2 : t1;}
        
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
