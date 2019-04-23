//Given an array nums and a value val, remove all instances of that value in-place and return the new length.
//Do not allocate extra space for another array, you must do this by modifying the input array in - place with O(1) extra memory.
//The order of elements can be changed.It doesn't matter what you leave beyond the new length.
//Speed: (4ms) Faster than 100% of C++ submissions; Mem: (8.5mb) less than 100% of C++ submissions

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		int count = 0;
		int size = nums.size();
		auto pos = find(nums.begin(), nums.end(), val);
		if (pos == nums.end()) return size;

		while (pos != nums.end()) {
			++count;
			nums.erase(pos);
			pos = find(nums.begin(), nums.end(), val);
		}

		return size - count;
	}
};
