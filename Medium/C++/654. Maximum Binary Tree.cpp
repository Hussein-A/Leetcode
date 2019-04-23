/*
 Given an integer array with no duplicates. A maximum tree building on this array is defined as follow:

	The root is the maximum number in the array.
	The left subtree is the maximum tree constructed from left part subarray divided by the maximum number.
	The right subtree is the maximum tree constructed from right part subarray divided by the maximum number.

Construct the maximum tree by the given array and output the root node of this tree.

Runtime beats 89.18 % of cpp submissions.
Memory usage beats 77.59 % of cpp submissions
*/

class Solution {
private:
	pair<int, int> find_max(vector<int>& nums, int left, int right) {
		pair<int, int> max = { nums[left], left };
		for (int i = left; i <= right; ++i) { if (nums[i] > max.first) { max.first = nums[i]; max.second = i; } }
		return max;
	}
	TreeNode* helper(vector<int>& nums, const int left, const int right) {
		while (left <= right) {
			pair<int, int> max = find_max(nums, left, right);
			TreeNode* root = new TreeNode{ max.first };
			root->left = helper(nums, left, max.second - 1);
			root->right = helper(nums, max.second + 1, right);
			return root;
		}
		return nullptr;
	}
public:
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return helper(nums, 0, nums.size() - 1);
	}
};