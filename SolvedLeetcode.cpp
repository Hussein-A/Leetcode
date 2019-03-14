#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using std::cout;

/*  Problem 160. Intersection of Two Linked Lists
	Difficulty: Easy
	Description: Write a program to find the node at which the intersection of two singly linked lists begins.

 //* Definition for singly-linked list.
 //* struct ListNode {
 //*     int val;
 //*     ListNode *next;
 //*     ListNode(int x) : val(x), next(NULL) {}
 //* };
 
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
*/

/*  Problem: 557. Reverse Words in a String III
	Difficulty: Easy
	Description: Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

class Solution {
public:
	string reverseWords(string s) {
		istringstream ist {s};
		string temp;
		string reversed;
		while (ist >> temp){
			reverse(temp.begin(), temp.end());
			reversed = reversed + temp + " ";
		}
		reversed.erase(reversed.end()-1); //remove the last space
		return reversed;

	}
};
*/

/*  Problem: 237. Delete Node in a Linked List
	Difficulty: Easy
	Description: Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.

 //* Definition for singly-linked list.
 //* struct ListNode {
 //*     int val;
 //*     ListNode *next;
 //*     ListNode(int x) : val(x), next(NULL) {}
 //* };
 
class Solution {
public:
	void deleteNode(ListNode* node) {
		while (node->next != NULL) {
			node->val = node->next->val;
			if (node->next->next == NULL) { node->next = NULL; break; }
			node = node->next;
		}
	}
};
*/


/*  Problem: 125. Valid Palindrome
	Difficulty: Easy
	Description: Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.


#include <algorithm>
class Solution {
public:
	bool isPalindrome(string& s) {
		if (s.size()<=1) return true;
		string temp;
		for (char c : s){ if (isalnum(c)) {if (isalpha(c)) temp += tolower(c); else temp+= c;}}
		s = temp;

		string reversed_s = s; reverse(reversed_s.begin(), reversed_s.end());
		for (int i =0; i<=s.size()/2; ++i){
			if (tolower(s[i]) != tolower(reversed_s[i])) return false;
		}


		return true;
	}
};
*/

/*  Problem: 66. Plus One
	Difficulty: Easy
	Description: Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
	The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
	You may assume the integer does not contain any leading zero, except the number 0 itself.

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		int last = digits.size()-1;
		int pos = last-1;
		if (digits.size()==1 && digits[0]==9){digits.push_back(1); digits[0]=0; swap(digits[0], digits[digits.size()-1]); return digits;}
		else if (digits.size()==1) {++digits[0]; return digits;}
		else if (digits[last]<9) ++digits[last];
		else {
			digits[last]=0;
			while (pos>=0){
				if (pos == 0 && digits[pos] ==9){digits.push_back(1); digits[0]=0; swap(digits[0], digits[digits.size()-1]); --pos;}//increase size of array by one and make the leading digit 1
				else if (digits[pos]==9){digits[pos]=0; --pos;}
				else {++digits[pos]; return digits;}
			}
		}
		return digits;
	}
};
*/

/*  Problem: 20. Valid Parentheses
	Difficulty: Easy
	Description: Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
	An input string is valid if:
	Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.



class Solution {
public:
bool isValid(std::string s) {
		std::vector<char> expectation;
		for (char c : s) {
			switch (c) {
			case '(':
				expectation.push_back('(');
				break;
			case '[':
				expectation.push_back('[');
				break;
			case '{':
				expectation.push_back('{');
				break;
			case ')':
				if (expectation.size() == 0) return false; //no matching left char
				else if (expectation[expectation.size() - 1] != '(') return false;
				else  expectation.erase(expectation.end()-1);
				break;
			case ']':
				if (expectation.size() == 0) return false; //no matching left char
				else if (expectation[expectation.size() - 1] != '[') return false;
				else expectation.erase(expectation.end()-1);
				break;
			case '}':
				if (expectation.size() == 0) return false; //no matching left char
				else if (expectation[expectation.size() - 1] != '{') return false;
				else expectation.erase(expectation.end()-1);
				break;
			}
		}
		cout << expectation.size() << "\n";
		if (expectation.size() > 0)  return false; //more left facing brackets than right facing found.
		else return true;


		//need to check two things at the end either 1. the vector of "expectations" is empty or ive got more right hand brackets than my vector of expectations has
	}
};
*/

