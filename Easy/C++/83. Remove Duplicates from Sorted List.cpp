/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List.
Memory Usage: 9.2 MB, less than 66.57% of C++ online submissions for Remove Duplicates from Sorted List.
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;

		ListNode* curr = head;
		while (curr->next != NULL) {
			if (curr->val == curr->next->val) {
				auto p = curr->next;
				curr->next = curr->next->next;
				delete p;
				continue;
			}
			curr = curr->next;
		}
		return head;
	}
};