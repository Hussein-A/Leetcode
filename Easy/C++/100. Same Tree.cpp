/*
Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

Runtime: 8 ms, faster than 35.37% of C++ online submissions for Same Tree.
Memory Usage: 9.8 MB, less than 99.45% of C++ online submissions for Same Tree.
*/


class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//idea: do by recursion
		if ((p == NULL || q == NULL) && !(p == NULL && q == NULL)) return false; //check first if both nodes are checkable
		else if (!(p && q)) return true;
		else if (p->val != q->val) return false;
		else {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}

	}
};