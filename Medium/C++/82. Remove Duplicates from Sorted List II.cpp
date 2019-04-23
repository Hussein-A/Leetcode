/*
Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

Runtime: 12 ms, faster than 56.94% of C++ online submissions for Remove Duplicates from Sorted List II.
Memory Usage: 9.2 MB, less than 35.44% of C++ online submissions for Remove Duplicates from Sorted List II.
*/

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		ListNode* dummy = new ListNode{ 0 };
		dummy->next = head;

		ListNode* prev = dummy;
		ListNode* curr = head;
		while (curr->next != NULL) {
			if (curr->val == curr->next->val) {
				int duplicate = curr->val;
				while (curr && curr->val == duplicate) {
					auto temp = curr;
					curr = curr->next;
					delete temp;
				}

				prev->next = curr;
				if (curr == NULL) break;
				continue;
			}
			prev = curr;
			curr = curr->next;
		}


		return dummy->next;
	}
};