/*
Problem 155. Min Stack
Difficulty: Easy
Description:  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
    push(x) -- Push element x onto stack.
    pop() -- Removes the element on top of the stack.
    top() -- Get the top element.
    getMin() -- Retrieve the minimum element in the stack.

class MinStack {
public:
MinStack() {

}

void push(int x) {
	if (ints.size() == 0) min = x;
	else if (x < min) min = x;
	ints.push_back(x);
}

void pop() {
	if (min == *--ints.end()) {
		//find the new min
		ints.erase(--ints.end());
		if (ints.size() == 0) {}
		else {
			list<int> temp = ints;
			temp.sort();
			min = *temp.begin();
		}
	}
	else ints.erase(--ints.end());
	cout << "Size is now: " << ints.size() << "\n";
}

int top() {
	return *(--ints.end());
}

int getMin() {
	return min;
}
private:
	int min{ INT_MAX };
	list<int> ints;

};

*/

/*
Problem 239. Sliding Window Maximum
Difficulty: Hard
Description: Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.

class Solution {
public:
	int get_lmax(const list<int>& l) const{
		int max = INT_MIN;
		for (const int& x : l){if (x>max) max = x;}
		return max;
	}

	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		if (nums.size() == 0) return nums;
		//initialize
		int nums_size = nums.size();
		int max = INT_MIN;
		vector<int> window_max;
		list<int> window(k);

		//initialize window
		auto p = window.begin();
		for (int i =0; i <k; ++i){*(p++) = nums[i]; if (nums[i]>max) max = nums[i];}
		window_max.push_back(max);

		//slide window
		int i = k;
		while (i != nums_size){
			window.erase(window.begin());
			window.push_back(nums[i]);
			//check new num
			if (nums[i]> max) {max = nums[i]; window_max.push_back(max);}
			else {
				max = get_lmax(window); window_max.push_back(max);
			}

			++i;
		}
		return window_max;


	}
};
*/

/*
Problem 402. Remove K Digits
Difficulty: Medium
Description: Given a non-negative integer num represented as a string,
remove k digits from the number so that the new number is the smallest possible. 

class Solution {
public:
	//idea is to go through the number removing only 1 digit at a time to minimize the resulting number, and continuing this
	//until the number of digits to remove is 0.

	void removedigit(string& num){
		//if possible to remove a leading digit and a 0, keep removing until remainder does not have a leading 0
		if (num.size()>1 && num[1]=='0') {
			int i = 0;
			while (num[i+1]=='0'){++i;}
			num.erase(num.begin(), num.begin()+i+1);
			if (num.size()==0) num = "0";
			return;
		}
		else{
			if (num.size()==1) {num = "0"; return;}
			auto p = num.begin();
			while (p != num.end()-1){
				if (*p <= *(p+1)) ++p;
				else {num.erase(p); return;}
			}
			num.erase(p);
		}


	}

	string removeKdigits(string num, int k) {
		if (k == 0) return num;
		else if (num.size() ==0) {num ="0"; return num;}

		while (k!=0){removedigit(num); --k;}
		return num;
	}
};
*/

/*
Problem 61. Rotate List
Difficulty: Medium
Description: Given a linked list, rotate the list to the right by k places, where k is non-negative.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };

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
*/

/*
Problem 326. Power of Three
Difficulty: Easy
Description: Given an integer, write a function to determine if it is a power of three.

class Solution {
public:
	bool isPowerOfThree(int n) {
		if(n%3 != 0 && n !=1) return false;

		for (int i = 0; pow(3,i)<=n; ++i){if (pow(3,i)==n) return true;}
		return false;
	}
};
*/

