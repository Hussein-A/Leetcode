/*
Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. 
You can only see the k numbers in the window. 
Each time the sliding window moves right by one position. Return the max sliding window.

Runtime: 176 ms, faster than 5.11% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 16.8 MB, less than 13.56% of C++ online submissions for Sliding Window Maximum.
*/

class Solution {
public:
	int get_lmax(const list<int>& l) const {
		int max = INT_MIN;
		for (const int& x : l) { if (x > max) max = x; }
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
		for (int i = 0; i < k; ++i) { *(p++) = nums[i]; if (nums[i] > max) max = nums[i]; }
		window_max.push_back(max);

		//slide window
		int i = k;
		while (i != nums_size) {
			window.erase(window.begin());
			window.push_back(nums[i]);
			//check new num
			if (nums[i] > max) { max = nums[i]; window_max.push_back(max); }
			else {
				max = get_lmax(window); window_max.push_back(max);
			}

			++i;
		}
		return window_max;


	}
};