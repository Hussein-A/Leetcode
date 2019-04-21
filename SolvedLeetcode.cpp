

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

/*
Problem 231. Power of Two
Difficulty: Easy
Description: Given an integer, write a function to determine if it is a power of two.
class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n == 0) return false;

		for (int exp = 0; pow(2,exp)<= n;++exp){
			if (pow(2,exp) == n) return true;
		}
		return false;
	}
};
*/

/*
Problem 116. Populating Next Right Pointers in Each Node
Difficulty: Medium
Decription: You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. 
The binary tree has the following definition: (See attached readme for node definition, added next pointer only difference)
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        else if (root->left == NULL) {root->next = NULL; return root;}
        root->next = NULL;
        
        queue<Node*> curr_level;
        queue<Node*> next_level;
        next_level.push(root->left); next_level.push(root->right);
        
        while(!next_level.empty()){
            curr_level.swap(next_level); //now jumping into next level
            Node* temp;
            
            while(!curr_level.empty()){
                temp = curr_level.front(); curr_level.pop();
                if (curr_level.empty()) temp->next = NULL;
                else temp->next = curr_level.front();
                //if left child exists then so must right (perfect binary tree)
                if (temp->left) {next_level.push(temp->left); next_level.push(temp->right);}
            }
        }
        return root;
    }
};

*/

/*
Problem 117. Populating Next Right Pointers in Each Node II
Difficulty: Medium
Description: Same as above except now the tree may not be perfect.
class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return root;
        root->next = NULL;
        
        queue<Node*> curr_level;
        queue<Node*> next_level;
        if (root->left) next_level.push(root->left); 
        if (root->right) next_level.push(root->right);
        
        while(!next_level.empty()){
            curr_level.swap(next_level); //now jumping into next level
            Node* temp;
            
            while(!curr_level.empty()){
                temp = curr_level.front(); curr_level.pop();
                if (curr_level.empty()) temp->next = NULL;
                else temp->next = curr_level.front();
                
                if (temp->left) next_level.push(temp->left);
                if (temp->right) next_level.push(temp->right);
            }
        }
        return root;
        
        
    }
};
*/

/*
Problem 148. Sort List
Difficulty: Medium
Description: Sort a linked list in O(n log n) time using constant space complexity.
class Solution {
public:
    ListNode* middle(ListNode* head){
        ListNode *slow = head, *fast = head -> next;
        while (fast && fast -> next) {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        return slow;
    }
    
    void merge(ListNode* head1, ListNode* head2){
        queue<int> first_half;
        queue<int> second_half;
        
        //fill queues
        ListNode* temp = head1; while(temp->next){first_half.push(temp->val); temp= temp->next;}
        first_half.push(temp->val);
        
        //connect first list to second (will return the combined sorted list later)
        temp->next = head2; 
        temp = head2; while(temp){second_half.push(temp->val); temp = temp->next;}
        
        temp = head1;
        while(!(first_half.empty() || second_half.empty())){
            if (first_half.front() <= second_half.front()){temp->val = first_half.front(); first_half.pop(); temp = temp->next;}
            else {temp->val = second_half.front(); second_half.pop(); temp = temp->next;}
        }
        while (!first_half.empty()){temp->val = first_half.front(); first_half.pop(); temp = temp->next;}
        while(!second_half.empty()){temp->val = second_half.front(); second_half.pop(); temp = temp->next;}
    }
    
    
    void mergesort(ListNode* head){
        if(head && head->next){
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
*/

/*
Problem 21. Merge Two Sorted Lists
Difficulty: Easy
Description: Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        else if (!l2) return l1;
        
        queue<int> first;
        queue<int> second;
        
        //copy contents into the queue first and second
        ListNode* temp = l1; while(temp->next){first.push(temp->val); temp = temp->next;}
        //connect the two lists
        first.push(temp->val); temp->next = l2;
        temp = l2; while (temp){second.push(temp->val); temp = temp->next;}
        temp = l1;
        while(!(first.empty() || second.empty())){
            if (first.front() <= second.front()) {temp->val = first.front(); first.pop();}
            else {temp->val = second.front(); second.pop();}
            temp = temp->next;
        }
        //copy over remnants
        while(!first.empty()){temp->val = first.front(); first.pop(); temp= temp->next;}
        while(!second.empty()){temp->val = second.front(); second.pop(); temp = temp->next;}
        return l1;
    }
};
*/

