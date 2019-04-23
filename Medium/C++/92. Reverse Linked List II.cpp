/*
Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 <= m ? n <= length of list.

Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
Memory Usage: 8.6 MB, less than 99.25% of C++ online submissions for Reverse Linked List II.
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

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* before_cut = new ListNode{ 0 }; before_cut->next = head;
		ListNode* dummy = before_cut;
		ListNode* start = head;
		ListNode* end;
		ListNode* after_cut;

		//increment to cut position
		for (int i = 1; i < m; ++i) {
			before_cut = before_cut->next;
			start = start->next;
		}

		//increment to end cut position
		end = start;
		for (int i = 1; i < n - m + 1; ++i) {
			end = end->next;
		}

		cout << "before_cut: " << before_cut->val << "\n" << "start: " << start->val << "\n"
			<< "end: " << end->val << "\n";

		after_cut = end->next;
		end->next = NULL;

		before_cut->next = reverseList(start);
		start->next = after_cut;

		return dummy->next;





	}
};
