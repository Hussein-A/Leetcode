/*
Given a linked list, remove the n-th node from the end of list and return its head.

Runtime: 12 ms, faster than 22.76% of C++ online submissions for Remove Nth Node From End of List.
Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Remove Nth Node From End of List.
*/

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		n -= 1;
		if (head == NULL) return head;

		//do the gymanstics in a more comfortable container (vector)
		ListNode* p = head;
		vector<int> list_copy;
		while (p) { list_copy.push_back(p->val); p = p->next; }
		reverse(list_copy.begin(), list_copy.end());
		list_copy.erase(list_copy.begin() + n);
		reverse(list_copy.begin(), list_copy.end());

		//translate changes back into the list
		if (list_copy.size() == 0) { head = NULL; return head; }

		p = head->next;
		ListNode* newhead = p;
		head->next = NULL; //sever the "head" to reduce list size by one

		for (int x : list_copy) { p->val = x; p = p->next; }
		return newhead;




	}
};