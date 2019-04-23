/*
Sort a linked list in O(n log n) time using constant space complexity.

Runtime: 188 ms, faster than 18.41% of C++ online submissions for Sort List.
Memory Usage: 120.4 MB, less than 5.02% of C++ online submissions for Sort List.
*/

class Solution {
public:
	ListNode* middle(ListNode* head) {
		ListNode *slow = head, *fast = head->next;
		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;
		}
		return slow;
	}

	void merge(ListNode* head1, ListNode* head2) {
		queue<int> first_half;
		queue<int> second_half;

		//fill queues
		ListNode* temp = head1; while (temp->next) { first_half.push(temp->val); temp = temp->next; }
		first_half.push(temp->val);

		//connect first list to second (will return the combined sorted list later)
		temp->next = head2;
		temp = head2; while (temp) { second_half.push(temp->val); temp = temp->next; }

		temp = head1;
		while (!(first_half.empty() || second_half.empty())) {
			if (first_half.front() <= second_half.front()) { temp->val = first_half.front(); first_half.pop(); temp = temp->next; }
			else { temp->val = second_half.front(); second_half.pop(); temp = temp->next; }
		}
		while (!first_half.empty()) { temp->val = first_half.front(); first_half.pop(); temp = temp->next; }
		while (!second_half.empty()) { temp->val = second_half.front(); second_half.pop(); temp = temp->next; }
	}


	void mergesort(ListNode* head) {
		if (head && head->next) {
			ListNode* mid = middle(head);
			ListNode* temp = mid->next; mid->next = NULL;// breaking into two halves to merge later
			mergesort(head); mergesort(temp);
			merge(head, temp);
		}
	}
	ListNode* sortList(ListNode* head) {
		mergesort(head);
		return head;
	}
};