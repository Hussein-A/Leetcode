/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

Runtime: 1152 ms, faster than 5.19% of C++ online submissions for Merge k Sorted Lists.
Memory Usage: 322 MB, less than 5.03% of C++ online submissions for Merge k Sorted Li
*/

class Solution {
public:
	ListNode* merge(ListNode* l1, ListNode* l2) {
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


	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int last_elem_pos = lists.size() - 1;
		if (last_elem_pos == -1) return NULL;
		else if (last_elem_pos == 0) return lists[0];

		//do a snowball of two list merging. Merging the first with second with the second being
		//the merged of two and repeat with list2 and list3
		for (int i = 0; i < last_elem_pos; ++i) {
			lists[i + 1] = merge(lists[i + 1], lists[i]);
		}
		return lists[last_elem_pos];
	}
};