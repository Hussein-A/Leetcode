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

int main() {

}