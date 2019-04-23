/*
Given a binary tree
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Runtime: 464 ms, faster than 17.22% of C++ online submissions for Populating Next Right Pointers in Each Node II.
Memory Usage: 66.9 MB, less than 37.87% of C++ online submissions for Populating Next Right Pointers in Each Node II.
*/

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) return root;
		root->next = NULL;

		queue<Node*> curr_level;
		queue<Node*> next_level;
		if (root->left) next_level.push(root->left);
		if (root->right) next_level.push(root->right);

		while (!next_level.empty()) {
			curr_level.swap(next_level); //now jumping into next level
			Node* temp;

			while (!curr_level.empty()) {
				temp = curr_level.front(); curr_level.pop();
				if (curr_level.empty()) temp->next = NULL;
				else temp->next = curr_level.front();

				if (temp->left) next_level.push(temp->left);
				if (temp->right) next_level.push(temp->right);
			}
		}
		return root;


	}
};