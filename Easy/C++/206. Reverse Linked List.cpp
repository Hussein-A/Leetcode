/*
Reverse a singly linked list.

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Reverse Linked List.
Memory Usage: 9.1 MB, less than 81.85% of C++ online submissions for Reverse Linked List.
*/

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;

		ListNode* curr = head->next;
		ListNode* prev = head;
		head->next = NULL;

		while (curr) {
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}

		return prev;
	}
};