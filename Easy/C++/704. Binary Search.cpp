/*
Given a sorted (in ascending order) integer array nums of n elements and a target value, 
write a function to search target in nums. If target exists, then return its index, otherwise return -1.

Runtime: 56 ms, faster than 29.21% of C++ online submissions for Binary Search.
Memory Usage: 10.9 MB, less than 98.02% of C++ online submissions for Binary Search.
*/

class Solution {
public:
	inline int middle(int left, int right) {
		return (right - left) / 2 + left;
	}

	int search(vector<int>& nums, int target) {
		int left = 0;
		int right = nums.size() - 1;

		while (left != right && left < right) {
			int mid = middle(left, right);
			if (nums[mid] == target) return mid;
			else if (target > nums[mid]) { left = ++mid; continue; }
			else { right = --mid; continue; }
		}
		if (nums[left] == target) return left;
		return -1;
	}
};