/*
Problem 21. Merge k Sorted Lists
Difficulty: Hard
Description: Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

class Solution {
public:
    ListNode* merge(ListNode* l1, ListNode* l2) {
    	//idea is to use merge two sorted lists technique
        if (!l1) return l2;
        else if (!l2) return l1;
        
        queue<int> first;
        queue<int> second;
        
        //copy contents into the queue first and second
        ListNode* temp = l1; while(temp->next){first.push(temp->val); temp = temp->next;}
        //connect the two lists
        first.push(temp->val); temp->next = l2;
        temp = l2; while (temp){second.push(temp->val); temp = temp->next;}
        temp = l1;
        while(!(first.empty() || second.empty())){
            if (first.front() <= second.front()) {temp->val = first.front(); first.pop();}
            else {temp->val = second.front(); second.pop();}
            temp = temp->next;
        }
        //copy over remnants
        while(!first.empty()){temp->val = first.front(); first.pop(); temp= temp->next;}
        while(!second.empty()){temp->val = second.front(); second.pop(); temp = temp->next;}
        return l1;
    }

    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int last_elem_pos = lists.size()-1;
        if (last_elem_pos ==-1) return NULL;
        else if (last_elem_pos == 0) return lists[0];
        
        //do a snowball of two list merging. Merging the first with second with the second being
        //the merged of two and repeat with list2 and list3
        for (int i = 0; i < last_elem_pos; ++i){
            lists[i+1] = merge(lists[i+1], lists[i]);
        }
        return lists[last_elem_pos];
    }
};
*/

/*
Problem 102. Binary Tree Level Order Traversal
Difficulty: Medium
Description: Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        queue<TreeNode*> curr_level;
        queue<TreeNode*> next_level;
        
        if (!root) return order;
        else next_level.push(root);

        
        while(!next_level.empty()){
            swap(curr_level, next_level);
            vector<int> level {};
            
            while(!curr_level.empty()){
                TreeNode*& node = curr_level.front();
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
                level.push_back(node->val); curr_level.pop();
            }
            order.push_back(level);
        }
        return order;
    }
};
*/

/*
Problem 103. Binary Tree Zigzag Level Order Traversal
Difficulty: Medium
Description: Given a binary tree, return the zigzag level order traversal of its nodes' values. 
(ie, from left to right, then right to left for the next level and alternate between).

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> order;
        queue<TreeNode*> curr_level;
        queue<TreeNode*> next_level;
        
        if (!root) return order;
        else next_level.push(root);

        bool zigorzag = true;
        while(!next_level.empty()){
            swap(curr_level, next_level);
            vector<int> level {};
            zigorzag = zigorzag ? false : true;
            
            while(!curr_level.empty()){
                TreeNode*& node = curr_level.front();
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
                level.push_back(node->val); curr_level.pop();
            }
            if (zigorzag) reverse(level.begin(), level.end());
            order.push_back(level);
        }
        return order;
    }
};

*/

/*
Problem. 147 Insertion Sort List
Difficulty: Medium
Description: Sort a linked list using insertion sort.

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
    
    ListNode* insertionSortList(ListNode* head) {
        if (!head) return head;
        ListNode* tail = new ListNode{head->val};
        
        ListNode* curr = head->next;
        ListNode* temp;
        ListNode* prev;
        while(curr){
            temp = tail;
            prev = temp;
            while (temp && curr->val < temp->val){
                prev = temp;
                temp = temp->next;
            }
            if (prev == temp){//case when element is inserted at the very beginning (ie. the end of the real sorted list)
                tail = new ListNode {curr->val};
                tail->next = prev;
            }
            else{
                prev->next = new ListNode{curr->val};
                prev->next->next = temp;
            }
            curr = curr->next;
        }
        
        //delete old list
        curr = head->next;
        prev = head;
        while (curr){
            delete prev;
            prev = curr;
            curr = curr->next;
        }
        delete prev;
        
        ListNode* sorted = reverseList(tail);
        return sorted;
        
    }
};

*/

