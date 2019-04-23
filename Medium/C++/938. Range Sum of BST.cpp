/*
Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
The binary search tree is guaranteed to have unique values.

Runtime beats 13.29 % of cpp submissions
Memory usage beats 79.93 % of cpp submissions.
*/

class Solution {
public:

	int rangeSumBST(TreeNode* root, const int& L, const int& R) {
		if (root == nullptr) return 0;

		if (root->val >= L && root->val <= R) sum += root->val;

		if (root->left != nullptr) rangeSumBST(root->left, L, R);
		if (root->right != nullptr) rangeSumBST(root->right, L, R);

		return sum;
	}
private:
	int sum = 0;
};