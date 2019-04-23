// Given an array with n integers, your task is to check if it could become non-decreasing by modifying at most 1 element.
//We define an array is non - decreasing if array[i] <= array[i + 1] holds for every i(1 <= i < n).
//Speed: (36ms) Faster than 81.65% of C++ submissions; Mem: (10.4mb) less than 100% of C++ submissions

class Solution {
public:
	bool checkPossibility(vector<int>& nums) {
		int size = nums.size();
		int count = 0; //count the number of "fixable" pairs
		if (size <= 2) return true;
		if (nums[0] > nums[2] && nums[1] > nums[2]) {
			if (nums[1] > nums[0]) { nums[2] = nums[1]; ++count; }
			else return false;
		}
		else if (nums[0] > nums[1]) { nums[0] = nums[1]; ++count; }

		for (int i = 1; i < size - 1; ++i) {//start at 1 to make a triple
			if (count > 1) return false;//if ever we need to fix more than 1 pos return false
			if (nums[i] > nums[i + 1]) { //check if we have a problem index
				if (nums[i - 1] <= nums[i + 1]) { nums[i] = nums[i + 1]; ++count; }//if x<y, we can fix the index
				else if (nums[i - 1] > nums[i + 1]) {//other wise change the one infront of the problem index
					nums[i + 1] = nums[i];
					++count;
				}
			}
		}
		if (count > 1) return false;
		else return true;

	}
};