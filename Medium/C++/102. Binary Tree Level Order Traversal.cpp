/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.
Memory Usage: 13.9 MB, less than 48.30% of C++ online submissions for Binary Tree Level Order Traversal.
*/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> order;
		queue<TreeNode*> curr_level;
		queue<TreeNode*> next_level;

		if (!root) return order;
		else next_level.push(root);


		while (!next_level.empty()) {
			swap(curr_level, next_level);
			vector<int> level{};

			while (!curr_level.empty()) {
				TreeNode*& node = curr_level.front();
				if (node->left) next_level.push(node->left);
				if (node->right) next_level.push(node->right);
				level.push_back(node->val); curr_level.pop();
			}
			order.push_back(level);
		}
		return order;
	}
};