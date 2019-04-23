/*
You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition:
	struct Node {
	int val;
	Node *left;
	Node *right;
	Node *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Runtime: 64 ms, faster than 82.83% of C++ online submissions for Populating Next Right Pointers in Each Node.
Memory Usage: 27.3 MB, less than 23.74% of C++ online submissions for Populating Next Right Pointers in Each Node.
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;
		else if (root->left == NULL) { root->next = NULL; return root; }
		root->next = NULL;

		queue<Node*> curr_level;
		queue<Node*> next_level;
		next_level.push(root->left); next_level.push(root->right);

		while (!next_level.empty()) {
			curr_level.swap(next_level); //now jumping into next level
			Node* temp;

			while (!curr_level.empty()) {
				temp = curr_level.front(); curr_level.pop();
				if (curr_level.empty()) temp->next = NULL;
				else temp->next = curr_level.front();
				//if left child exists then so must right (perfect binary tree)
				if (temp->left) { next_level.push(temp->left); next_level.push(temp->right); }
			}
		}
		return root;


	}
};