/*
Problem. 263 Ugly Number
Difficulty: Easy
Description: Write a program to check whether a given number is an ugly number.
Ugly numbers are positive numbers whose prime factors only include 2, 3, 5

class Solution {
public:
    bool isUgly(int num) {
        if (num == 0) return false;
        else if (num == 1) return true;
        //find highest power of 2, 3 and 5 dividing num
        // divide the num by the product of those, if the remainder isnt 1 then is not an ugly number
        
        //get highest power of 2,3,5 remainder must be 1
        
        while (num%2 == 0){num /=2; }
        while(num%3 == 0){num /=3; }
        while (num%5 == 0) {num/= 5; }
        
        if (num != 1) return false;
        else return true;
    }
};
*/

/*
Problem 26. Remove Duplicates from Soprted Array
Difficulty: Easy
Description: Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        for (int i =1; i<nums.size(); ++i ){
            if (nums[i] == nums[i-1]){
                int& first_dup = i;
                int last_dup=i;
                int j = i+1;
                while(j< nums.size() && nums[j]== nums[first_dup]){++last_dup; ++j;}
                nums.erase(nums.begin()+first_dup, nums.begin()+last_dup+1);
            }
        }
        return nums.size();
        
    }
};
*/

/*
Problem 204. Count Primes
Difficulty: Easy
Description: Count the number of prime numbers less than a non-negative number, n.

class Solution {
public:
    	int countPrimes(int n) {
            if (n == 0 || n == 1) return 0;
	        //sieve of erostathene
            int size = n+1;
	        vector<bool> nums(size, true);

	        //0 and 1 are not primes
	        nums[0] =nums[1] = false;
            	nums[size-1] = false;

	        //remove all products of primes
	        int curr_prime = 2;
	        while (curr_prime <= n / 2) {
		        for (int multiple = 2; multiple <= n / curr_prime; ++multiple) { nums[multiple * curr_prime] = false; }
		        //find next prime
		        bool found_next = false;
		        int i = curr_prime + 1;
		        while (!found_next) { if (nums[i]) { curr_prime = i; found_next = true; } ++i; }
	        }

	        return count(nums.begin(), nums.end(), true);
        }
};
*/

/*
Problem 169. Majority Element
Difficulty: Easy
Description: Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.
You may assume that the array is non-empty and the majority element always exist in the array.

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //hash instead, pick the bucket with the largest size.
        unordered_map<int,int> hash;
        
        for (int x : nums){++hash[x];}
        
        //find max element
        //initialize
        pair<int, int> max_pos (nums[0], hash[nums[0]]);
        for (auto p : hash){
            if (p.second> max_pos.second) max_pos = p;
        }
        return max_pos.first;
    }
};

*/

/*
Problem 229. Majority Element II
Difficulty: Medium
Description: Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
Note: The algorithm should run in linear time and in O(1) space.

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.size()==0) return result;
        int min_bound = nums.size()/3;
        
        //use hash
        unordered_map<int, int> mymap;
        
        for (const int& x : nums){++mymap[x];}
        
        for (auto p : mymap){
            if (p.second > min_bound) result.push_back(p.first);
        }
        sort(result.begin(), result.end());
        return result;
    }
};
*/

/*
Problem 509. Fibonacci Number
Difficulty: Easy
Description: The Fibonacci numbers, commonly denoted F(n) form a sequence, 
called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. 

class Solution {
public:
    int fib(int N) {
        if (N == 0) return 0;
        if (N == 1 || N == 2) return 1;
        
        return fib(N-1) +fib(N-2);
    }
};
*/