/*
Problem 19. Remove Nth Node From End of List
Difficulty: Medium
Description: Given a linked list, remove the n-th node from the end of list and return its head.

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		n-=1;
		if (head == NULL) return head;

		//do the gymanstics in a more comfortable container (vector)
		ListNode* p = head;
		vector<int> list_copy;
		while(p){list_copy.push_back(p->val); p=p->next;}
		reverse(list_copy.begin(), list_copy.end());
		list_copy.erase(list_copy.begin()+n);
		reverse(list_copy.begin(), list_copy.end());

		//translate changes back into the list
		if (list_copy.size() == 0) {head = NULL; return head;}

		p = head->next;
		ListNode* newhead = p;
		head->next = NULL; //sever the "head" to reduce list size by one

		for (int x : list_copy){p->val = x; p =p->next;}
		return newhead;




	}
};
*/

/*
Problem 876. Middle of Linked List
Difficulty: Easy
Description: Given a non-empty, singly linked list with head node head, return a middle node of linked list.
If there are two middle nodes, return the second middle node.

class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		int size = 0;
		auto p = head;
		while(p){
			p = p->next;
			++size;
		}
		p = head;
		for (int j = 0; j< size/2; ++j){p =p->next;}
		return p;
	}
};
*/

/*
Problem 445. Add Two Numbers II
Difficulty: Medium
Description: You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list. You may assume the two numbers do not contain any leading zero, except the number 0 itself.

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (l1 == NULL || l2 == NULL){return l1 == NULL ? l1 : l2;}

		vector<int> digits1;
		vector<int> digits2;

		//convert into vector for ease of use
		auto p1 = l1; auto p2 = l2;
		while(p1){digits1.push_back(p1->val); p1=p1->next;}
		while(p2){digits2.push_back(p2->val); p2 = p2->next;}

		reverse(digits1.begin(), digits1.end());
		reverse(digits2.begin(),digits2.end());

		//make both the same size with any extra entries being zero if smaller
		int size = digits1.size();
		if (digits1.size() != digits2.size()){size  = digits1.size() > digits2.size() ? digits1.size() : digits2.size(); digits1.resize(size+1); digits2.resize(size+1);}
		else {digits1.resize(size+1); digits2.resize(size+1);}
		vector<int> result(digits1.size());

		//now add as in elementary school, digit by digit, carrying over the ones
		int sum = 0;
		for (int i = 0; i< digits1.size(); ++i){
			sum = digits1.at(i) + digits2.at(i);
			if (sum>= 10) {sum -=10;  ++digits1.at(i+1);} //carry over the 1
			result.at(i) = sum;
		}
		reverse(result.begin(), result.end());
		if(result[0]==0) result.erase(result.begin());

		//convert to a list
		auto list_result = new ListNode(0);
		auto head = list_result;
		for (int i =0; i<result.size(); ++i){
			list_result->val = result[i];
			if(i!=result.size()-1){list_result->next = new ListNode(0); list_result = list_result->next;}
		}
		return head;
	}
};
*/

/*
Problem 897. Increasing Order Search Tree
Difficulty: Easy
Description: Given a tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, 
and every node has no left child and only 1 right child.

class Solution {
public:
	TreeNode* head;
	TreeNode* result = head = new TreeNode(0);


	void tree_vector (TreeNode* root){
		if (root->left != NULL){tree_vector(root->left);}
		if (root->right != NULL){result->val = root->val; result->right = new TreeNode(0); result= result->right; tree_vector(root->right); return;}
		result->val = root->val; result->right = new TreeNode(0); result = result->right;
		return ;
	}

	void delete_rightmost(TreeNode* root){
		TreeNode* curr = root;
		TreeNode* parent = root;

		while(curr->right != NULL){
			parent = curr;
			curr=curr->right;
		}
		parent->right  =NULL;

	}

	TreeNode* increasingBST(TreeNode* root) {//do by recursion
		tree_vector(root);

		//delete rightmost element (the added 0)
		delete_rightmost(head);

		return head;
	}

};
*/

