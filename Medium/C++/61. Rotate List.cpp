/*
Given a linked list, rotate the list to the right by k places, where k is non-negative.

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Rotate List.
Memory Usage: 9 MB, less than 99.63% of C++ online submissions for Rotate List.
*/

class Solution {
public:
	inline int mod(int a, int b) { int ret = a % b; return ret >= 0 ? ret : ret + b; }

	ListNode* rotateRight(ListNode* head, int k) {
		if (!head) return head;

		//count how many elements list has
		auto p = head; int count = 1;
		while (p->next) { p = p->next; ++count; }

		vector<int> copy(count); int i = 0;
		for (p = head; p != NULL; p = p->next) { copy[i++] = p->val; }

		for (int i = 0; i < count; ++i) {
			p = head; for (int j = 0; j < mod(i + k, count); ++j) { p = p->next; }
			p->val = copy[i];
		}
		return head;
	}
};