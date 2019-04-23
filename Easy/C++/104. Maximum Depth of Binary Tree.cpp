/*
Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the 
farthest leaf node.

Runtime: beats 98.99 % of cpp submissions. 
MEM: Your memory usage beats 96.47 % of cpp submissions.
*/

class Solution {
public:
	int maxDepth(TreeNode* root) {
		//do in level traversal        
		//initialize
		queue<TreeNode*> curr_level;
		queue<TreeNode*> next_level;

		if (!root) return 0;
		else next_level.push(root);
		int depth = 0;

		while (!next_level.empty()) {
			swap(curr_level, next_level);
			cout << "1";
			++depth;
			while (!curr_level.empty()) {
				TreeNode*& node = curr_level.front();
				if (node->left) next_level.push(node->left);
				if (node->right) next_level.push(node->right);
				curr_level.pop();
			}
		}
		return depth;
	}
};