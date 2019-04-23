/*
Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Delete Node in a Linked List.
Memory Usage: 9.3 MB, less than 20.62% of C++ online submissions for Delete Node in a Linked List.
*/

class Solution {
public:
	void deleteNode(ListNode* node) {
		while (node->next != NULL) {
			node->val = node->next->val;
			if (node->next->next == NULL) { node->next = NULL; break; }
			node = node->next;
		}
	}
};