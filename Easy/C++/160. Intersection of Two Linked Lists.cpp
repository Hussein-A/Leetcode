/*
Write a program to find the node at which the intersection of two singly linked lists begins.

Runtime: 808 ms, faster than 5.00% of C++ online submissions for Intersection of Two Linked Lists.
Memory Usage: 16.7 MB, less than 75.53% of C++ online submissions for Intersection of Two Linked Lists.
*/

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (headA == headB) return headA;

		auto posA = headA;
		auto posB = headB;
		while (posA != NULL) {
			posB = headB;
			while (posB != NULL) {
				if (posB == posA) return posB;
				else posB = posB->next;
			}
			posA = posA->next;
		}
		return NULL;
	}
};