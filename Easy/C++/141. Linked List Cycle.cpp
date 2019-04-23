/*
Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

Runtime: 12 ms, faster than 99.40% of C++ online submissions for Linked List Cycle.
Memory Usage: 9.8 MB, less than 36.60% of C++ online submissions for Linked List Cycle.
*/

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL || head->next == NULL) return false;

		ListNode* slow = head;
		ListNode* fast = head;
		while (fast != NULL && fast->next != NULL) {
			fast = fast->next;
			if (fast == slow) return true;
			else { slow = slow->next; fast = fast->next; }
		}
		return false;

	}
};