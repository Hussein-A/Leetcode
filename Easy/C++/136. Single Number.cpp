//Given a non-empty array of integers, every element appears twice except for one. Find that single one.
//Note: Your algorithm should have a linear runtime complexity.Could you implement it without using extra memory ?
//Speed: (28ms) Faster than 16.33% of C++ submissions; Mem: (11.6mb) less than 11.40% of C++ submissions

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		//use hash
		unordered_map<int, int> myhash;
		for (int i : nums) ++myhash[i];

		for (auto it : myhash) {
			if (it.second == 1) return it.first;
		}
		return 0;
	}
};