/*
Problem 75. Sort Colours (Dutch National Flag)
Difficulty: Medium
Description: Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color 
are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note: You are not suppose to use the library's sort function for this problem.

class Solution {
public:
    void sortColors(vector<int>& nums) {
        if (nums.size() == 0) return;
        //use similiar idea to quicksort pivots
        vector<int>::iterator first1 = nums.begin();
        vector<int>::iterator curr = nums.begin();
        
        while (curr != nums.end()){
            if (*curr == 0){swap(*curr, *first1); ++first1;}
            ++curr;
        }
        //do again but this time imagine you have an array of only 1s and 2s
        curr = nums.begin();
        while (curr != nums.end() &&*curr == 0) ++curr;
        vector<int>::iterator first2 = curr;
        
        while (curr != nums.end()){
            if (*curr == 1){swap(*curr, *first2); ++first2;}
            ++curr;
        }
        
        
    }
};
*/

/*
Problem 74. Search a 2D Matrix
Difficulty: Medium
Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

   * Integers in each row are sorted from left to right.
   * The first integer of each row is greater than the last integer of the previous row.

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int&  row_size= matrix.size();
        if (row_size == 0 ) return false;
        const int&  col_size= matrix[0].size();
        if (col_size == 0) return false;
        
        
        int row_count = 0;
        vector<int> curr_row = matrix[row_count];
        while (row_count < row_size){
            curr_row = matrix[row_count];
            if (target <= curr_row[col_size-1]) return binary_search(curr_row.begin(), curr_row.end(), target);
            ++row_count;
        }
        return false;
    }
};
*/

/*
Problem 240. Search a 2D Matrix II
Difficulty: Medium
Description: Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

    * Integers in each row are sorted in ascending from left to right.
    * Integers in each column are sorted in ascending from top to bottom.
    

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        const int& row_size = matrix.size();
        if (row_size == 0) return false;
        const int& col_size = matrix[0].size();
        if (col_size == 0) return false;
        
        
        int row = row_size-1;
        int col = 0;
        int* curr_val= &matrix[row][col];
        while (row >=0 && col < col_size){
            curr_val = &matrix[row][col];
            if (*curr_val == target) return true;
            else if (target > *curr_val) ++col;
            else --row;
        }
        return false;
        
    }
};
*/

/*
Problem 217. Contains Duplicate
Difficulty: Easy
Description: Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> mymap;
        for (const int& x : nums) ++mymap[x];
        
        for (auto it : mymap) if ((it).second > 1) return true;
        
        return false;
    }
};
*/

/*
Problem 785. Is Graph Bipartite?
Difficulty: Medium
Description: Given an undirected graph, return true if and only if it is bipartite.
Recall that a graph is bipartite if we can split it's set of nodes into two independent subsets A and B such that every edge in the graph has one node in A and another node in B.
The graph is given in the following form: graph[i] is a list of indexes j for which the edge between nodes i and j exists.  
Each node is an integer between 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i] does not contain i, 
and it doesn't contain any element twice. 

class Solution {
public:
    
    bool flag = true;
    void bfs(vector<vector<int>>& graph, vector<int>& colors, vector<int>& state, const int start){
        //do bfs
        //initialize
        queue<int> myqueue; myqueue.push(start);
        colors[start]=1;
        state[start] = 1;
        
        int curr = start;
        while(!myqueue.empty()){
            curr = myqueue.front();
            
            for (const int& neighbor : graph[curr]){
                if (state[neighbor] == 0){
                    state[neighbor] = 1;
                    //set color
                    if (colors[curr] == 1) colors[neighbor] = 2;
                    else colors[neighbor] = 1;
                    myqueue.push(neighbor);
                }
                
                else{//already seen or processed, check color
                    if (colors[curr] == colors[neighbor]) flag = false;
                }
            }
            state[curr] = 2;
            myqueue.pop();
        }
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        if (graph.size() == 0) return true;
        vector<int> colors(graph.size(),0);//0 for uncolored, 1 for red, 2 for blue
        vector<int> state(graph.size(),0);//0 for undiscovered, 1 for discovered, 2 for processed
        auto it = find(state.begin(), state.end(), 0);

        while (it != state.end()){
            bfs(graph, colors, state, distance(state.begin(), it));
            if (flag == false) return false;
            it = find(state.begin(), state.end(), 0);
        }
        
        //check
        
        return flag;
    }
};
*/