/*
Problem 206. Reverse Linked List
Difficulty: Easy
Description: Reverse a singly linked list.

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;

		ListNode* curr = head->next;
		ListNode* prev = head;
		head->next = NULL;

		while(curr){
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}

		return prev;
	}
};
*/

/*
Problem 92. Reverse Linked List II
Difficulty: Medium
Description: Reverse a linked list from position m to n. Do it in one-pass.
Note: 1 <= m <= n <= length of list.

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		if (head == NULL) return head;

		ListNode* curr = head->next;
		ListNode* prev = head;
		head->next = NULL;

		while(curr){
			ListNode* temp = curr->next;
			curr->next = prev;
			prev = curr;
			curr = temp;
		}

		return prev;
	}

	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode* before_cut = new ListNode{0}; before_cut->next = head;
		ListNode* dummy = before_cut;
		ListNode* start = head;
		ListNode* end;
		ListNode* after_cut;

		//increment to cut position
		for (int i = 1; i< m; ++i){
			before_cut = before_cut->next;
			start = start->next;
		}

		//increment to end cut position
		end = start;
		for (int i = 1; i < n-m+1; ++i){
			end = end->next;
		}

		after_cut= end->next;
		end->next = NULL;

		before_cut->next = reverseList(start);
		start->next = after_cut;

		return dummy->next;





	}
};
*/

/*
Problem 83. Remove Duplicates from Sorted List
Difficulty: Easy
Description: Given a sorted linked list, delete all duplicates such that each element appear only once.

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;

		ListNode* curr = head;
		while (curr->next != NULL){
			if (curr->val == curr->next->val){
				auto p = curr->next;
				curr-> next = curr->next->next;
				delete p;
				continue;
			}
			curr = curr->next;
		}
		return head;
	}
};
*/

/*
Problem: 82. Remove Duplicates from Sorted List II
Difficulty: Easy
Description: Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) return head;
		ListNode* dummy = new ListNode{0};
		dummy->next = head;

		ListNode* prev = dummy;
		ListNode* curr = head;
		while (curr->next != NULL){
			if (curr->val == curr->next->val){
				int duplicate = curr->val;
				while (curr && curr->val == duplicate){
					auto temp = curr;
					curr= curr->next;
					delete temp;
				}

				prev->next = curr;
				if (curr == NULL) break;
				continue;
			}
			prev = curr;
			curr = curr->next;
		}


		//remember the case of 1,1,1,1
		return dummy->next;
	}
};
*/

/*
Problem 100. Same Tree
Difficulty: Easy
Description: Given two binary trees, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical and the nodes have the same value.

class Solution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		//idea: do by recursion
		if ((p == NULL || q == NULL)&& !(p == NULL && q == NULL)) return false; //check first if both nodes are checkable
		else if (!(p && q)) return true;
		else if (p->val != q->val) return false;
		else {
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		}

	}
};
*/

/*
Problem 704. Binary Search
Difficulty: Easy
Description: Given a sorted (in ascending order) integer array nums of n elements and a target value, write a function to search target in nums.
If target exists, then return its index, otherwise return -1.

class Solution {
public:
	inline int middle(int left, int right){
		return (right-left)/2+left;
	}

	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size()-1;

		while (left!=right && left < right){
			int mid = middle(left, right);
			if (nums[mid] == target) return mid;
			else if (target > nums[mid]){left = ++mid; continue;}
			else {right = --mid; continue;}
		}
		if (nums[left] == target) return left;
		return -1;
	}
};
*/

/*
Problem 141. Linked List Cycle
Difficulty: Easy
Description: Given a linked list, determine if it has a cycle in it.
To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) 
in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == NULL ||head->next == NULL) return false;

		ListNode* slow = head;
		ListNode* fast = head;
		while(fast!= NULL && fast->next != NULL){
			fast= fast->next;
			if (fast == slow) return true;
			else {slow = slow->next; fast = fast->next;}
		}
		return false;

	}
};

*/

int main() {

}