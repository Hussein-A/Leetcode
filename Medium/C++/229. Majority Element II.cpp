/*
Given an integer array of size n, find all elements that appear more than ? n/3 ? times.
Note: The algorithm should run in linear time and in O(1) space.

Runtime: 16 ms, faster than 87.33% of C++ online submissions for Majority Element II.
Memory Usage: 10.7 MB, less than 50.89% of C++ online submissions for Majority Element II.
*/

class Solution {
public:
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> result;
		if (nums.size() == 0) return result;
		int min_bound = nums.size() / 3;

		//use hash
		unordered_map<int, int> mymap;

		for (const int& x : nums) { ++mymap[x]; }

		for (auto p : mymap) {
			if (p.second > min_bound) result.push_back(p.first);
		}
		sort(result.begin(), result.end());
		return result;
	}
};