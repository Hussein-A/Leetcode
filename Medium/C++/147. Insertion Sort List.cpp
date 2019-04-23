/*
Sort a linked list using insertion sort.

Runtime: 64 ms, faster than 17.91% of C++ online submissions for Insertion Sort List.
Memory Usage: 10 MB, less than 5.07% of C++ online submissions for Insertion Sort List.
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

	ListNode* insertionSortList(ListNode* head) {
		if (!head) return head;
		ListNode* tail = new ListNode{ head->val };

		ListNode* curr = head->next;
		ListNode* temp;
		ListNode* prev;
		while (curr) {
			temp = tail;
			prev = temp;
			while (temp && curr->val < temp->val) {
				prev = temp;
				temp = temp->next;
			}
			if (prev == temp) {//case when element is inserted at the very beginning (ie. the end of the real sorted list)
				tail = new ListNode{ curr->val };
				tail->next = prev;
			}
			else {
				prev->next = new ListNode{ curr->val };
				prev->next->next = temp;
			}
			curr = curr->next;
		}

		//delete old list
		curr = head->next;
		prev = head;
		while (curr) {
			delete prev;
			prev = curr;
			curr = curr->next;
		}
		delete prev;

		ListNode* sorted = reverseList(tail);
		return sorted;

	}
};