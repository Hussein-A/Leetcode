//Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//Speed: (16ms) Faster than 99.27% of C++ submissions; Mem: (9.3mb), less than 100% of C++ submissions
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) {
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
			}
		}
	}
};