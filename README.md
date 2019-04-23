# Leetcode
Leetcode Link: https://leetcode.com/h42ahmad/  
A repository containing solved Leetcode problems. Problems are numbered and placed according to difficulty and then according to the language used to solve the problem. Their respective number is placed just before the title. General descriptions of the problem are contained as enclosed comments in the files themselves. Moreover statistics regarding the problem (ie. runtime, memory usage, percentile of them) are given when possible (sometimes leetcode does not keep such data after a period of time). Below you will find an example
of such a file.   

Note: code contained in these files (such as the code below) is not meant to be stand alone, they are meant to be used directly as the code accepted by leetcode. That is to verify such a solution simply go to the mentioned problem on leetcode and copy and paste the solution here into leetcode.

Example   
```c++
/*
Given a binary tree, return the level order traversal of its nodes' values. 
(ie, from left to right, level by level).

Runtime: 8 ms, faster than 100.00% of C++ online submissions for Binary Tree Level Order Traversal.   
Memory Usage: 13.9 MB, less than 48.30% of C++ online submissions for Binary Tree Level Order Traversal.
*/

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> order;
		queue<TreeNode*> curr_level;
		queue<TreeNode*> next_level;

		if (!root) return order;
		else next_level.push(root);


		while (!next_level.empty()) {
			swap(curr_level, next_level);
			vector<int> level{};

			while (!curr_level.empty()) {
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
```
## Definitions for Data Structures Used:
```c++
 //Definition for singly-linked list.  
 struct ListNode {  
 int val;  
 ListNode *next;  
 ListNode(int x) : val(x), next(NULL) {}  
 };

//Definition for a binary tree node.  
//(Do note that one variation of this is to include a TreeNode* next pointer pointing to the rightwards neighbour)  
struct TreeNode {  
int val;  
TreeNode *left;  
TreeNode *right;  
TreeNode(int x) : val(x), left(NULL), right(NULL) {}  
};  
```
 
## Statistics  
For the most up to date stats please see my leetcode account linked at the top of the page.  
Problems Solved (68) by Difficulty:  
Easy (42)   
Medium (24)   
Hard (2)
