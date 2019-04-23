/*
Given a binary tree, determine if it is a valid binary search tree (BST).
Assume a BST is defined as follows:
	The left subtree of a node contains only nodes with keys less than the node's key.
	The right subtree of a node contains only nodes with keys greater than the node's key.
	Both the left and right subtrees must also be binary search trees.

Runtime: 48 ms, faster than 9.34% of C++ online submissions for Validate Binary Search Tree.
Memory Usage: 21.3 MB, less than 5.15% of C++ online submissions for Validate Binary Search
*/

class Solution {
public:
	vector<int> treesort;
	void BSTtraversal(TreeNode* root) {
		if (!root->left && !root->right) { treesort.push_back(root->val); return; }

		if (root->left) BSTtraversal(root->left);
		treesort.push_back(root->val);
		if (root->right) BSTtraversal(root->right);
	}

	bool isValidBST(TreeNode* root) {
		//do inorder traversal to generate a sorted list if BST
		if (!root) return true;
		BSTtraversal(root);
		for (int x : treesort) cout << x << " ";
		cout << "\n";

		vector<int> temp = treesort;
		sort(temp.begin(), temp.end());

		for (int i = 0; i < temp.size(); ++i) {
			if (temp[i] != treesort[i]) return false;
		}
		//check for duplicates
		for (int i = 0; i < temp.size() - 1; ++i) {
			if (temp[i] == temp[i + 1]) return false;
		}
		return true;
	}

};