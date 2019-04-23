/*
Given an array of integers, find if the array contains any duplicates.
Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.

Runtime: 44 ms, faster than 65.37% of C++ online submissions for Contains Duplicate.
Memory Usage: 17.6 MB, less than 9.44% of C++ online submissions for Contains Duplicate.
*/

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		unordered_map<int, int> mymap;
		for (const int& x : nums) ++mymap[x];

		for (auto it : mymap) if ((it).second > 1) return true;

		return false;
	}
};