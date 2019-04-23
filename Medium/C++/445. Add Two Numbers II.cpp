/*
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Runtime: 32 ms, faster than 79.90% of C++ online submissions for Add Two Numbers II.
Memory Usage: 11.5 MB, less than 99.00% of C++ online submissions for Add Two Numbers II.
*/

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL) { return l1 == NULL ? l1 : l2; }

		vector<int> digits1;
		vector<int> digits2;

		//convert into vector for ease of use
		auto p1 = l1; auto p2 = l2;
		while (p1) { digits1.push_back(p1->val); p1 = p1->next; }
		while (p2) { digits2.push_back(p2->val); p2 = p2->next; }

		reverse(digits1.begin(), digits1.end());
		reverse(digits2.begin(), digits2.end());

		//make both the same size with any extra entries being zero if smaller
		int size = digits1.size();
		if (digits1.size() != digits2.size()) { size = digits1.size() > digits2.size() ? digits1.size() : digits2.size(); digits1.resize(size + 1); digits2.resize(size + 1); }
		else { digits1.resize(size + 1); digits2.resize(size + 1); }
		vector<int> result(digits1.size());

		//now add as in elementary school, digit by digit, carrying over the ones
		int sum = 0;
		for (int i = 0; i < digits1.size(); ++i) {
			sum = digits1.at(i) + digits2.at(i);
			if (sum >= 10) { sum -= 10;  ++digits1.at(i + 1); } //carry over the 1
			result.at(i) = sum;
		}
		reverse(result.begin(), result.end());
		if (result[0] == 0) result.erase(result.begin());

		//convert to a list
		auto list_result = new ListNode(0);
		auto head = list_result;
		for (int i = 0; i < result.size(); ++i) {
			list_result->val = result[i];
			if (i != result.size() - 1) { list_result->next = new ListNode(0); list_result = list_result->next; }
		}
		return head;
	}
};