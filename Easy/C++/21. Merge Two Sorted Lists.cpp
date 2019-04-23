/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
Memory Usage: 9.2 MB, less than 99.03% of C++ online submissions for Merge Two Sorted Lists.
*/


class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		else if (!l2) return l1;

		queue<int> first;
		queue<int> second;

		//copy contents into the queue first and second
		ListNode* temp = l1; while (temp->next) { first.push(temp->val); temp = temp->next; }
		//connect the two lists
		first.push(temp->val); temp->next = l2;
		temp = l2; while (temp) { second.push(temp->val); temp = temp->next; }
		temp = l1;
		while (!(first.empty() || second.empty())) {
			if (first.front() <= second.front()) { temp->val = first.front(); first.pop(); }
			else { temp->val = second.front(); second.pop(); }
			temp = temp->next;
		}
		//copy over remnants
		while (!first.empty()) { temp->val = first.front(); first.pop(); temp = temp->next; }
		while (!second.empty()) { temp->val = second.front(); second.pop(); temp = temp->next; }
		return l1;
	}
};