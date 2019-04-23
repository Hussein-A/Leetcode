/*
Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root 
of the tree, and every node has no left child and only 1 right child.

Runtime: 52 ms, faster than 82.23% of C++ online submissions for Increasing Order Search Tree.
Memory Usage: 25.3 MB, less than 100.00% of C++ online submissions for Increasing Order Search Tree.
*/

class Solution {
public:
	TreeNode* head;
	TreeNode* result = head = new TreeNode(0);


	void tree_vector(TreeNode* root) {
		if (root->left != NULL) { tree_vector(root->left); }
		if (root->right != NULL) { result->val = root->val; result->right = new TreeNode(0); result = result->right; tree_vector(root->right); return; }
		result->val = root->val; result->right = new TreeNode(0); result = result->right;
		return;
	}

	void delete_rightmost(TreeNode* root) {
		TreeNode* curr = root;
		TreeNode* parent = root;

		while (curr->right != NULL) {
			parent = curr;
			curr = curr->right;
		}
		parent->right = NULL;

	}

	TreeNode* increasingBST(TreeNode* root) {//do by recursion
		tree_vector(root);

		//delete rightmost element (the added 0)
		delete_rightmost(head);

		return head;
	}

};