/*
Problem 886. Possible Bipartition
Difficulty: Medium
Description: Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.

class Solution {
public:
    #define undiscovered 0
    #define discovered 1
    #define processed 2
        
    #define red 0
    #define blue 1
    
    bool isbipartite(vector<vector<int>>& graph, vector<int>& states, vector<int>& colors, const int& start){
        queue<int> myqueue; myqueue.push(start);
        states[start] = discovered;//0, 1 or 2
        colors[start]= red; // 0 or 1
        
        while (!myqueue.empty()){
            int curr = myqueue.front();
            for (int& neighbor : graph[curr]){
                if (states[neighbor] == undiscovered){
                    states[neighbor] = discovered;
                    colors[neighbor] = colors[curr] == red ? blue : red;
                    myqueue.push(neighbor);
                }
                else{
                    if (colors[neighbor] == colors[curr]) return false;
                } 
            }
            
            states[curr] = processed;
            myqueue.pop();
        }
        
        for (int i =0; i < states.size(); ++i) {if (states[i] == undiscovered) return isbipartite(graph, states, colors, i);}
        return true;
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        //convert to graph first
        vector<vector<int>> graph(N);
        for (const vector<int>& v : dislikes){
            graph[v[0]-1].push_back(v[1]-1); graph[v[1]-1].push_back(v[0]-1); //undirected graph, hence two copies of same edge in adj list
        }
        vector<int> states(N); vector<int> colors(N);
        return isbipartite(graph, states, colors, 0);
        
    }
};
*/

/*
Problem 104. Maximum Depth of Binary Tree
Difficulty: Easy
Description: Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        //do in level traversal        
        //initialize
        queue<TreeNode*> curr_level;
        queue<TreeNode*> next_level;
        
        if (!root) return 0;
        else next_level.push(root);
        int depth = 0;
        
        while (!next_level.empty()){
            swap(curr_level, next_level);
            cout << "1";
            ++depth;
            while (!curr_level.empty()){
                TreeNode*& node = curr_level.front();
                if (node->left) next_level.push(node->left);
                if (node->right) next_level.push(node->right);
                curr_level.pop();
            }
        }
        return depth;
    }
};
*/


/*
Problem 207. Course Schedule
Difficulty: Medium
Description: There are a total of n courses you have to take, labeled from 0 to n-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

class Solution {
public:
    #define undiscovered 0
    #define discovered 1
    #define processed 2
    
    bool flag = true;
    void dfs(vector<vector<int>>& graph, vector<int>& states, int start){
        states[start] = discovered;
        auto neighbor = graph[start].begin();
        
        while(neighbor != graph[start].end()){
            if (states[*neighbor] == discovered){
                flag = false;
                return;
            }
            dfs(graph, states, *neighbor);
            ++neighbor;
        }
        
        states[start] = processed;
        return;
    }
    
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        //do dfs, if backedge is found then impossible
        //construct graph
        vector<vector<int>> graph(numCourses); if (graph.size() == 0) return true;
        vector<int> states(numCourses);
        for (pair<int,int> edge : prerequisites){
            graph[edge.second].push_back(edge.first);
        }
        auto it = find(states.begin(), states.end(), undiscovered);
        while(it!= states.end()){
            dfs(graph, states, distance(states.begin(), it));
            it = find(states.begin(), states.end(), undiscovered);
        }
        return flag;
        
    }
};
*/

