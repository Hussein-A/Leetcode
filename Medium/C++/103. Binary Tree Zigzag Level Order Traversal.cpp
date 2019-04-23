/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
Memory Usage: 13.5 MB, less than 54.36% of C++ online submissions for Binary Tree Zigzag Level Order Traversal.
*/

class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> order;
		queue<TreeNode*> curr_level;
		queue<TreeNode*> next_level;

		if (!root) return order;
		else next_level.push(root);

		bool zigorzag = true;
		while (!next_level.empty()) {
			swap(curr_level, next_level);
			vector<int> level{};
			zigorzag = zigorzag ? false : true;

			while (!curr_level.empty()) {
				TreeNode*& node = curr_level.front();
				if (node->left) next_level.push(node->left);
				if (node->right) next_level.push(node->right);
				level.push_back(node->val); curr_level.pop();
			}
			if (zigorzag) reverse(level.begin(), level.end());
			order.push_back(level);
		}
		return order;
	}
};