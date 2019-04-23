//Given an array, rotate the array to the right by k steps, where k is non-negative.
//Speed: (32ms) Faster than 23.89% of C++ submissions; MEM: (9.6mb) less than 40.97% of C++ submissions

class Solution {
public:
	inline int mod(const int& a, const int& b) { return (a%b < 0) ? (b + a % b) : a % b; }
	void rotate(vector<int>& nums, int k) {
		int size = nums.size();
		vector<int> nums2(size);
		for (int i = 0; i < size; ++i) {
			nums2[i] = nums[mod(i - k, size)];
		}
		nums = nums2;
	}
};