/*
Problem 98. Validate Binary Search Tree
Difficulty: Medium
Description: Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

    The left subtree of a node contains only nodes with keys less than the node's key.
    The right subtree of a node contains only nodes with keys greater than the node's key.
    Both the left and right subtrees must also be binary search trees.

class Solution {
public:
    vector<int> treesort;
    void BSTtraversal(TreeNode* root){
        if (!root->left && !root->right) {treesort.push_back(root->val); return;}
        
        if (root->left) BSTtraversal(root->left);
        treesort.push_back(root->val);
        if (root->right) BSTtraversal(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        //do inorder traversal to generate a sorted list if BST
        if (!root) return true;
        BSTtraversal(root);
        for (int x : treesort) cout << x << " ";
        cout << "\n";
        
        vector<int> temp = treesort;
        sort(temp.begin(), temp.end());
        
        for (int i = 0; i < temp.size(); ++i){
            if (temp[i] != treesort[i]) return false;
        }
        //check for duplicates
        for (int i = 0; i < temp.size()-1; ++i){
            if (temp[i] == temp[i+1]) return false;
        }
        return true;
    }
        
};

*/


/*
Problem 210. Course Schedule II
Difficulty: Medium
Description:There are a total of n courses you have to take, labeled from 0 to n-1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.

class Solution {
public:
    #define undiscovered 0
    #define discovered 1
    #define processed 2
    
    bool flag = true;
    vector<int> order;
    void dfs(vector<vector<int>>& graph, vector<int>& states,const int& start){
        states[start] = discovered;
        auto edge = graph[start].begin();
        
        while (edge != graph[start].end()){
            if (states[*edge] == discovered) {flag = false; return;}//must be a backedge, not a DAG return.
            if (states[*edge] == undiscovered){dfs(graph, states, *edge);}
            ++edge;
        }
        states[start] = processed;
        order.push_back(start);
    }
    
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        //implement a topological sort
        
        //make graph
        vector<vector<int>> graph(numCourses);
        vector<int> states(numCourses);
        for (auto p : prerequisites){graph[p.second].push_back(p.first);}
        
        //go through all connected components
        auto it = find(states.begin(), states.end(), 0);
        while (it != states.end()){
            dfs(graph, states, distance(states.begin(), it));
            //check in case dfs found a backedge
            if (flag == false) {order = {}; cout << "IMPOSSIBLE!\n"; return order;}
            it = find(states.begin(), states.end(), 0);
        }
        reverse(order.begin(), order.end());
        return order;
        
    }
};
*/

/*
Problem 69. Sqrt(x)
Difficulty: Easy
Description: Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.

class Solution {
public:
    int mySqrt(int n) {
        int low = 1, high = n / 2;//root will always be less than half as long as 4<=n
	    int mid;
	    while (low < high) {
		    mid = low + (high - low) / 2;
		    if (mid == n) return mid;
		    else if (mid < n/mid){low = mid + 1;}
		    else { high = mid - 1; }
	    }
	    if (low > n/low) {
		    return low - 1;
	    }
	    else if ((low + 1) <= n/(low + 1)) {
		    return low + 1;
	    }
        else return low;
    }
};
*/

/*
Problem 344. Reverse String
Difficulty: Easy
Description: Write a function that reverses a string. The input string is given as an array of characters char[].
Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.
You may assume all the characters consist of printable ascii characters.

class Solution {
public:
    void reverseString(vector<char>& s) {
        
        if (s.size()!=0){
            char temp1;
            int size = s.size()-1;
            int j;
            int i = s.size()-1;
            while (i>(s.size()-1)/2){
                j = size-i;
                temp1 = s[j];
                s[j]=s[i];
                s[i] =temp1;
                --i;
        }
        }
        
    }
};
*/
/*
Problem 541. Reverse String II
Difficulty: Easy
Description:
Given a string and an integer k, you need to reverse the first k characters for every 2k characters counting 
from the start of the string. If there are less than k characters left, reverse all of them. 
If there are less than 2k but greater than or equal to k characters, then reverse the first k characters and left the other as original. 

class Solution {
public:
    string reverseStr(string s, int k) {
        
        for (int i = 0; 2*k*i < s.size(); ++i){
            auto first = s.begin()+2*k*i;
            auto last = first+k > s.end() ? s.end() : first+k;
            reverse(first, last);
        }
        return s;
    }
};

*/

int main() {

}
