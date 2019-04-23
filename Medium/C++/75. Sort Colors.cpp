/*
Given an array with n objects colored red, white or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white and blue.
Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
Note: You are not suppose to use the library's sort function for this problem

Runtime: 8 ms, faster than 39.36% of C++ online submissions for Sort Colors.
Memory Usage: 8.6 MB, less than 44.80% of C++ online submissions for Sort Colors.
*/

class Solution {
public:
	void sortColors(vector<int>& nums) {
		if (nums.size() == 0) return;
		//use similiar idea to quicksort pivots
		vector<int>::iterator first1 = nums.begin();
		vector<int>::iterator curr = nums.begin();

		while (curr != nums.end()) {
			if (*curr == 0) { swap(*curr, *first1); ++first1; }
			++curr;
		}
		//do again but this time imagine you have an array of only 1s and 2s
		curr = nums.begin();
		while (curr != nums.end() && *curr == 0) ++curr;
		vector<int>::iterator first2 = curr;

		while (curr != nums.end()) {
			if (*curr == 1) { swap(*curr, *first2); ++first2; }
			++curr;
		}


	}
};