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

int main() {

}