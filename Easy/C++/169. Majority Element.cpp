/*
Given an array of size n, find the majority element. The majority element is the element that appears more than floor( n/2 ) times.
You may assume that the array is non-empty and the majority element always exist in the array.

Runtime: 24 ms, faster than 61.54% of C++ online submissions for Majority Element.
Memory Usage: 11.1 MB, less than 93.81% of C++ online submissions for Majority Element.
*/

class Solution {
public:
	int majorityElement(vector<int>& nums) {
		//hash instead, pick the bucket with the largest size.
		unordered_map<int, int> hash;

		for (int x : nums) { ++hash[x]; }

		//find max element
		//initialize
		pair<int, int> max_pos(nums[0], hash[nums[0]]);
		for (auto p : hash) {
			if (p.second > max_pos.second) max_pos = p;
		}
		return max_pos.first;
	}
};